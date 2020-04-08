#include "UserInterface.h"

UserInterface::UserInterface()
{
	RepoSTLTemplate<Cake> repo;
	this->service = Service(repo, "");
}

UserInterface::UserInterface(const Service& service)
{
	this->service = service;
}

UserInterface::~UserInterface(){}

void handleDisplayOptions()
{
	std::cout << " 1. Add cake\n";
	std::cout << " 2. Display cakes\n";
	std::cout << " 3. Update cakes\n";
	std::cout << " 4. Delete cake\n";
	std::cout << " 0. Exit app\n";
}

void UserInterface::handleAddCake()
{
	std::string name, ingredients;
	std::cout << "Cake name: ";
	std::cin >> name;
	std::cout << "Cake ingredients: ";
	std::cin >> ingredients;
	double price;
	std::cout << "Cake price: ";
	std::cin >> price;
	this->service.addCake(name.c_str(), ingredients.c_str(), price);
}

void UserInterface::handleDisplayCakes()
{
	std::vector<Cake> cakes = this->service.getCakes();
	for (Cake c : cakes)
	{
		std::cout << c << '\n';
	}
}

void UserInterface::handleUpdateCake()
{
	int cakeId;
	std::cout << "Cake ID: ";
	std::cin >> cakeId;
	if (this->service.getCakeById(cakeId).getId() == -1)
		return;
	std::string name = "", ingredients = "", price = "";
	std::cout << "Cake name: ";
	std::cin.get();
	std::getline(std::cin, name);
	std::cout << "Cake ingredients: ";
	std::getline(std::cin, ingredients);
	std::cout << "Cake price: ";
	std::getline(std::cin, price);
	this->service.updateCake(cakeId, name=="\0"?"":name.c_str(), ingredients=="\0"?"":ingredients.c_str(), price=="" ? -1 : std::stoi(price));
}

void UserInterface::handleDeleteCake()
{
	int cakeId;
	std::cout << "Cake ID: ";
	std::cin >> cakeId;
	this->service.deleteCake(cakeId);
}

void UserInterface::startLoop()
{
	while (!this->exitTrigger)
	{
		handleDisplayOptions();
		std::cout << "\nChoice: ";
		int choice;
		std::cin >> choice;
		std::cout << "\n";
		switch (choice)
		{
		case 1:
			handleAddCake();
			break;
		case 2:
			handleDisplayCakes();
			break;
		case 3:
			handleUpdateCake();
			break;
		case 4:
			handleDeleteCake();
			break;
		case 0:
			this->exitTrigger = true;
			break;
		}
		std::cout << '\n';
	}
}