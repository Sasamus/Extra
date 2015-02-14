#ifndef THREADSLEEPER_H
#define THREADSLEEPER_H
#include <random>

using std::uniform_int_distribution;
using std::default_random_engine;

class ThreadSleeper {
public:
	ThreadSleeper(int max);
	void randomSleep();  // Blocks this thread randomly for 1..max millisecs.
	void threadSleep(int ms); // Blocks this thread for ms millisecs
private:
	int maxSleep;
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> dist;
};

#endif