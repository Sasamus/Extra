/*
	Bounded blocking deque

*/

#ifndef BLOCKINGTICKETDEQUE_H
#define BLOCKINGTICKETDEQUE_H

#include <deque>
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
};



#endif
