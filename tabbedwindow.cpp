#include "tabbedwindow_p.h"
#include "tabview.h"


TabbedWindow::TabbedWindow(QWidget *parent) :
    QMainWindow(parent),
    d_ptr(new TabbedWindowPrivate(this))
{
}


TabbedWindow::~TabbedWindow()
{
    delete d_ptr;
}


void TabbedWindow::setCurrentView(int index)
{
    d_ptr->setCurrentView(index);
}


int TabbedWindow::insertTab(const QPoint &pos, QWidget *page,
                            const QString &text)
{
    return d_ptr->insertView(pos, page, text);
}


int TabbedWindow::addView(QWidget *view, const QString &title)
{
    return d_ptr->addView(view, title);
}


void TabbedWindow::removeView(int index)
{
    d_ptr->removeView(index);
}


TabbedWindowPrivate::TabbedWindowPrivate(TabbedWindow* q_ptr)
{
    // Create tab widget
    tabs = new TabView();
    tabs->setTabsClosable(true);
    tabs->setDocumentMode(true);

    // Set up main window
    this->q_ptr = q_ptr;
    this->q_ptr->setCentralWidget(tabs);
}


void TabbedWindowPrivate::setCurrentView(int index)
{
    tabs->setCurrentIndex(index);
}


int TabbedWindowPrivate::insertView(const QPoint &pos, QWidget *page,
                                    const QString &text)
{
    // Get tab's index at the given global postition
    int index = tabs->tabAt(tabs->mapFromGlobal(pos));

    // Insert new tab
    return tabs->insertTab(index, page, text);
}


int TabbedWindowPrivate::addView(QWidget *view, const QString &title)
{
    return tabs->addTab(view, title);
}


void TabbedWindowPrivate::removeView(int index)
{
    tabs->removeTab(index);
}

