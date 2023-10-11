#include <QDir>
#include <QTabWidget>
#include <QHelpContentWidget>
#include <QHelpIndexWidget>
#include <QHelpSearchQueryWidget>
#include <QDebug>
#include <QApplication>
#include <QDockWidget>

#include "helpmodel.h"

Jiratool::HelpManager::HelpManager(QObject *parent)
{
    qInfo() << "HelpManager created";
    m_window.reset(new HelpWindow);
    connect(this, &HelpManager::titleChanged, m_window.data(), &QMainWindow::setWindowTitle);
    connect(this, &HelpManager::widthChanged, m_window.data(), &QWidget::setFixedWidth);
    connect(this, &HelpManager::heightChanged, m_window.data(), &QWidget::setFixedHeight);
    connect(this, &HelpManager::bgHelpWindowColorChanged, this, [&](QString color) {
        m_window->setStyleSheet("background-color:" + color + ";");
    });
    connect(this, &HelpManager::bgHelpBrowserColorChanged, this, [&](QString color) {
        m_window->horizSplitter->setStyleSheet("QSplitter::handle{background: " + color + ";}");
    });
    connect(this, &HelpManager::txtColorChanged, this, [&](QString color) {
        m_window->helpEngine->contentWidget()->setStyleSheet("QHelpContentWidget::item{color:" + color + ";}");
        m_window->helpEngine->indexWidget()->setStyleSheet("QHelpIndexWidget::item{color:" + color + ";}");
        m_window->helpBrowser->setStyleSheet("QTextEdit{color:" + color + ";}");
        m_window->tWidget->setStyleSheet("QTabBar::tab {color:" + color + ";}");
    });
    connect(m_window.data(), &HelpWindow::closing, this, &HelpManager::closing);
    connect(this, &HelpManager::closing, this, &QObject::deleteLater);
}

Jiratool::HelpManager::~HelpManager()
{
    qInfo() << "HelpManager destroyed";
}

int Jiratool::HelpManager::width() const
{
    return m_width;
}

void Jiratool::HelpManager::setWidth(int w)
{
    m_width = w;
    emit widthChanged(m_width);
}

int Jiratool::HelpManager::height() const
{
    return m_height;
}

void Jiratool::HelpManager::setHeight(int h)
{
    m_height = h;
    emit heightChanged(m_height);
}

QString Jiratool::HelpManager::bgHelpWindowColor() const
{
    return m_bgHelpWindowColor;
}

void Jiratool::HelpManager::setBgHelpWindowColor(QString &color)
{
    m_bgHelpWindowColor = color;
    emit bgHelpWindowColorChanged(m_bgHelpWindowColor);
}

QString Jiratool::HelpManager::bgHelpBrowserColor() const
{
    return m_bgHelpBrowserColor;
}

void Jiratool::HelpManager::setBgHelpBrowserColor(QString &color)
{
    m_bgHelpBrowserColor = color;
    emit bgHelpBrowserColorChanged(m_bgHelpBrowserColor);
}

QString Jiratool::HelpManager::txtColor() const
{
    return m_txtColor;
}

void Jiratool::HelpManager::setTxtColor(QString &color)
{
    m_txtColor = color;
    emit txtColorChanged(m_txtColor);
}

QString Jiratool::HelpManager::title() const
{
    return m_title;
}

void Jiratool::HelpManager::setTitle(QString &title)
{
    m_title = title;
    emit titleChanged(m_title);
}

void Jiratool::HelpManager::show()
{
    m_window->show();
}

Jiratool::HelpWindow::HelpWindow()
{
    qInfo() << "HelpWindow created";

    // init helpEngine
    {
        helpEngine = new QHelpEngine(QDir::currentPath() + "/helpmodel/helpmodelviewer.qhc", this);
        helpEngine->setupData();
        QFont font;
        font.setPixelSize(16);
        helpEngine->contentWidget()->setFont(font);
    }

    helpBrowser = new HelpBrowser(helpEngine, this);
    tWidget = new QTabWidget(this);
    horizSplitter = new QSplitter(Qt::Horizontal, this);
    createHelpWindow();
}

Jiratool::HelpWindow::~HelpWindow()
{
    qInfo() << "HelpWindow destroyed";
}

void Jiratool::HelpWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit closing(event);
}

void Jiratool::HelpWindow::createHelpWindow()
{
    tWidget->setMaximumWidth(200);
    tWidget->addTab(helpEngine->contentWidget(), "Contents");
    tWidget->addTab(helpEngine->indexWidget(), "Index");

    helpBrowser->setSource(QUrl("qthelp://jiratool.qt.help/doc/index.html"));
    connect(helpEngine->contentWidget(), SIGNAL(linkActivated(QUrl)), helpBrowser, SLOT(setSource(QUrl)));
    connect(helpEngine->indexWidget(), SIGNAL(linkActivated(QUrl, QString)), helpBrowser, SLOT(setSource(QUrl)));

    horizSplitter->insertWidget(0, tWidget);
    horizSplitter->insertWidget(1, helpBrowser);

    horizSplitter->setMinimumWidth(800);
    horizSplitter->setMinimumHeight(600);
}

Jiratool::HelpBrowser::HelpBrowser(QHelpEngine *helpEngine, QWidget *parent)
    : m_helpEngine(helpEngine)
    , QTextBrowser(parent)
{
    qInfo() << "HelpBrowser created";
}

Jiratool::HelpBrowser::~HelpBrowser()
{
    qInfo() << "HelpBrowser destroyed";
}

QVariant Jiratool::HelpBrowser::loadResource(int type, const QUrl &url)
{
    QTextBrowser::loadResource(type, url);

    if (url.scheme() == "qthelp") {
        return QVariant(m_helpEngine->fileData(url));
    }

    return QTextBrowser::loadResource(type, url);
}
