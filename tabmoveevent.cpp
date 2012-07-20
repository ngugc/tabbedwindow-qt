#include "tabmoveevent.h"


TabMoveEvent::TabMoveEvent(QPoint& pos, int index)
{
    m_index = index;
    m_pos = pos;
}
