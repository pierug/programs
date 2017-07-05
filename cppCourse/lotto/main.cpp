#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "lotto.h"
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    Lotto lotto;
    vector<int> result =lotto.getLuckSix();
    qDebug()<<result.size();
    for(int x:result){
        qDebug()<<x;
    }*/

    return a.exec();
}
