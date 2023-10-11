#pragma once

#include <QObject>
#include <QQuickWindow>
#include <QMainWindow>
#include <QHelpEngine>
#include <QAbstractItemModel>
#include <QScopedPointer>
#include <QTextBrowser>
#include <QSplitter>
#include "config.h"

JIRATOOL_NS_BEGIN

class HelpWindow;
class HelpBrowser;

class HelpManager: public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged FINAL)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged FINAL)
    Q_PROPERTY(QString bgHelpWindowColor READ bgHelpWindowColor WRITE setBgHelpWindowColor NOTIFY bgHelpWindowColorChanged FINAL)
    Q_PROPERTY(QString bgHelpBrowserColor READ bgHelpBrowserColor WRITE setBgHelpBrowserColor NOTIFY bgHelpBrowserColorChanged FINAL)
    Q_PROPERTY(QString txtColor READ txtColor WRITE setTxtColor NOTIFY txtColorChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
public:
    explicit HelpManager(QObject *parent = nullptr);
    ~HelpManager();
    Q_INVOKABLE void show();

    int width() const;
    void setWidth(int w);
    Q_SIGNAL void widthChanged(int widht);

    int height() const;
    void setHeight(int h);
    Q_SIGNAL void heightChanged(int height);

    QString bgHelpWindowColor() const;
    void setBgHelpWindowColor(QString &color);
    Q_SIGNAL void bgHelpWindowColorChanged(QString color);

    QString bgHelpBrowserColor() const;
    void setBgHelpBrowserColor(QString &color);
    Q_SIGNAL void bgHelpBrowserColorChanged(QString color);

    QString txtColor() const;
    void setTxtColor(QString &color);
    Q_SIGNAL void txtColorChanged(QString color);

    QString title() const;
    void setTitle(QString &title);
    Q_SIGNAL void titleChanged(QString title);

    Q_SIGNAL void closing(QCloseEvent *e);
private:
    int m_width;
    int m_height;

    QString m_bgHelpWindowColor;
    QString m_bgHelpBrowserColor;
    QString m_txtColor;
    QString m_title;
    QScopedPointer<HelpWindow> m_window;

};

class HelpWindow: public QMainWindow {
    Q_OBJECT
    QML_ELEMENT
public:
    HelpWindow();
    ~HelpWindow();

    Q_SIGNAL void closing(QCloseEvent *even);
protected:
    void closeEvent(QCloseEvent *event) override;
private:
    void createHelpWindow();

    QTabWidget* tWidget{nullptr};
    QHelpEngine* helpEngine{nullptr};
    HelpBrowser* helpBrowser{nullptr};
    QSplitter* horizSplitter{nullptr};

    friend class HelpManager;
};

class HelpBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    HelpBrowser(QHelpEngine *helpEngine, QWidget *parent = 0);
    ~HelpBrowser();
    virtual QVariant loadResource(int type, const QUrl &url) override;
private:
    QHelpEngine *m_helpEngine;
};

JIRATOOL_NS_END
