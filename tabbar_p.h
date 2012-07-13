#ifndef VIEWBAR_P_H
#define VIEWBAR_P_H

#include <QtGui>

class TabBarPrivate : public QTabBar
{
    Q_OBJECT
public:
    TabBarPrivate(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

protected:
    void createNewWindow(int index);
    void tabRemoved(int index);
    
signals:
    
public slots:

private:
    QPoint dragStartPos;
    int dragging;
};

#endif // VIEWBAR_P_H
