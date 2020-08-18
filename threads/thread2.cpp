/*
thread pool
threads accessing the same piece of information
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <mutex>

// returns a random value whenever called
int getRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

std::string getTime()
{
    //current time in milliseconds
    auto nowTime = std::chrono::system_clock::now();
    // to put threads to sleep
    std::time_t sleepTime =
        std::chrono::system_clock::to_time_t(nowTime);

    return std::ctime(&sleepTime);
}

double acctBalance = 100;

// protect shared data from being accessed at the same time
// keep threads from accessing acctBalance at exactly the same time
std::mutex acctLock;

// function for accessing acctBalance
void getMoney(int id, double withdrawal)
{
    // restrict access to the entire scope of this function
    // once one of the other threads comes here and tries to execute code
    std::lock_guard<std::mutex> lock(acctLock);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << id <<
            " tries to withdrawal $" <<
            withdrawal << " on " <<
            getTime() << std::endl;

    if((acctBalance - withdrawal) >= 0)
    {
        acctBalance -= withdrawal;
        std::cout << "New account balance is $" <<
                acctBalance << std::endl << std::endl;
    } else
    {
        std::cout << "Not enough money in account!\n" <<
                "Current balance is $" <<
                acctBalance << std::endl;
    }

}

int main()
{
    // create thread pools
    std::thread threads[10];
    for(int i = 0; i <10; i++)
    {
        // all threads will access function getMoney
        // i is their id
        // they will all try to take out 15$
        threads[i] = std::thread(getMoney, i, 15);
    }

    // join threads to main
    for(int i = 0; i <10; i++)
    {
        threads[i].join();
    }

    return 0;
}
