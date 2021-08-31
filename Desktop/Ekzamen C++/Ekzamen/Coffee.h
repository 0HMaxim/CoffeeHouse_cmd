#pragma once
#include "Header.h"

class Coffee {
	double water;
	double milk;
	double coffee;
	double additive;
	string nameAdditive;
	string name;
	double costCoffePortion;
public:


	friend class Additive;
	friend class CoffeeHouse;
	friend class Client;



	Coffee() :water(10), milk(14), coffee(15.11), name("Espresso"), nameAdditive("Without additive"), additive(0) {}



	Coffee(string name) :water(10), milk(14), coffee(15.11), name(name), costCoffePortion(0) {}
	Coffee(string name, string nameAdditive, double additive) :water(10), milk(14), coffee(15.11),
		name(name), nameAdditive(nameAdditive), additive(additive) {}


	Coffee(string nameAdditive, double additive) :nameAdditive(nameAdditive), additive(additive) {}


	double resultCostCoffee() {
		return costCoffePortion = getCostMilk() + getCostWater() + getCostCoffee() + getCostAdditive();
	}


	void setCostCoffePortion(double cost) {
		this->costCoffePortion = cost;
	}
	void setCostCoffee(double coffee) {
		this->coffee = coffee;
	}
	void setCostMilk(double milk) {
		this->milk = milk;
	}
	void setNameCoffee(string name) {
		this->name = name;
	}
	void setCostAdditive(double additive) {
		this->additive = additive;
	}
	void setNameAdditive(string nameAdditive) {
		this->nameAdditive = nameAdditive;
	}
	void setCostWater(double water) {
		this->water = water;
	}

	bool trueCoffee(vector<Coffee> &coffeee, string obj) {
		for (int i = 0; i < coffeee.size(); i++) {
			if (coffeee[i].getName() == obj)
				return true;
		}
		cout << "Wrong name Coffee";
		return false;
	}



	void printCoffee(vector<Coffee> &coffeee) {
		for (int i = 0; i < coffeee.size(); i++) {
			cout << coffeee[i].getName() << endl;
			if (coffeee[i].getNameAdditive() == "0")
				cout << "Without additive" << endl;
			else
				cout << coffeee[i].getNameAdditive() << " : " << coffeee[i].getCostAdditive() << endl;
			cout << "cost portion : " << coffeee[i].getCostPortion() << endl << endl;
		}
	}

	void saveCoffee(vector<Coffee> &coffeee) {
		ofstream catalog("Catalog.txt");
		for (int i = 0; i < coffeee.size(); i++) {
			catalog << coffeee[i].getName() << ",";
			if (coffeee[i].getNameAdditive() == "Without additive")
				catalog << 0 << "," << 0 << " ";
			else
				catalog << coffeee[i].getNameAdditive() << "," << coffeee[i].getCostAdditive() << " ";
			catalog << coffeee[i].getCostPortion();
			if (i < coffeee.size() - 1)
				catalog << endl;
		}
		catalog.close();
	}



	int countCoffe() {
		string buf;
		ifstream catalog("Catalog.txt");
		int countRows = 1;
		if (catalog.is_open()) {
			countRows = 0;
			while (!catalog.eof()) {
				getline(catalog, buf);
				countRows++;
			}
			catalog.close();
		}
		else {
			catalog.close();
			ofstream catalog("Catalog.txt");
			catalog << "Espresso" << "," << 0 << "," << 0 << " " << 18.61;
			catalog.close();
		}
		return countRows;
	}


	int readCoffe(vector<Coffee> &coffeee) {
		string buf;
		double cost;
		int i = 0;
		ifstream catalog("Catalog.txt");
		if (catalog.is_open()) {
			while (!catalog.eof()) {
				getline(catalog, buf, ',');
				if (buf == ""&&i == 0) {
					coffeee[i].setNameCoffee("Espresso");
					coffeee[i].setNameAdditive("0");
					coffeee[i].setCostAdditive(0);
					coffeee[i].setCostCoffePortion(18.61);
					return 1;
				}
				coffeee[i].setNameCoffee(buf);
				getline(catalog, buf, ',');
				coffeee[i].setNameAdditive(buf);
				catalog >> cost;
				coffeee[i].setCostAdditive(cost);
				catalog >> cost;
				coffeee[i++].setCostCoffePortion(cost);
				getline(catalog, buf, '\n');
			}
		}
		catalog.close();
		return 0;
	}

