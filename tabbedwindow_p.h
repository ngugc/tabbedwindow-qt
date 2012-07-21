#ifndef TABBEDWINDOWPRIVATE_H
#define TABBEDWINDOWPRIVATE_H

#include "tabbedwindow.h"


class TabView;


class TabbedWindowPrivate : public QObject
{
    Q_OBJECT

public:
    TabbedWindowPrivate(TabbedWindow* q_ptr);

    int addView(QWidget* view, const QString &title);
    int insertView(const QPoint &pos, QWidget *page, const QString &text);
    void removeView(int index);
    void setCurrentView(int index);
    QWidget* currentView();

private:
    TabbedWindow *q_ptr;
    TabView* tabs;

private slots:
    void onCurrentChanged(int);
};

#endif // TABBEDWINDOWPRIVATE_H
