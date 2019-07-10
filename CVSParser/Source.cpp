//∆’Õ®±®±Ì

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

struct Ticket
{
	std::string id, hash, A, T, phone, entered = "0";
};

std::string decto36(int A) {
	std::string tendigit;
	switch (A / 10)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		tendigit = std::to_string(A / 10);
		break;
	case 10:
		tendigit = 'A';
		break;
	case 11:
		tendigit = 'B';
		break;
	case 12:
		tendigit = 'C';
		break;
	case 13:
		tendigit = 'D';
		break;
	case 14:
		tendigit = 'E';
		break;
	case 15:
		tendigit = 'F';
		break;
	case 16:
		tendigit = 'G';
		break;
	case 17:
		tendigit = 'H';
		break;
	case 18:
		tendigit = 'I';
		break;
	case 19:
		tendigit = 'J';
		break;
	case 20:
		tendigit = 'K';
		break;
	case 21:
		tendigit = 'L';
		break;
	case 22:
		tendigit = 'M';
		break;
	case 23:
		tendigit = 'N';
		break;
	case 24:
		tendigit = 'O';
		break;
	case 25:
		tendigit = 'P';
		break;
	case 26:
		tendigit = 'Q';
		break;
	case 27:
		tendigit = 'R';
		break;
	case 28:
		tendigit = 'S';
		break;
	case 29:
		tendigit = 'T';
		break;
	case 30:
		tendigit = 'U';
		break;
	case 31:
		tendigit = 'V';
		break;
	case 32:
		tendigit = 'W';
		break;
	case 33:
		tendigit = 'X';
		break;
	case 34:
		tendigit = 'Y';
		break;
	case 35:
		tendigit = 'Z';
		break;
	}

	return tendigit + std::to_string(A % 10);
}

const std::string code = "SDTSR19BJCN15JULA";

int main() {
	int A = 1;
	std::vector<Ticket> TicketList;
	std::vector<Ticket>::iterator it = TicketList.begin();
	std::ifstream file("expt.csv");
	std::ofstream csv("list.csv", std::ios::trunc);
	std::string line, cell;

	//skip the header
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (std::getline(file, line, '\n')) {
		std::istringstream iss(line);
		Ticket temp;
		for (int i = 0; std::getline(iss, cell, ','); ++i) {
			switch (i)
			{
			case 0:
				temp.id = cell.substr(1);
				break;
			case 14:
				temp.T = cell;
				break;
			case 50:
				temp.phone = cell;
				break;
			}
		}
		TicketList.push_back(temp);
	}

	for (std::vector<Ticket>::reverse_iterator it = TicketList.rbegin(); it != TicketList.rend(); ++it) {
		std::ostringstream oss;
		oss << std::setfill('0') << std::setw(2) << decto36(A);
		(*it).A = oss.str();

		std::string temp;
		temp += code + (*it).A + "T" + (*it).T;
		(*it).hash = temp;
		++A;
	}

	for (std::vector<Ticket>::iterator it = TicketList.begin(); it != TicketList.end(); ++it) {
		std::cout << "----------\n" <<
			"Ticket ID: " << (*it).id << "\n" <<
			"Ticket A: " << (*it).A << "\n" <<
			"Ticket T: " << (*it).T << "\n" <<
			"Ticket Phone: " << (*it).phone << "\n" <<
			"Ticket Hash: " << (*it).hash << "\n" <<
			"----------\n" << std::endl;
	}

	csv << "A,T,Phone,Entered,Hash\n";
	for (std::vector<Ticket>::reverse_iterator it = TicketList.rbegin(); it != TicketList.rend(); ++it) {
		csv << (*it).A << "," << (*it).T << "," << (*it).phone 
			<< "," << (*it).entered << "," << (*it).hash << "," << "\n";
	}

	file.close();
	csv.close();

	return 0;
}