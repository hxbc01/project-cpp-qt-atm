#include <QDebug>
#include <thread>
#include "ThreadGuard.h"

utils::ThreadGuard::ThreadGuard(std::thread& ar_atmThread):mr_atmThread(ar_atmThread)
{

}

utils::ThreadGuard::~ThreadGuard()
{
    if (mr_atmThread.joinable())
    {
        mr_atmThread.join();
    }

}




