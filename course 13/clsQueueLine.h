#pragma once
#include <iostream>
#include "../clsDate.h"
#include <queue>
#include <stack>
#include <string>
using namespace std;

class clsQueueLine
{
private:
	string _Prefix = "";
	short _AverageServeTime = 0;
	short _TotalTickets = 0;

	class clsTicket
	{
	private:
		string _Prefix = "";
		int _Number= 0;
		int _WaitingClients = 0;
		int _AverageServeTime = 0;
		string _TicketTime = "";

	public:

		clsTicket(string Prefix, int Number, int WaitingClients, int AverageServeTime)
		{
			_Prefix = Prefix;
			_Number = Number;
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
			_TicketTime = clsDate::GetSystemDateTimeString();
		}

		string Prefix()
		{
			return _Prefix;
		}

		int Number()
		{
			return _Number;
		}

		string FullName()
		{
			return _Prefix + to_string(_Number);
		}

		int WaitingClients()
		{
			return _WaitingClients;
		}

		int ExpectedServeTime()
		{
			return _WaitingClients * _AverageServeTime;
		}

		void Print()
		{
			cout << "\t\t\t\t    --Tickets--\n";
			cout << "\t\t\t-----------------------------------\n";
			cout << "\t\t\t\t\t" << FullName() << "\n\n";
			cout << "\t\t\t\t" << _TicketTime << endl;
			cout << "\t\t\t\tWaiting Client = " << _WaitingClients << "\n";
			cout << "\t\t\t\tServe Time in " << "\n";
			cout << "\t\t\t\t" << ExpectedServeTime() << " Minutes.\n";
			cout << "\t\t\t-----------------------------------\n\n\n";
		}

	};
	
	queue <clsTicket> QueueLine;

public:

	clsQueueLine(string Prefix,int AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;

		clsTicket NewTicket(_Prefix, _TotalTickets, WaitingClient(), _AverageServeTime);

		QueueLine.push(NewTicket);
	}

	int WaitingClient()
	{
		return QueueLine.size();
	}

	int ServedClients()
	{
		return _TotalTickets - WaitingClient();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
		{
			return false;
		}

		QueueLine.pop();
		return true;
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
		{
			return "No Client Left.";
		}

		return QueueLine.front().FullName();
	}

	void PrintInfo()
	{
		cout << "\t\t\t-----------------------------------\n";
		cout << "\t\t\t\t    Queue Info\n";
		cout << "\t\t\t-----------------------------------\n";
		cout << "\t\t\t    Prefix    = " << _Prefix << endl;
		cout << "\t\t\t    Total Tickets    = " << _TotalTickets << endl;
		cout << "\t\t\t    Served Clients   = " << ServedClients() << endl;
		cout << "\t\t\t    Waiting Clients = " << WaitingClient() << endl;
		cout << "\t\t\t-----------------------------------\n\n";
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
		{
			cout << "\t\t\tNo Tickets" << endl;
			return;
		}

		queue <clsTicket> TempQueueLine = QueueLine;

		cout << "\n\t\tTickets: ";

		while (!TempQueueLine.empty())
		{
			cout << TempQueueLine.front().FullName() << " <-- ";
			TempQueueLine.pop();
		}

		cout << endl << endl;
	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
		{
			cout << "\t\t\tNo Tickets" << endl;
			return;
		}

		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		cout << "\t\tTickets: ";

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			cout << TempStackLine.top().FullName() << " --> ";
			TempStackLine.pop();
		}

		cout << endl << endl;
	}

	void PrintAllTickets()
	{
		queue <clsTicket> TempQueueLine = QueueLine;

		if (TempQueueLine.empty())
		{
			cout << "\t\t\t --No Tickets--" << endl;
		}
		else
		{
			while (!TempQueueLine.empty())
			{
				TempQueueLine.front().Print();
				TempQueueLine.pop();
			}
		}
	}
};