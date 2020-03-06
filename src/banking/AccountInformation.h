/**
 * @file AccountInformation.h
 * @brief Header file of the AccountInformation class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef ACCOUNTINFORMATION_H
#define ACCOUNTINFORMATION_H
#include <QStringList>
/** The static members of this class incorporate information about accounts
 *  offered by the bank.  Actual communication with the bank uses account type
 *  numbers - e.g. 0 represents the first type of account listed.
 */
namespace banking
{
class AccountInformation
{

public:
    /** Default Constructor
     */
    AccountInformation();
    /** Destructor
     */
    ~AccountInformation();
    /** Names for accounts to be offered in menu to customer
     */
    const QStringList ACCOUNT_NAMES = {"Checking", "Savings", "Money Market"};
    /** Abbreviations for account names to be printed on receipts.
      */
    const QStringList ACCOUNT_ABBREVIATIONS = {"CHKG", "SVGS", "MMKT"};

protected:


private:

};
}

#endif // ACCOUNTINFORMATION_H


