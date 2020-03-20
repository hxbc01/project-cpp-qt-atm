/**
 * @file SimReceiptPrinter.h
 * @brief Header file of the SimReceiptPrinter class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMRECEIPTPRINTER_H
#define SIMRECEIPTPRINTER_H
#include <QPushButton>
/** Simulate the receipt printer
 */
namespace simulation
{
class SimReceiptPrinter : public QPushButton
{

public:
    /** Default Constructor
     */
    explicit SimReceiptPrinter(const QString &text);
    /** Destructor
     */
    ~SimReceiptPrinter();

protected:


private:

};
}

#endif // SIMRECEIPTPRINTER_H

