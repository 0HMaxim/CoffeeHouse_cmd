#pragma once
#include "Header.h"

class Client {
	int id;
	double spentMoney;
public:

	friend class Coffee;
	friend class CoffeeHouse;
	friend class Additive;


	Client() :id(0), spentMoney(0) {}
	void setId(int id) {
		this->id = id;
	}
	void setSpentMoney(double spentMoney) {
		this->spentMoney = spentMoney;
	}

	int money(vector<Client> &clients) {
		int sum = 0;
		for (int i = 0; i < clients.size(); i++)
			sum += clients[i].getSpentMoney();
		return sum;
	}

	void howMuchClientSpent(vector<Client> &clients) {
		char buf[50];
		char choice;
		int id;
		cout << "Enter your id : ";
		cin.getline(buf, 50);
		id = atoi(buf);
		while (id == 0) {
			if (id == 0)
				try {
				if (id == 0)
					throw 2;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong format id\n\n";
			}
			cout << "Enter your id : ";
			cin.getline(buf, 50);
			id = atoi(buf);
		}
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == id) {
				cout << "You spent " << clients[i].getSpentMoney() << " here\n\n";
				break;
			}
			else if (i == clients.size() - 1) {
				cout << "\n\n========== Wrong id ==========\n\n";
				printf("1. - Try again\n");
				printf("2. - Exit\n");
				choice = _getch();
				while (choice != '1' && choice != '2') {
					try {
						if (choice != '1' && choice != '2')
							throw 1;
					}
					catch (int error) {
						system("cls");
						cout << "Wrong choice\n\n";
					}
					printf("1. - Try again\n");
					printf("2. - Exit\n");
					choice = _getch();
				}
				if (choice == '1') {
					system("cls");
					cout << "Enter your id : ";
					cin.ignore();
					cin.getline(buf, 50);
					id = atoi(buf);
					while (id == 0) {
						try {
							if (id == 0)
								throw 2;
						}
						catch (int error) {
							system("cls");
							cout << "Wrong id\n\n";
						}
						cout << "Enter your id : ";
						cin.getline(buf, 50);
						id = atoi(buf);
					}
					i = -1;
				}
				if (choice == '2') {
					system("cls");
					cout << "See you latter!\n\n";
					break;
				}
			}
		}
	}

	void addClient(vector<Client> &clients) {
		clients.resize(clients.size() + 1);
		clients[clients.size() - 1].setId(clients[clients.size() - 2].getId() + 1);
		cout << "Your new id client is : " << clients[clients.size() - 1].getId() << endl;
	}


	void printClients(vector<Client> &clients) {
		for (int i = 0; i < clients.size(); i++)
			cout << "ID client : " << clients[i].getId() << " Count Spent Money : " << clients[i].getSpentMoney() << endl;
		cout << endl;
	}


	void saveClients(vector<Client> &clients) {
		ofstream listOfClients("Clients.txt");
		for (int i = 0; i < clients.size(); i++) {
			listOfClients << clients[i].getId() << " " << clients[i].getSpentMoney();
			if (i < clients.size() - 1)
				listOfClients << endl;
		}
		listOfClients.close();
	}

	int countClients() {
		int countClients = 1;
		string buf;
		ifstream listOfClients("Clients.txt");
		if (listOfClients.is_open()) {
			countClients = 0;
			while (!listOfClients.eof()) {
				getline(listOfClients, buf);
				countClients++;
			}
			listOfClients.close();
		}
		else {
			listOfClients.close();
			ofstream listOfClients("Clients.txt");
			listOfClients << 0 << " " << 0;
			listOfClients.close();
		}
		return countClients;
	}

	void readClients(vector<Client> &clients) {
		double spentMoney;
		int id;
		string buf;
		int i = 0;
		ifstream listOfClients("Clients.txt");
		if (listOfClients.is_open()) {
			while (!listOfClients.eof()) {
				listOfClients >> id;
				clients[i].setId(id);
				listOfClients >> spentMoney;
				clients[i++].setSpentMoney(spentMoney);
				getline(listOfClients, buf, '\n');
			}
		}
		clients[0].setId(0);
		clients[0].setSpentMoney(0);
		listOfClients.close();
	}
	int getId() { return id; }
	double getSpentMoney() { return spentMoney; }
};