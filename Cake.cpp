#include "Cake.h"

Cake::Cake() {
	this->cakeId = 0;
	this->name = NULL;
	this->ingredients = NULL;
	this->price = 0;
}

Cake::Cake(int cakeId, const char* name, const char* ingredients, double price)
{
	this->cakeId = cakeId;
	this->name = new char[std::strlen(name)+1];
	strcpy_s(this->name, strlen(name)+1, name);
	this->ingredients = new char[std::strlen(ingredients) + 1];
	strcpy_s(this->ingredients, strlen(ingredients) + 1, ingredients);
	this->price = price;
}

Cake::~Cake()
{
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	if (this->ingredients) {
		delete[] this->ingredients;
		this->ingredients = NULL;
	}
}

int Cake::getId()
{
	return this->cakeId;
}

char* Cake::getName()
{
	return this->name;
}

char* Cake::getIngredients()
{
	return this->ingredients;
}

double Cake::getPrice()
{
	return this->price;
}

void Cake::setId(int cakeId)
{
	this->cakeId = cakeId;
}

void Cake::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Cake::setIngredients(const char* ingredients)
{
	if (this->ingredients) {
		delete[] this->ingredients;
	}
	this->ingredients = new char[strlen(ingredients) + 1];
	strcpy_s(this->ingredients, strlen(ingredients) + 1, ingredients);
}

void Cake::setPrice(double price)
{
	this->price = price;
}

Cake& Cake::operator=(const Cake& s) {
	this->setId(s.cakeId);
	this->setName(s.name);
	this->setIngredients(s.ingredients);
	this->setPrice(s.price);
	return *this;
}

bool Cake:: operator==(const Cake& s) {
	if (this->cakeId != s.cakeId)
		return false;
	if (strcmp(this->name, s.name) != 0)
		return false;
	if (strcmp(this->ingredients, s.ingredients) != 0)
		return false;
	if (this->price != s.price)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Cake& s)
{
	os << s.cakeId << " " << s.name << " " << s.ingredients << " " << s.price;
	return os;
}