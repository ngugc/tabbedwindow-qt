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

#ifndef TABBEDWINDOW_H
#define TABBEDWINDOW_H

#include <QMainWindow>


class TabbedWindowPrivate;


/*
 * Subclass of QMainWindow, contains a tab bar to manage a per-window list of
 * tabbed views and allows to add, insert or remove a view.
 *
 * Views can be standard QWidget instances or even instances of QMainWindow
 * with menu bar and tool bars as well.
 *
 * Thes features will be displayed automatically when the view's tab will be
 * activated and hidden when it'll be deactivated.
 */
class TabbedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabbedWindow(QWidget *parent = 0);
    ~TabbedWindow();

    // Add a new view
    int addView(QWidget* view, const QString &title);

    // Insert a view at the given global position
    // Returns -1 if the insert view operations fails otherwise returns the
    // view's index
    int insertView(const QPoint &pos, QWidget *page, const QString &text);

    // Remove the view at the given index
    void removeView(int index);

    // Set the view at the given index as the current view
    void setCurrentView(int index);

    // Returns the current view
    QWidget* currentView();

private:
    TabbedWindowPrivate* d_ptr;
};

#endif // TABBEDWINDOW_H
