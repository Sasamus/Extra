
#include "QTicket.h"

std::atomic<int> QTicketDomestic::ticketNumber { 0 };

std::atomic<int> QTicketAbroad::ticketNumber { 0 };