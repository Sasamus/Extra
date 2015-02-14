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
	void popFrontAndService(int deskNumber);

private:
	deque<QTicket*> theDeque;
	const int maxSz;

};


#endif
