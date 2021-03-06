//
// Created by michal on 19.12.18.
//

#ifndef P2P_STOPPABLE_H
#define P2P_STOPPABLE_H

#include <thread>
#include <future>
#include <iostream>


class Stoppable {
    std::promise<void> exitSignal;
    std::future<void> futureObj;
public:
    Stoppable() : futureObj(exitSignal.get_future())
    {

    }
    Stoppable(Stoppable && obj) : exitSignal(std::move(obj.exitSignal)), futureObj(std::move(obj.futureObj))
    {
        std::cout << "Move Constructor is called" << std::endl;
    }
    Stoppable & operator=(Stoppable && obj)
    {
        std::cout << "Move Assignment is called" << std::endl;
        exitSignal = std::move(obj.exitSignal);
        futureObj = std::move(obj.futureObj);
        return *this;
    }

    // Task need to provide defination  for this function
    // It will be called by thread function
    virtual void run() = 0;


    // Thread function to be executed by thread
    void operator()()
    {
        run();
    }

    //Checks if thread is requested to stop
    bool stopRequested()
    {
        // checks if value in future object is available
        if (futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
            return false;
        return true;
    }
    // Request the thread to stop by setting value in promise object
    void stop()
    {
        exitSignal.set_value();
    }
};


#endif //P2P_STOPPABLE_H
