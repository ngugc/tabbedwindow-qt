#ifndef QTABBEDWINDOWPRIVATE_H
#define QTABBEDWINDOWPRIVATE_H

#include "qtabbedwindow.h"


class QTabbedWindowPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(QTabbedWindow)

public:
    void init(QWidget* parent);

private:
    QTabbedWindow *q_ptr;
};

#endif // QTABBEDWINDOWPRIVATE_H
