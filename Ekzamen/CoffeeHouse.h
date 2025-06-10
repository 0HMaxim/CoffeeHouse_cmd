#pragma once
#include "Header.h"

class CoffeeHouse {
public:

	friend class Additive;
	friend class Coffee;
	friend class Client;


	void menuForBarista() {
		printf("1. - Output all coffee\n");
		printf("2. - Output all additive\n");
		printf("3. - Output all clients\n");
		printf("4. - Output the amount of all revenue for the entire time\n");
		printf("5. - Add new coffee\n");
		printf("6. - Add new additive\n");
		printf("7. - Save all changes\n");
		printf("8. - Exit\n");
	}

	void menuForClient() {
		printf("1. - How much client spent\n");
		printf("2. - Order coffee\n");
		printf("3. - Exit\n");
	}

	void menuForClients(vector<Additive> &additive, vector<Coffee> &coffeee, vector<Client> &clients) {
		Additive addit;
		Coffee coff;
		Client cli;
		char choice;
		char choiceId[50];
		int id;
		int numberClient;
		string coffee;
		char choiceAdditive;
		int orderPrice = 0;
		string allAdditive;
		string buf;
		cout << "Have you been here already? \n";
		printf("1. - Nope\n");
		printf("2. - Yes\n");
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
			cout << "Have you been here already? \n";
			printf("1. - Nope\n");
			printf("2. - Yes\n");
			choice = _getch();
		}
		if (choice == '1') {
			cli.addClient(clients);
			numberClient = clients.size() - 1;
		}
		if (choice == '2') {
			cout << "Enter your ID :";
			cin.getline(choiceId, 50);
			id = atoi(choiceId);
			while (id == 0) {
				try {
					if (id == 0)
						throw 2;
				}
				catch (int error) {
					system("cls");
					cout << "Wrong format id\n\n";
				}
				cout << "Enter your ID :";
				cin.getline(choiceId, 50);
				id = atoi(choiceId);
			}
			for (int i = 0; i < clients.size(); i++) {
				if (clients[i].getId() == id) {
					cout << "yes, such id is present\n";
					numberClient = i;
					break;
				}
				if (i == clients.size() - 1) {
					system("cls");
					cout << "========== Wrong id ==========\n";
					printf("1. - Try again\n");
					printf("2. - Create new id\n");
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
						printf("2. - Create new id\n");
						choice = _getch();
					}
					if (choice == '1') {
						cout << "Enter your ID :";
						cin.getline(choiceId, 50);
						id = atoi(choiceId);
						while (id == 0) {
							try {
								if (id == 0)
									throw 2;
							}
							catch (int error) {
								system("cls");
								cout << "Wrong format id\n\n";
							}
							cout << "Enter your ID :";
							cin.getline(choiceId, 50);
							id = atoi(choiceId);
						}
						i = -1;
					}
					if (choice == '2') {
						cli.addClient(clients);
						numberClient = clients.size() - 1;
						break;
					}
				}
			}
		}
		printf("1. - Output all coffee\n");
		printf("2. - Exit\n");
		choice = _getch();
		system("cls");
		while (choice != '1' && choice != '2') {
			try {
				if (choice != '1' && choice != '2')
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong choice\n\n";
			}
			printf("1. - Output all coffee\n");
			printf("2. - Exit\n");
			choice = _getch();
		}
		switch (choice) {
		case '1': {
			coff.printCoffee(coffeee);
			cout << "Enter Name Coffee : ";
			getline(cin, coffee);
			for (int i = 0; i < coffeee.size(); i++) {
				if (coffeee[i].getName() == coffee) {
					orderPrice += coffeee[i].getCostPortion();
					cout << "Order Price = " << orderPrice << endl;
					cout << "Maybe are you want some kind of additive?\n";
					printf("1. - Yes\n");
					printf("2. - Nope\n");
					choiceAdditive = _getch();
					while (choiceAdditive != '1' && choiceAdditive != '2') {
						try {
							if (choiceAdditive != '1' && choiceAdditive != '2')
								throw 1;
						}
						catch (int error) {
							system("cls");
							cout << "Wrong choice\n\n";
						}
						cout << "Maybe are you want some kind of additive?\n";
						printf("1. - Yes\n");
						printf("2. - Nope\n");
						choiceAdditive = _getch();
					}
					break;
				}
				if (i == coffeee.size() - 1) {
					cout << "\n\n========== Wrong name coffee ==========\n\n";
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
						i = -1;
						coff.printCoffee(coffeee);
						cout << "Enter Name Coffee : ";
						getline(cin, coffee);
					}
					if (choice == '2') {
						cout << "\n\n========== Okey, good bye ==========\n\n";
						break;
					}
				}
			}
			if (choice != '2') {
				if (choiceAdditive == '1') {
					system("cls");
					cout << "========== Select additive ==========\n\n";
					addit.printAdditive(additive);
					cout << "\n0. - I have changed my mind, i will be without additive\n";
					cout << "Enter Name Additive : ";
					getline(cin, buf);
					if (buf != "0") {
						for (int i = 0; i < additive.size(); i++) {
							if (additive[i].getNameAdditive() == buf) {
								printf("\n\n1. - One portion additive\n");
								printf("2. - Double portion additive\n");
								printf("3. - One portion of additive and one another additive\n");
								printf("4. - Double portion additive and one another additive\n");
								printf("5. - I have changed my mind, i will be without additive\n");
								choiceAdditive = _getch();
								while (choiceAdditive > 53 || choiceAdditive < 49) {
									try {
										if (choiceAdditive > 53 || choiceAdditive < 49)
											throw 1;
									}
									catch (int error) {
										system("cls");
										cout << "Wrong choice\n\n";
									}
									printf("\n\n1. - One portion additive\n");
									printf("2. - Double portion additive\n");
									printf("3. - One portion of additive and one another additive\n");
									printf("4. - Double portion additive and one another additive\n");
									printf("5. - I have changed my mind, i will be without additive\n");
									choiceAdditive = _getch();
								}
								if (choiceAdditive == '1') {
									allAdditive.append(buf);
									orderPrice += additive[i].getCostAdditive();
									cout << "Order Price = " << orderPrice << endl;
									break;
								}
								if (choiceAdditive == '2') {
									allAdditive.append(buf);
									orderPrice += (additive[i].getCostAdditive() * 2);
									cout << "Order Price = " << orderPrice << endl;
									break;
								}
								if (choiceAdditive == '3') {
									system("cls");
									orderPrice += additive[i].getCostAdditive();
									cout << "Order Price = " << orderPrice << endl;
									allAdditive.append(buf);
									allAdditive.append(", ");

									addit.printAdditive(additive);
									cout << "\n\nEnter Name Additive : ";
									getline(cin, buf);
									i = -1;
								}
								if (choiceAdditive == '4') {
									system("cls");
									orderPrice += (additive[i].getCostAdditive() * 2);
									cout << "Order Price = " << orderPrice << endl;
									allAdditive.append(buf);
									allAdditive.append(", ");
									addit.printAdditive(additive);
									cout << "\n\nEnter Name Additive : ";
									getline(cin, buf);
									i = -1;
								}
							}
							else if (i == additive.size() - 1) {
								cout << "\n\n========== Wrong Additive ==========\n\n";
								printf("1. - Try again\n");
								printf("2. - I will be without additive\n");
								choice = _getch();
								while (choice != '1' && choice != '2') {
									try {
										if (id == 0)
											throw 1;
									}
									catch (int error) {
										system("cls");
										cout << "Wrong choice\n\n";
									}
									printf("1. - Try again\n");
									printf("2. - I will be without additive\n");
									choice = _getch();
								}
								if (choice == '1') {
									system("cls");
									addit.printAdditive(additive);
									cout << "\n\nEnter Name Additive : ";
									getline(cin, buf);
									i = -1;
								}
								if (choice == '2')
									cout << "It's your choice ";
							}
						}
					}
				}
				system("cls");
				if (clients[numberClient].getSpentMoney() > 500)
					orderPrice -= (orderPrice / 100) * 15;

				cout << "Your coffee : " << coffee << "\n" << "Additive : " << allAdditive << endl;
				cout << "Order Price = " << orderPrice;
				clients[numberClient].setSpentMoney(clients[numberClient].getSpentMoney() + orderPrice);

				ofstream orders("Orders.txt", ios::app);
				if (orders.is_open())
					orders << coffee << "," << allAdditive << "," << orderPrice << endl;
				cout << "\n\n========== Thanks, good bye ==========\n\n";
			}
			break;
		}
		case '2': {
			cout << "\n\n========== See you latter! ==========\n\n";
			break;
		}
		}
	}

	void work(vector<Additive> &additive, vector<Coffee> &coffeee, vector<Client> &clients) {
		Additive addit;
		Coffee coff;
		Client cli;
		char choice;
		char choiceClient;
		do {
			cout << "========== MAIN MENU ==========\n\n";
			printf("1. - I'm barista\n");
			printf("2. - I'm client\n");
			printf("3. - Exit\n");
			choice = _getch();
			try {
				if (choice < 49 || choice > 51)
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong choice\n\n";
			}
			switch (choice) {
			case '1': {
				system("cls");
				do {
					cout << "========== BARISTA MENU ==========\n\n";
					menuForBarista();
					choice = _getch();
					try {
						if (choice < 49 || choice > 56)
							throw 1;
					}
					catch (int error) {
						system("cls");
						cout << "Wrong choice\n\n";
					}
					switch (choice) {
					case '1':
						system("cls");
						coff.printCoffee(coffeee);
						break;
					case '2':
						system("cls");
						addit.printAdditive(additive);
						break;
					case '3':
						system("cls");
						cli.printClients(clients);
						break;
					case '4':
						system("cls");
						cout << "Earned money : " << cli.money(clients) << endl << endl;
						break;
					case '5':
						system("cls");
						coff.addCoffee(coffeee, additive);
						break;
					case '6':
						system("cls");
						addit.addAdditive(additive);
						break;
					case '7':
						system("cls");
						cout << "SAVING.......................\n\n";
						cli.saveClients(clients);
						addit.saveAdditive(additive);
						coff.saveCoffee(coffeee);
						break;
					case '8':
						system("cls");
						break;
					}
				} while (choice != '8');
				break;
			}
			case '2': {
				system("cls");
				do {
					cout << "========== CLIENT'S MENU ==========\n\n";
					menuForClient();
					choiceClient = _getch();
					try {
						if (choiceClient < 49 || choiceClient > 51)
							throw 1;
					}
					catch (int error) {
						system("cls");
						cout << "Wrong choice\n\n";
					}
					switch (choiceClient) {
					case '1':
						system("cls");
						cli.howMuchClientSpent(clients);
						break;
					case '2':
						system("cls");
						CoffeeHouse::menuForClients(additive, coffeee, clients);
						break;
					case '3':
						system("cls");
						break;
					}
				} while (choiceClient != '3');
				break;
			}
			}
		} while (choice != '3');
	}
};