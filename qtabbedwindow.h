#ifndef QTABBEDWINDOW_H
#define QTABBEDWINDOW_H

#include <QMainWindow>


class QTabbedWindowPrivate;


class QTabbedWindow : public QMainWindow
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QTabbedWindow)

public:
    explicit QTabbedWindow(QWidget *parent = 0);
    ~QTabbedWindow();

private:
    //QTabbedWindowPrivate* d_ptr;
};

#endif // QTABBEDWINDOW_H
