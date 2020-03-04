
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include "Money.h"
#include "Card.h"
using namespace std;
using namespace banking;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text = "test";
    Money money1(100,12),money2(12,1);
    Card card1(100);
    cout << card1.getNumber() <<endl;
    return 0;
}
