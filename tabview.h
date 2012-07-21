#ifndef TABVIEW_H
#define TABVIEW_H

#include <QTabWidget>


class TabView : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabView(QWidget *parent = 0);
    int tabAt(const QPoint &pos);
    
signals:
    
public slots:
    
};

#endif // TABVIEW_H
