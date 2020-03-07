/**
 * @file ReceiptPrinter.h
 * @brief Header file of the ReceiptPrinter class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef RECEIPTPRINTER_H
#define RECEIPTPRINTER_H
/** Manager for the ATM's receipt printer.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
class Receipt;
namespace atm
{
namespace physical
{
class ReceiptPrinter
{

public:
    /** Default Constructor
     */
    ReceiptPrinter();
    /** Destructor
     */
    ~ReceiptPrinter();
    /** Print a receipt
       *
       *  @param receipt object containing the information to be printed
       */
    void printReceipt(Receipt *ap_receipt);

protected:


private:


};
}
}

#endif // RECEIPTPRINTER_H

