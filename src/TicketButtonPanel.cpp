#include "TicketButtonPanel.h"
#include "BlockingTicketDeque.h"
#include <iostream>


TicketButtonPanel::TicketButtonPanel(BlockingTicketDeque *domesticQ, BlockingTicketDeque *abroadQ)
:sleeper(MAX_INTERVAL), theDomesticQ(domesticQ), theAbroadQ(abroadQ)
{ }



void TicketButtonPanel::runPushSimulationLoop() {
	QTicket *qt = nullptr;
	while (true) {

		int randNum = dist(gen);


		if (randNum & 1) {  // if randNum is an odd number, make a ticket for domestic service

			qt = new QTicketDomestic;
			theDomesticQ->pushBack(qt);

		}
		else {  // randNum is an even number, make a ticket for abroad service

			qt = new QTicketAbroad;
			theAbroadQ->pushBack(qt);

		}
		sleeper.randomSleep(); // sleep some millisecs
	}

}