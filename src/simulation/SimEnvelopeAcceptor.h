/**
 * @file SimEnvelopeAcceptor.h
 * @brief Header file of the SimEnvelopeAcceptor class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMENVELOPEACCEPTOR_H
#define SIMENVELOPEACCEPTOR_H
#include <QPushButton>
/** Simulate the envelope acceptor
 */
namespace simulation
{
class SimEnvelopeAcceptor : public QPushButton
{

public:
    /** Default Constructor
     */
    explicit SimEnvelopeAcceptor(const QString &text);

    /** Destructor
     */
    ~SimEnvelopeAcceptor();

protected:


private:


};
}

#endif // SIMENVELOPEACCEPTOR_H

