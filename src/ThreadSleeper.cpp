#include <chrono>
#include <thread>
#include "ThreadSleeper.h"


ThreadSleeper::ThreadSleeper(int max)
:maxSleep(max), gen(rd()), dist(1,maxSleep) {

}

void ThreadSleeper::randomSleep() {

	std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
}

void ThreadSleeper::threadSleep(int ms) {

	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

 

