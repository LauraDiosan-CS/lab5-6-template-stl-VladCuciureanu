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
	//Blank constructor
	Cake();
	//Parameterized constructor
	Cake(int cakeId, const char* name, const char* ingredients, double price);
	//Copy constructor
	Cake(const Cake& c);
	//Destructor
	~Cake();
	//Id getter
	int getId();
	//Name getter
	char* getName();
	//Ingredients getter
	char* getIngredients();
	//Price getter
	double getPrice();
	//Id setter
	void setId(int cakeId);
	//Name setter
	void setName(const char* name);
	//Ingredients setter
	void setIngredients(const char* ingredients);
	//Price setter
	void setPrice(double price);
	//Copy operator
	Cake& operator=(const Cake& s);
	//Equals operator
	bool operator==(const Cake& s);
	//Serializer
	friend std::ostream& operator<<(std::ostream& os, const Cake& s);
};

