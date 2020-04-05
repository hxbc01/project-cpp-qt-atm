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
#include <QString>
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
    Q_OBJECT

private slots:
    /**
     * Card Reader button clicked
     */
    void pushCardReaderButton();

public:
    /** Constructor
     *
     *  @param simulation the Simulation object
     */
    explicit SimCardReader(const Simulation *ap_simulation);
    /** Destructor
     */
    ~SimCardReader();

protected:


private:
    /** simulation object
     */
    const Simulation *mp_simulation=nullptr;



};
}

#endif // SIMCARDREADER_H

