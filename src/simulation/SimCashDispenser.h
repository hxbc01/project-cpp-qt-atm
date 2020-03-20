/**
 * @file SimCashDispenser.h
 * @brief Header file of the SimCashDispenser class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMCASHDISPENSER_H
#define SIMCASHDISPENSER_H
#include <QPushButton>
/** Simulate the cash dispenser
 */
namespace simulation
{
class SimCashDispenser : public QPushButton
{

public:
    /** Default Constructor
     */
    explicit SimCashDispenser(const QString &text);

    /** Destructor
     */
    ~SimCashDispenser();

protected:


private:


};
}

#endif // SIMCASHDISPENSER_H

