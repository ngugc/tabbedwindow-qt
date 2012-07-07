#include "qtabbedwindow.h"
#include "qtabbedwindow_p.h"


QTabbedWindow::QTabbedWindow(QWidget *parent) :
    QMainWindow(parent)
{
    d_func()->init(parent);
}

QTabbedWindow::~QTabbedWindow()
{
}
