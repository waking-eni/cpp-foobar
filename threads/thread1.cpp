/* A thread is a block of code that executes */

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

// returns a random value whenever called
int getRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void executeThread(int id)
{
    //current time in milliseconds
    auto nowTime = std::chrono::system_clock::now();
    // to put threads to sleep
    std::time_t sleepTime =
        std::chrono::system_clock::to_time_t(nowTime);
    // convert to our current timezone
    tm myLocalTime = *localtime(&sleepTime);

    // print it out
    std::cout << "Thread " << id <<
            " Sleep Time: " <<
            std::ctime(&sleepTime)<< std::endl;

    std::cout << "Month: " <<
            myLocalTime.tm_mon << std::endl;
    std::cout << "Day: " <<
            myLocalTime.tm_mday << std::endl;
    std::cout << "Year: " <<
            myLocalTime.tm_year + 1900 << std::endl;
    std::cout << "Hours: " <<
            myLocalTime.tm_hour << std::endl;
    std::cout << "Minutes: " <<
            myLocalTime.tm_min << std::endl;
    std::cout << "Seconds: " <<
            myLocalTime.tm_sec << std::endl << std::endl;

    // put thread to sleep
    std::this_thread::sleep_for(std::chrono::seconds(getRandom(3)));
    // get current time
    nowTime = std::chrono::system_clock::now();
    sleepTime =
        std::chrono::system_clock::to_time_t(nowTime);

    std::cout << "Thread " << id <<
            " Awake Time: " <<
            std::ctime(&sleepTime)<< std::endl;
}

int main()
{
    std::thread th1(executeThread, 1);
    // joint the thread to main thread
    // so that main waits for this thread to stop executing
    // before continuing execution of code in main
    th1.join();

    std::thread th2(executeThread, 2);
    th2.join();

    return 0;
}
