#include <iostream>
#include <thread>
#include <random>
#include <vector>

#include "TicketButtonPanel.h"
#include "ServiceDesk.h"
#include "BlockingTicketDeque.h"

int main() {

	// Create BlockingTicketDeques objects
	BlockingTicketDeque *abroadQueue = new BlockingTicketDeque(10);
	BlockingTicketDeque *domesticQueue = new BlockingTicketDeque(10);

	// Create the ButtonPanels
	TicketButtonPanel *ticketButtonPanel1 = new TicketButtonPanel(domesticQueue, abroadQueue);
	TicketButtonPanel *ticketButtonPanel2 = new TicketButtonPanel(domesticQueue, abroadQueue);

	// Create threads and run the TicketButtonPanels runPushSimulationLoop functions in them
	std::thread ticketButtonPanelThread1(&TicketButtonPanel::runPushSimulationLoop, ticketButtonPanel1);
	std::thread ticketButtonPanelThread2(&TicketButtonPanel::runPushSimulationLoop, ticketButtonPanel2);

	// Create ServiceDesks objects
	ServiceDesk *serviceDesk1 = new ServiceDesk(domesticQueue, 1);
	ServiceDesk *serviceDesk2 = new ServiceDesk(domesticQueue, 2);
	ServiceDesk *serviceDesk3 = new ServiceDesk(abroadQueue, 3);
	ServiceDesk *serviceDesk4 = new ServiceDesk(abroadQueue, 4);


	// Create threads and run the ServiceDesks service function in them
	std::thread serviceDeskThread1(&ServiceDesk::service, serviceDesk1);
	std::thread serviceDeskThread2(&ServiceDesk::service, serviceDesk2);
	std::thread serviceDeskThread3(&ServiceDesk::service, serviceDesk3);
	std::thread serviceDeskThread4(&ServiceDesk::service, serviceDesk4);

	// Join the threads
	ticketButtonPanelThread1.join();
	ticketButtonPanelThread2.join();
	serviceDeskThread1.join();
	serviceDeskThread2.join();
	serviceDeskThread3.join();
	serviceDeskThread4.join();

	return 0;
}
