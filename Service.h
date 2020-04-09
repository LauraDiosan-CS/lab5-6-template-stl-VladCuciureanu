#pragma once
#include "Cake.h"
#include "RepoSTLTemplate.h"
#include <vector>
#include <set>
#include <map>

class Service
{
private:
	RepoSTLTemplate<Cake>* repo;
	std::set<std::string> ingredients;
public:
	/*
	Blank constructor.
	*/
	Service();

	/*
	Parameterized construtor.
	In: provided repo.
	*/
	Service(RepoSTLTemplate<Cake>* repo);
	
	/*
	Destructor
	*/
	~Service();

	/*
	Add cake with given values to repo.
	In: cake name
	In: cake ingredients
	In: cake price
	*/
	void addCake(const char* name, const char* ingredients, double price);
	
	/*
	Gets all cakes from repo.
	Out: vector of cakes.
	*/
	std::vector<Cake> getCakes();

	/*
	Returns cake with given id if it exists.
	In: given cake id.
	*/
	Cake getCakeById(unsigned int id);

	/*
	Updates cake with given it with given values.
	In: cake id
	In: new cake name.
	In: new cake ingredients.
	In: new cake price.
	*/
	void updateCake(unsigned int id, const char* newName, const char* newIngredients, const double newPrice);
	
	/*
	Deletes cake with given id.
	In: cake id.
	*/
	void deleteCake(unsigned int id);

	/*
	Checks cakes for new ingredients.
	*/
	void refreshIngredients();

	/*
	Returns averages of all cakes using an ingredient, for all ingredients.
	*/
	std::map<std::string, double> avgIngredients();
};

