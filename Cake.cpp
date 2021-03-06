#include "Cake.h"

Cake::Cake() : Entity() {
	this->name = NULL;
	this->ingredients = NULL;
	this->price = 0;
}

Cake::Cake(int cakeId, const char* name, const char* ingredients, double price) : Entity(cakeId)
{
	this->name = new char[std::strlen(name)+1];
	strcpy_s(this->name, strlen(name)+1, name);
	this->ingredients = new char[std::strlen(ingredients) + 1];
	strcpy_s(this->ingredients, strlen(ingredients) + 1, ingredients);
	this->price = price;
}

Cake::Cake(const Cake& c) : Entity(c)
{
	this->price = c.price;
	this->name = new char[strlen(c.name) + 1];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);
	this->ingredients = new char[strlen(c.ingredients) + 1];
	strcpy_s(this->ingredients, strlen(c.ingredients) + 1, c.ingredients);
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

unsigned int Cake::getId()
{
	return this->entityId;
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
	this->entityId = cakeId;
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
	Entity::operator=(s);
	this->setName(s.name);
	this->setIngredients(s.ingredients);
	this->setPrice(s.price);
	return *this;
}

bool Cake:: operator==(const Cake& s) {
	if (this->entityId != s.entityId)
		return false;
	if (strcmp(this->name, s.name) != 0)
		return false;
	if (strcmp(this->ingredients, s.ingredients) != 0)
		return false;
	if (this->price != s.price)
		return false;
	return true;
}

bool Cake:: operator!=(const Cake& s) {
	return !(Cake::operator==(s));
}

std::ostream& operator<<(std::ostream& os, const Cake& s)
{
	os << s.entityId << "|" << s.name << "|" << s.ingredients << "|" << s.price;
	return os;
}

void Cake::fromString(std::string info)
{/*
	int index1 = 0;
	int index2 = 0;
	while (info[index1] != '|')
		index1++;
	this->setId(stoi(info.substr(0, index1)));
	index1++;
	index2 = index1;
	while (info[index2] != '|')
		index2++;
	this->setName(info.substr(index1, index2 - index1).c_str());
	index1 = index2;
	index1++;
	index2 = index1;
	while (info[index2] != '|')
		index2++;
	this->setIngredients(info.substr(index1, index2 - index1).c_str());
	index1 = index2;
	index1++;
	this->setPrice(stod(info.substr(index1, info.length()-index1)));*/
	int i1 = info.length()-1, i2 = info.length()-1;
	while (info[i1] != '|')
		i1--;
	this->setPrice(stod(info.substr(i1+1, i2-i1+1)));
	i1--;
	i2 = i1;
	while (info[i1] != '|')
		i1--;
	this->setIngredients(info.substr(i1 + 1, i2 - i1).c_str());
	i1--;
	i2 = i1;
	while (info[i1] != '|')
		i1--;
	this->setName(info.substr(i1 + 1, i2 - i1).c_str());
	i2 = i1;
	i2--;
	i1 = 0;
	this->setId(stoi(info.substr(i1, i2-i1+1)));
}