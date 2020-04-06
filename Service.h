#pragma once
#include "Cake.h"
#include "RepoSTLTemplate.h"
#include <vector>

class Service
{
private:
	RepoSTLTemplate<Cake> repo;
	char* fileName = NULL;
public:
	/*
	Blank constructor.
	*/
	Service();

	/*
	Parameterized construtor.
	In: provided repo.
	*/
	Service(RepoSTLTemplate<Cake> repo, const char* fileName);
	
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
	Serializes the repo into the file.
	*/
	void save();

	/*
	Loads the repo from file.
	*/
	void load();
};

