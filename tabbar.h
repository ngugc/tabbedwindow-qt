#ifndef VIEWBAR_H
#define VIEWBAR_H

#include <QTabBar>


class GhostWindow;


class TabbedWindow;


class TabBar : public QTabBar
{
    Q_OBJECT

public:
    TabBar(QWidget *parent = 0);
    ~TabBar();

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

protected:
    void createNewWindow(GhostWindow*);
    void moveToWindow(TabbedWindow*, const QPoint&, GhostWindow*);
    void tabRemoved(int index);
    
signals:
    
public slots:

private:
    GhostWindow *m_ghost;
};

#endif // VIEWBAR_H