	int addCoffee(vector<Coffee> &coffeee, vector<Additive> &additive) {
		Additive addit;
		Coffee coff;
		Client cli;

		string buf;
		string additiveA;
		char cost[50];
		int costInt;
		char choice;
		coffeee.resize(coffeee.size() + 1);
		cout << "Enter name Coffee : ";
		getline(cin, buf);
		coffeee[coffeee.size() - 1].setNameCoffee(buf);
		printf("1. - Coffee will be with milk\n");
		printf("2. - Coffee will be with wather\n");
		printf("3. - Exit\n");
		choice = _getch();
		while (choice != '1' && choice != '2' && choice != '3') {
			try {
				if (choice < 49 || choice > 50)
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong choice\n\n";
			}
			printf("1. - Coffee will be with milk\n");
			printf("2. - Coffee will be with wather\n");
			printf("3. - Exit\n");
			choice = _getch();
		}
		switch (choice) {
		case '1':
			coffeee[coffeee.size() - 1].setCostWater(0);
			break;
		case '2':
			coffeee[coffeee.size() - 1].setCostMilk(0);
			break;
		case '3':
			coffeee.resize(coffeee.size() - 1);
			return 0;
			break;
		}
		system("cls");
		printf("1. - Coffee will be with additive\n");
		printf("2. - Coffee will be without additive\n");
		printf("3. - Exit\n");
		choice = _getch();
		while (choice != '1' && choice != '2' && choice != '3') {
			try {
				if (choice < 49 || choice > 50)
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong choice\n\n";
			}
			printf("1. - Coffee will be with additive\n");
			printf("2. - Coffee will be without additive\n");
			printf("3. - Exit\n");
			choice = _getch();
		}
		switch (choice) {
		case '1':
			system("cls");
			printf("1. - Create new additive\n");
			printf("2. - Use ready-made\n");
			choice = _getch();
			while (choice != '1' && choice != '2') {
				try {
					if (choice < 49 || choice > 50)
						throw 1;
				}
				catch (int error) {
					system("cls");
					cout << "Wrong choice\n\n";
				}
				printf("1. - Create new additive\n");
				printf("2. - Use ready-made\n");
				choice = _getch();
			}
			switch (choice) {
			case '1':
				addit.addAdditive(additive);
				coffeee[coffeee.size() - 1].setNameAdditive(additive[additive.size() - 1].getNameAdditive());
				coffeee[coffeee.size() - 1].setCostAdditive(additive[additive.size() - 1].getCostAdditive());
				break;
			case '2':
				addit.printAdditive(additive);
				cout << "========== Choice additive ==========\n\n";
				getline(cin, buf);
				for (int i = 0; i < additive.size(); i++) {
					if (buf == additive[i].getNameAdditive()) {
						cout << "Yes, it's additive is present\n";
						coffeee[coffeee.size() - 1].setNameAdditive(buf);
						coffeee[coffeee.size() - 1].setCostAdditive(additive[i].getCostAdditive());
						additiveA = buf;
					}
					if (i == additive.size() - 1 && additiveA.size() == 0) {
						cout << "\n\n========== Wrong name additive ==========\n\n";
						printf("1. - Try again\n");
						printf("2. - Coffee will be without additive\n");
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
							printf("2. - Coffee will be without additive\n");
							choice = _getch();
						}
						if (choice == '1') {
							system("cls");
							addit.printAdditive(additive);
							cout << "========== Choice additive ==========\n\n";
							getline(cin, buf);
							i = -1;
						}
						if (choice == '2')
							break;
					}
				}
				break;
			}
			break;
		case '2':
			coffeee[coffeee.size() - 1].setCostAdditive(0);
			system("cls");
			break;
		case '3':
			coffeee.resize(coffeee.size() - 1);
			system("cls");
			return 0;
			break;
		}
		printf("1. - Enter cost coffee\n");
		printf("2. - Set the cost of a portion by the cost of products\n");
		printf("3. - Exit\n");
		choice = _getch();
		while (choice != '1' && choice != '2' && choice != '3') {
			try {
				if (choice < 49 || choice > 50)
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrong choice\n\n";
			}
			printf("1. - Enter cost coffee\n");
			printf("2. - Set the cost of a portion by the cost of products\n");
			printf("3. - Delte all changes Exit\n");
			choice = _getch();
		}
		switch (choice) {
		case '1':
			cout << "Enter cost: ";
			cin.getline(cost, 50);
			costInt = atoi(cost);
			while (costInt == 0) {
				try {
					if (costInt == 0)
						throw 2;
				}
				catch (int error) {
					system("cls");
					cout << "Wrong format cost\n\n";

				}
				cout << "Enter true cost: ";
				cin.getline(cost, 50);
				costInt = atoi(cost);
			}
			coffeee[coffeee.size() - 1].setCostCoffePortion(costInt);
			system("cls");
			break;
		case '2':
			coffeee[coffeee.size() - 1].resultCostCoffee();
			system("cls");
			break;
		case '3':
			coffeee.resize(coffeee.size() - 1);
			system("cls");
			return 0;
			break;
		}
		cout << coffeee[coffeee.size() - 1].getName() << endl;
		if (coffeee[coffeee.size() - 1].getNameAdditive() == "0")
			cout << "Without additive" << endl;
		else
			cout << coffeee[coffeee.size() - 1].getNameAdditive() << " : " << coffeee[coffeee.size() - 1].getCostAdditive() << endl;
		cout << "cost portion : " << coffeee[coffeee.size() - 1].getCostPortion() << endl << endl;
	}



	double getCostPortion() { return costCoffePortion; }
	double getCostWater() { return water; }
	double getCostMilk() { return  milk; }
	double getCostCoffee() { return coffee; }
	double getCostAdditive() { return additive; }
	string getNameAdditive() { return nameAdditive; }
	string getName() { return name; }
};