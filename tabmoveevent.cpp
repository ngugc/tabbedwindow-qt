#include "tabmoveevent.h"
#include "tabbar_p.h"


TabMoveEvent::TabMoveEvent(TabBarPrivate *tabbar, const QPoint& pos)
{
    m_index = tabbar->tabAt(pos);
    m_offset = tabbar->mapToGlobal(pos) - tabbar->window()->pos();
}
