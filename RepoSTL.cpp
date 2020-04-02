#include "RepoSTL.h"

#include <iostream>
using namespace std;

RepoSTL::RepoSTL()
{}

void RepoSTL::addElem(Cake p)
{
	elem.push_back(p);
}

void RepoSTL::delElem(Cake s)
{
	std::vector<Cake>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) elem.erase(it);
}

bool RepoSTL::findElem(Cake p)
{
	vector<Cake>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) return true;
	return false;
}

int RepoSTL::dim()
{
	return elem.size();
}

Cake RepoSTL::getItemFromPos(int i)
{
	return elem[i];
}

RepoSTL::~RepoSTL()
{}

vector<Cake> RepoSTL::getAll()
{
	return elem;
}

void RepoSTL::updateElem(Cake& p, int cakeId, const char* name, const char* ingredients, double price)
{
	for (int i = 0; i < elem.size(); i++)
	{
		if (elem[i] == p)
		{
			elem[i].setId(cakeId);
			elem[i].setName(name);
			elem[i].setIngredients(ingredients);
			elem[i].setPrice(price);
		}
	}

}