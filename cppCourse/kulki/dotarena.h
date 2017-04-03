#ifndef DOTARENA_H
#define DOTARENA_H

#include <QWidget>
#include "dot.h"
#include <iostream>
#include <vector>

using namespace std;
class DotArena : public QWidget
{
    Q_OBJECT

private:
    vector<Dot> dotList;
public:
    explicit DotArena(QWidget *parent = 0);

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *zdarzenie);
    void paintEvent(QPaintEvent *zdarzenie);
};

#endif // DOTARENA_H
