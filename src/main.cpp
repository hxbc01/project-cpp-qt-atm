#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <ATM.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Create an ATM Object
    atm::ATM *p_myATM = new atm::ATM(42, "Gordon College", "First National Bank of Podunk",
                          "nullptr" /* We're not really talking to a bank! */);

    return 0;
}
