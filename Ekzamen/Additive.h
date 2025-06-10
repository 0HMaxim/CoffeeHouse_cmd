#pragma once
#include "Header.h"

class Additive {
	string nameAdditive;
	double additive;
public:

	friend class Coffee;
	friend class CoffeeHouse;
	friend class Client;



	Additive() :nameAdditive("Unknown"), additive(0) {}
	Additive(string nameAdditive, double additive) :nameAdditive(nameAdditive), additive(additive) {}
	void setCostAdditive(double additive) {
		this->additive = additive;
	}
	void setNameAdditive(string nameAdditive) {
		this->nameAdditive = nameAdditive;
	}
	void printAdditive(vector<Additive> &additive) {
		for (int i = 0; i < additive.size(); i++)
			cout << additive[i].getNameAdditive() << ": " << additive[i].getCostAdditive() << endl;
		cout << endl;
	}

	int countAdditive() {
		string buf;
		int countRowsAdditive = 1;
		ifstream catalogAdditive("CatalogAdditive.txt");
		if (catalogAdditive.is_open()) {
			countRowsAdditive = 0;
			while (!catalogAdditive.eof()) {
				getline(catalogAdditive, buf, '\n');
				countRowsAdditive++;
			}
			catalogAdditive.close();
		}
		else {
			catalogAdditive.close();
			ofstream catalogAdditive("CatalogAdditive.txt");
			catalogAdditive << "Cinnamon" << ":" << 3.1;
			catalogAdditive.close();
		}
		return countRowsAdditive;
	}


	void saveAdditive(vector<Additive> &additive) {
		ofstream catalogAdditive("CatalogAdditive.txt");
		for (int i = 0; i < additive.size(); i++) {
			catalogAdditive << additive[i].getNameAdditive() << ":" << additive[i].getCostAdditive();
			if (i < additive.size() - 1)
				catalogAdditive << endl;
		}
		catalogAdditive.close();
	}

	int readAdditive(vector<Additive> &additive) {
		string buf;
		double cost;
		int i = 0;
		ifstream catalogAdditive("CatalogAdditive.txt");
		if (catalogAdditive.is_open()) {
			while (!catalogAdditive.eof()) {
				getline(catalogAdditive, buf, ':');
				if (buf == ""&&i == 0) {
					additive[i].setNameAdditive("Cinnamon");
					additive[i++].setCostAdditive(3.1);
					return 1;
				}
				additive[i].setNameAdditive(buf);
				catalogAdditive >> cost;
				additive[i++].setCostAdditive(cost);
				getline(catalogAdditive, buf, '\n');
			}
		}
		catalogAdditive.close();
		return 0;
	}

	void addAdditive(vector<Additive>&additive) {
		string buf;
		int cost;
		char costBuf[50];
		additive.resize(additive.size() + 1);
		cout << "Enter name Additive : ";
		cin.ignore();
		getline(cin, buf);
		additive[additive.size() - 1].setNameAdditive(buf);
		cout << "Enter cost Additive : ";
		cin.getline(costBuf, 50);
		cost = atoi(costBuf);
		while (cost == 0) {
			try {
				if (cost == 0)
					throw 1;
			}
			catch (int error) {
				system("cls");
				cout << "Wrond format price\n\n";
			}
			cout << "Enter cost Additive : ";
			cin.getline(costBuf, 50);
			cost = atoi(costBuf);
		}
		additive[additive.size() - 1].setCostAdditive(cost);
		cout << additive[additive.size() - 1].getNameAdditive() << ": " << additive[additive.size() - 1].getCostAdditive() << endl;
		cout << endl;
	}


	double getCostAdditive() { return additive; }
	string getNameAdditive() { return nameAdditive; }
};