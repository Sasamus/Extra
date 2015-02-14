#ifndef SERVICEDESK_H
#define SERVICEDESK_H

#include "QTicket.h"
#include "BlockingTicketDeque.h"

class ServiceDesk {
public:
	ServiceDesk(BlockingTicketDeque *queue, int  deskNum)
		:theQueue(queue), deskNumber(deskNum) {}


	void service() {

		while (true) {

			theQueue->popFrontAndService(deskNumber);

		}

	}

private:
	BlockingTicketDeque *theQueue;
	int deskNumber;

};



#endif
