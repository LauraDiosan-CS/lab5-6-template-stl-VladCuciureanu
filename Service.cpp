#include "Service.h"
#include <fstream>

Service::Service()
{
	this->repo = RepoSTLTemplate<Cake>();
}

Service::Service(RepoSTLTemplate<Cake> repo, const char* fileName)
{
	this->repo = repo;
	this->fileName = new char[strlen(fileName) + 1];
	strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
}

Service::~Service() {}

void Service::addCake(const char* name, const char* ingredients, double price)
{
	unsigned int id = this->repo.getFreeId();
	Cake newCake = Cake(id, name, ingredients, price);
	this->repo.addElem(newCake);
}

std::vector<Cake> Service::getCakes()
{
	return this->repo.getAll();
}

Cake Service::getCakeById(unsigned int id)
{
	return *(this->repo.findElemById(id));
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
	this->repo.updateElem(id, newCake);
}

void Service::deleteCake(unsigned int id)
{
	this->repo.delElem(id);
}

void Service::save()
{
	if (this->fileName == NULL)
		return;
	std::ofstream out(this->fileName);
	std::vector<Cake> cakes = this->repo.getAll();
	out << cakes.size() << '\n';
	for (Cake c : cakes)
	{
		out << c.getId() << '\n';
		out << c.getName() << '\n';
		out << c.getIngredients() << '\n';
		out << c.getPrice() << '\n';
	}
	out.close();
}

void Service::load()
{
	if (this->fileName == NULL)
		return;
	std::ifstream in(this->fileName);
	int size;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		int id;
		in >> id;
		char* name = new char[101];
		char* ingredients = new char[101];
		in.get();
		in.getline(name, 101);
		in.getline(ingredients, 101);
		double price;
		in >> price;
		in.get();
		Cake newCake = Cake(id, name, ingredients, price);
		this->repo.addElem(newCake);
	}
	in.close();
}