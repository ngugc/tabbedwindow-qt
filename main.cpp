#include <QtGui/QApplication>
#include "qtabbedwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTabbedWindow w;
    w.show();
    
    return a.exec();
}
