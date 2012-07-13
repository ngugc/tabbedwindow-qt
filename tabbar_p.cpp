#include "QtGui"
#include "tabbar_p.h"
#include "tabbedwindow.h"
#include "tabview_p.h"


TabBarPrivate::TabBarPrivate(QWidget *parent) :
    QTabBar(parent),
    dragging(-1)
{
}

void TabBarPrivate::mousePressEvent(QMouseEvent *event)
{
    // If left button is pressed save current mouse position for
    // possible draggin action triggered in the future
    if (event->button() == Qt::LeftButton) {
        qDebug() << "left button pressed at" << event->pos();
        dragStartPos = event->pos();
    }

    // Call superclass
    QTabBar::mousePressEvent(event);
}


void TabBarPrivate::mouseReleaseEvent(QMouseEvent *event) {
    // Call superclass if a button different than the left one was released
    // and return
    if (event->button() != Qt::LeftButton) {
        QTabBar::mouseReleaseEvent(event);
        return;
    }

    // If left button was released and a dragging action is involved
    // stop dragging
    if (dragging > -1) {
        // Stop dragging

        TabBarPrivate *w = dynamic_cast<TabBarPrivate*>(
                    QApplication::widgetAt(mapToGlobal(event->pos())));

        qDebug() << "stop dragging tab" << "on widget" << w;

        // Chose action by the widget under the mouse's coordinates
        if (w == NULL) {
            createNewWindow(dragging);
        }

        // Reset flag
        dragging = -1;
    }
}


void TabBarPrivate::tabRemoved(int index)
{
    if (count() == 0) {
        window()->close();
    }
}


void TabBarPrivate::createNewWindow(int index)
{
    // Retrieve references
    TabViewPrivate *view = static_cast<TabViewPrivate*>(parent());

    // Create the new window
    TabbedWindow *wnd = new TabbedWindow();

    // Move widget to the new window
    QWidget *tab = view->widget(index);
    QString text = view->tabText(index);

    view->removeTab(index);
    wnd->addView(tab, text);

    // Show the new window
    wnd->show();
}


void TabBarPrivate::mouseMoveEvent(QMouseEvent *event)
{
    // No left button
    if (!(event->buttons() & Qt::LeftButton)) {
        qDebug() << "no left button";
        return;
    }

    // We are already dragging
    if (dragging > -1) {
        return;
    }

    // No far enough
    if ((event->pos() - dragStartPos).manhattanLength()
            < QApplication::startDragDistance()) {
        qDebug() << "no far enough"
                 << ((event->pos() - dragStartPos).manhattanLength())
                 << QApplication::startDragDistance();
        return;
    }

    // Start dragging
    qDebug() << "start dragging tab" << tabAt(event->pos());
    dragging = tabAt(event->pos());
}
