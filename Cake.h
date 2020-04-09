#pragma once
#include <cstddef>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Entity.h"

class Cake : public Entity
{
private:
	char* name;
	char* ingredients;
	double price;
public:
	/*
	Blank constructor
	*/
	Cake();
	
	/*
	Parameterized constructor
	In: entity ID
	In: cake name
	In: cake ingredients
	In: cake price
	*/
	Cake(int cakeId, const char* name, const char* ingredients, double price);
	
	/*
	Copy constructor
	In: object to be copied.
	*/
	Cake(const Cake& c);

	/*
	Destructor
	*/
	~Cake();
	
	//Id getter
	unsigned int getId();
	
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
	
	//Parses string
	void fromString(std::string info);

	//Copy operator
	Cake& operator=(const Cake& s);
	
	//Equals operator
	bool operator==(const Cake& s);

	//Not equals operator
	bool operator!=(const Cake& s);
	
	//Serializer
	friend std::ostream& operator<<(std::ostream& os, const Cake& s);
};

