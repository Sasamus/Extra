/*
	Bounded blocking deque

*/

#ifndef BLOCKINGTICKETDEQUE_H
#define BLOCKINGTICKETDEQUE_H

#include <deque>
#include <mutex>
#include <condition_variable>
#include "QTicket.h"

using std::deque;

class BlockingTicketDeque {
public:
	BlockingTicketDeque(int maxSize);

	void pushBack(QTicket *qt);
	/* Push qt at the end. If full, block until there is space. */

	void popFrontAndService(int deskNumber);
	/* Pop the front element off the front of theDeque and invoke the service
	function on it. If empty, block until not empty.*/

private:
	deque<QTicket*> theDeque;
	int maxSz;

	//Mutex to lock the critical sections
	std::mutex mMutex;

	//Condition variable's to lock the critical sections
	std::condition_variable mPutConditionVariable;
	std::condition_variable mTakeConditionVariable;
};



#endif
