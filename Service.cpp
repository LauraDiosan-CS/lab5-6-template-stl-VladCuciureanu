#include "Service.h"
#include <fstream>

Service::Service()
{
	this->repo = new RepoSTLTemplate<Cake>();
}

Service::Service(RepoSTLTemplate<Cake>* repo)
{
	this->repo = repo;
}

Service::~Service() {}

void Service::addCake(const char* name, const char* ingredients, double price)
{
	unsigned int id = this->repo->getFreeId();
	Cake newCake = Cake(id, name, ingredients, price);
	this->repo->addElem(newCake);
}

std::vector<Cake> Service::getCakes()
{
	return this->repo->getAll();
}

Cake Service::getCakeById(unsigned int id)
{
	if (this->repo->findElemById(id) != this->repo->getEnd())
		return *(this->repo->findElemById(id));
	else
		return Cake(-1, "", "", -1);
}

void Service::updateCake(unsigned int id, const char* newName = "", const char* newIngredients = "", const double newPrice = -1)
{
	Cake newCake = this->getCakeById(id);
	if (newName != "")
		newCake.setName(newName);
	if (newIngredients != "")
		newCake.setIngredients(newIngredients);
	if (newPrice != -1)
		newCake.setPrice(newPrice);
	this->repo->updateElem(id, newCake);
}

void Service::deleteCake(unsigned int id)
{
	this->repo->delElem(id);
}

std::map<std::string, double> Service::avgIngredients()
{
	std::map<std::string, double> results;
	std::map<std::string, int> counter;
	this->refreshIngredients();
	for (std::string ingredient : this->ingredients)
	{
		results[ingredient] = 0;
		counter[ingredient] = 0;
		for (Cake cake : this->repo->getAll())
		{
			if (std::string(cake.getIngredients()).find(ingredient) != std::string::npos)
			{
				results[ingredient]+=cake.getPrice();
				counter[ingredient]++;
			}
		}
		results[ingredient] /= counter[ingredient];
	}
	return results;
}

void Service::refreshIngredients()
{
	if (this->repo->getAll().size() == 0)
		return;
	std::vector<Cake> cakes = this->repo->getAll();
	for (Cake c : cakes) {
		int ingIndex = 0;
		std::string ingString = std::string(c.getIngredients());
		for (int i = 0; i < ingString.length(); i++)
		{
			if (ingString[i] == ',')
			{
				i++;
				this->ingredients.insert(ingString.substr(ingIndex, i - ingIndex-1));
				ingIndex = i;
			}
		}
		this->ingredients.insert(ingString.substr(ingIndex, ingString.length() - ingIndex));
	}
}