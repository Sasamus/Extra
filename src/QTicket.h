#ifndef QTICKET_H
#define QTICKET_H

#include <atomic>
#include <iostream>


class QTicket {
public:

	QTicket() { }
	~QTicket() { }

	virtual void  service(int) = 0;

};


class QTicketDomestic : public QTicket {
public:

	QTicketDomestic()
		:myTicketNumber(++ticketNumber)
	{ }

	virtual void  service(int deskNumber) {

		std::cout << "Domestic service ticket " << myTicketNumber << " at desk " << deskNumber << std::endl;

	}

private:
	static std::atomic<int> ticketNumber;
	int myTicketNumber;
};



class QTicketAbroad : public QTicket {
public:

	QTicketAbroad()
		:myTicketNumber(++ticketNumber)
	{ }

	virtual void  service(int deskNumber) {

		std::cout << "Abroad service ticket " << myTicketNumber << " at desk " << deskNumber << std::endl;

	}

private:
	static std::atomic<int> ticketNumber;
	int myTicketNumber;
};


#endif