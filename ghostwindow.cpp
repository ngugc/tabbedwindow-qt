/*
 * Copyright (c) 2012, Daniele Esposti <expo@expobrain.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of the contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ghostwindow.h"
#include "tabbar.h"

#include <QApplication>


GhostWindow::GhostWindow(TabBar *tabbar, const QPoint& pos) :
    QWidget()
{
    QWidget *wnd = tabbar->window();
    QPalette palette;

#if QT_VERSION >= 0x050000
    palette.setBrush(this->backgroundRole(), QBrush(wnd->grab()));
#else
    palette.setBrush(this->backgroundRole(), QBrush(QPixmap::grabWidget(wnd)));
#endif

    this->setPalette(palette);
    this->setGeometry(wnd->geometry());
    this->setWindowOpacity(0.5);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_offset = tabbar->mapToGlobal(pos) - wnd->pos();
    m_index = tabbar->tabAt(pos);
    m_originPos = tabbar->mapToGlobal(pos);
}


void GhostWindow::moveWithOffset(const QPoint& pos)
{
    QWidget::move(pos - m_offset);
}


bool GhostWindow::dragStarted(const QPoint &pos)
{
    return (pos - m_originPos).manhattanLength()
            >= QApplication::startDragDistance();
}
