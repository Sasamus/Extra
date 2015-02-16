#include <iostream>
#include <thread>
#include <random>

#include "TicketButtonPanel.h"
#include "BlockingTicketDeque.h"

int main() {

	BlockingTicketDeque *abroadQueue = new BlockingTicketDeque(10);
	BlockingTicketDeque *domesticQueue = new BlockingTicketDeque(10);

	TicketButtonPanel *ticketButtonPanel1 = new TicketButtonPanel(domesticQueue, abroadQueue);
	TicketButtonPanel *ticketButtonPanel2 = new TicketButtonPanel(domesticQueue, abroadQueue);


	std::thread ticketButtonPanelThread1(&TicketButtonPanel::runPushSimulationLoop, ticketButtonPanel1);
	std::thread ticketButtonPanelThread2(&TicketButtonPanel::runPushSimulationLoop, ticketButtonPanel2);

	return 0;
}
