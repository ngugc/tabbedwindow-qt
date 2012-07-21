#ifndef TABMOVEEVENT_H
#define TABMOVEEVENT_H

#include <QPoint>
#include <QPixmap>


class TabBarPrivate;


class TabMoveEvent
{
public:
    TabMoveEvent(TabBarPrivate *tabbar, const QPoint& pos);

    const int index() { return m_index; }
    const QPoint offset() { return m_offset; }
    const QPixmap screenshot() { return m_screenshot; }

private:
    int m_index;
    QPoint m_offset;
    QPixmap m_screenshot;
};

#endif // TABMOVEEVENT_H
