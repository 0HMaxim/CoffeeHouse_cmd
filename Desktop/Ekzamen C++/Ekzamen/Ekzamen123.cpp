#pragma once
#include "Header.h"


void main() {
	CoffeeHouse arom;
	Additive addit;
	Coffee coff;
	Client cli;

	vector<Additive> additive(addit.countAdditive());
	vector<Coffee> coffeee(coff.countCoffe());
	vector<Client> clients(cli.countClients());

	cli.readClients(clients);
	addit.readAdditive(additive);
	coff.readCoffe(coffeee);

	try {
		arom.work(additive, coffeee, clients);
	}
	catch (int error) {
		if (error == 1)
			cout << "Wrong choice";
		if (error == 2)
			cout << "Wrong format id";
	}



	cli.saveClients(clients);
	addit.saveAdditive(additive);
	coff.saveCoffee(coffeee);

	cout << endl << endl;
	system("pause");
}


































/*additive[0].setNameAdditive("Cinnamon");
	additive[0].setCostAdditive(3.1);

	additive[1].setNameAdditive("Chocolate Syrup");
	additive[1].setCostAdditive(5);

	additive[2].setNameAdditive("Caramel Syrup");
	additive[2].setCostAdditive(7);

	additive[3].setNameAdditive("Mohito Syrup");
	additive[3].setCostAdditive(11);

	additive[4].setNameAdditive("Vanilla Syrup");
	additive[4].setCostAdditive(11);


	additive[5].setNameAdditive("Pistachio Syrup");
	additive[5].setCostAdditive(13);

	additive[6].setNameAdditive("Whipped Cream");
	additive[6].setCostAdditive(5.8);

	additive[7].setNameAdditive("Chopped Chocolate");
	additive[7].setCostAdditive(5.8);


	additive[8].setNameAdditive("Marshmallow");
	additive[8].setCostAdditive(11);

	additive[9].setNameAdditive("Ice Cream");
	additive[9].setCostAdditive(7.8);



	coffeee[0].setNameCoffee("Espresso Macchiato");
	coffeee[0].setCostWater(0);
	coffeee[0].setCostCoffePortion(coffeee[0].getCostMilk() / 4 + coffeee[0].getCostCoffee());


	coffeee[1].setNameCoffee("Doppio");
	coffeee[1].setCostMilk(10);
	coffeee[1].setCostWater(0);
	coffeee[1].setCostCoffePortion((coffeee[1].getCostCoffee() + coffeee[1].getCostMilk()) * 2);


	coffeee[2].setNameCoffee("Romano");
	coffeee[2].setNameAdditive("Lemon");
	coffeee[2].setCostAdditive(2.2);
	coffeee[2].setCostWater(0);
	coffeee[2].resultCostCoffee();


	coffeee[3].setNameCoffee("Cappuccino");
	coffeee[3].setCostWater(0);
	coffeee[3].setCostCoffePortion(coffeee[3].getCostMilk()*1.4 + coffeee[3].getCostCoffee());
	coffeee[3].resultCostCoffee();


	coffeee[4].setNameCoffee("Latte Macchiato");
	coffeee[4].setCostWater(0);
	coffeee[4].setCostCoffePortion(coffeee[4].getCostMilk() + coffeee[3].getCostCoffee() / 3);


	coffeee[5].setNameCoffee("Schiumato");
	coffeee[5].setCostCoffePortion(coffeee[5].getCostMilk() / 10 + coffeee[5].getCostCoffee()+ coffeee[5].getCostWater());


	coffeee[6].setNameCoffee("Irish Coffee");
	coffeee[6].setNameAdditive("Irish whiskey");
	coffeee[6].setCostAdditive(34.84);
	coffeee[6].setCostCoffePortion(coffeee[6].getCostMilk() / 6 + coffeee[6].getCostCoffee() / 3 + 34.84);*/