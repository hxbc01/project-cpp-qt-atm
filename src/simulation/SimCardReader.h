/**
 * @file SimCardReader.h
 * @brief Header file of the SimCardReader class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMCARDREADER_H
#define SIMCARDREADER_H
#include <QPushButton>
/** Simulate the card reader
 */
namespace simulation
{
class Simulation;
}
namespace simulation
{
class SimCardReader : public QPushButton
{

public:
    /** Constructor
     *
     *  @param simulation the Simulation object
     */
    explicit SimCardReader(const QString &text, Simulation *ap_theSimulation);
    /** Destructor
     */
    ~SimCardReader();

protected:


private:

};
}

#endif // SIMCARDREADER_H

