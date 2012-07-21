#include "ghostwindow.h"
#include "tabbar_p.h"


GhostWindow::GhostWindow(TabBarPrivate *tabbar, const QPoint& pos) :
    QWidget()
{
    QWidget *wnd = tabbar->window();
    QPalette palette;

    palette.setBrush(this->backgroundRole(),
                     QBrush(QPixmap::grabWidget(wnd)));

    this->setPalette(palette);
    this->setGeometry(wnd->geometry());
    this->setWindowOpacity(0.5);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_offset = tabbar->mapToGlobal(pos) - wnd->pos();
    m_index = tabbar->tabAt(pos);
}


void GhostWindow::moveWithOffset(const QPoint& pos)
{
    QWidget::move(pos - m_offset);
}
