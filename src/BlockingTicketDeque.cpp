// Implementation of class BlockingTicketDequeue
// Author: Albin Engström

#include "BlockingTicketDeque.h"


BlockingTicketDeque::BlockingTicketDeque(int maxSize)
:maxSz(maxSize){

}

void BlockingTicketDeque::pushBack(QTicket *qt){

	// Create an unique lock with mMutex
	std::unique_lock<std::mutex> lock = std::unique_lock<std::mutex>(mMutex);

	// While theDeque is full
	while (theDeque.size() == maxSz)
	{
		//Wait mPutConditionVariable with lock
		mPutConditionVariable.wait(lock);
	}

	// Add element to the end of theDeque
	theDeque.push_back(qt);

	// Unlock lock
	lock.unlock();

	// Notify one thread waiting with mTakeConditionVariable
	mTakeConditionVariable.notify_one();

}

void BlockingTicketDeque::popFrontAndService(int deskNumber){

}
