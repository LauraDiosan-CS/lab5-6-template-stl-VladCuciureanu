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