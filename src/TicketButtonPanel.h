/*
	Class TicketButtonPanel simulates customers pushing either button for domestic service or abroad service randomly.
	Each button push generates a corresponding QTicket which is inserted in the queue.

*/


#ifndef TICKETBUTTONPANEL_H
#define TICKETBUTTONPANEL_H

#include <random>
#include "QTicket.h"
#include "ThreadSleeper.h"

class BlockingTicketDeque;


const int MAX_INTERVAL = 100; // max milliseconds between two button pushings

class TicketButtonPanel {

  public:

	TicketButtonPanel(BlockingTicketDeque *domesticQ, BlockingTicketDeque *abroadQ);
	// Initialize with the two queues

	void runPushSimulationLoop();  // Makes random calls to the two push functions

private:
	void pushForDomesticService();  // Simulate a button push
	void pushForAbroadService();	// Simulate a button push

	ThreadSleeper sleeper;
	BlockingTicketDeque *theDomesticQ, *theAbroadQ;



	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> dist;

};

#endif
