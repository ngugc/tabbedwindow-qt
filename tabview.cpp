#include "tabview.h"
#include "tabbar.h"


TabView::TabView(QWidget *parent) :
    QTabWidget(parent)
{
    setTabBar(new TabBar);
}


int TabView::tabAt(const QPoint &pos)
{
    return tabBar()->tabAt(pos);
}
