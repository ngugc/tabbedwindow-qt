#include <QApplication>
#include "tabbedwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabbedWindow w;
    w.resize(400, 400);
    w.show();

    QWidget red, green, blue;

    red.setStyleSheet("background-color: red");
    blue.setStyleSheet("background-color: blue");
    green.setStyleSheet("background-color: green");

    w.addView(&red, QString("Red View"));
    w.addView(&blue, QString("Blue view"));
    w.addView(&green, QString("Green view"));
    
    return a.exec();
}
