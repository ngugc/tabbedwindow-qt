#ifndef TABMOVEEVENT_H
#define TABMOVEEVENT_H

#include <QObject>
#include <QPoint>


class TabMoveEvent
{
public:
    /* Create a new instance of a tab move event passing the tab index under
       the mouse cursor and the position of the mouse as the offset between the
       current position and the top left corner of the enclosing window
    */
    TabMoveEvent(QPoint& pos, int index);

    const int index() { return m_index; }
    const QPoint pos() { return m_pos; }

private:
    int m_index;
    QPoint m_pos;
};

#endif // TABMOVEEVENT_H
