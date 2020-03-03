
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include "Money.h"
using namespace std;
using namespace banking;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text = "test";
    Money money1(100,12),money2(12,1);
    //money1.add(money2);
    cout << money1.toString().toStdString() <<endl;
    return 0;
}
