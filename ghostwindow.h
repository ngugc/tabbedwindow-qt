#ifndef GHOSTWINDOW_H
#define GHOSTWINDOW_H

#include <QWidget>


class TabBarPrivate;


class GhostWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GhostWindow(TabBarPrivate *tabbar, const QPoint& pos);

    const QPoint offset() { return m_offset; }
    const int index() { return m_index; }
    void moveWithOffset(const QPoint&);

private:
    QPoint m_offset;
    int m_index;
};

#endif // GHOSTWINDOW_H
