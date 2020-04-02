#pragma once
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

class Cake
{
private:
	int cakeId;
	char* name;
	char* ingredients;
	double price;
public:
	Cake();
	Cake(int cakeId, const char* name, const char* ingredients, double price);
	~Cake();
	int getId();
	char* getName();
	char* getIngredients();
	double getPrice();
	void setId(int cakeId);
	void setName(const char* name);
	void setIngredients(const char* ingredients);
	void setPrice(double price);
	Cake& operator=(const Cake& s);
	bool operator==(const Cake& s);
	friend std::ostream& operator<<(std::ostream& os, const Cake& s);
};

