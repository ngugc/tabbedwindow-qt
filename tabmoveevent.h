#ifndef TABMOVEEVENT_H
#define TABMOVEEVENT_H

#include <QObject>
#include <QPoint>


class TabBarPrivate;


class TabMoveEvent
{
public:
    TabMoveEvent(TabBarPrivate *tabbar, const QPoint& pos);

    const int index() { return m_index; }
    const QPoint offset() { return m_offset; }

private:
    int m_index;
    QPoint m_offset;
};

#endif // TABMOVEEVENT_H
