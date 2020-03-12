/**
 * @file ThreadGuard.h
 * @brief Header file of the ThreadGuard class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef THREADGUARD_H
#define THREADGUARD_H
/** utility class that uses standard Resource Acquisition
 * Initialization (RAII) to perform a safe thread join action
 */
namespace std
{
class thread;
}
namespace utils
{
class ThreadGuard
{

public:
    /** Constructor
     *
     *  @param atmthread a reference to the ATM thread
     */
    explicit ThreadGuard(std::thread& ar_atmThread);

    /** Destructor
     */
    ~ThreadGuard();
    // copy constructor and copy assignment operator are
    // marked =delete to ensure that they are not automatically
    // provided by compiler
    ThreadGuard(ThreadGuard const& )=delete;
    ThreadGuard& operator=(ThreadGuard const& )=delete;


protected:


private:
    std::thread &mr_atmThread;

};
}

#endif // THREADGUARD_H

