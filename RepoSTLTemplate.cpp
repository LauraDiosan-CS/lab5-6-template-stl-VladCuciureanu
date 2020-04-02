#include "RepoSTLTemplate.h"

#include <iostream>
using namespace std;

template <class T>
RepoSTLTemplate<T>::RepoSTLTemplate()
{}

template <class T>
void RepoSTLTemplate<T>::addElem(T p)
{
	elem.push_back(p);
}

template <class T>
void RepoSTLTemplate<T>::delElem(T s)
{
	typename std::vector<T>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) elem.erase(it);
}

template <class T>
bool RepoSTLTemplate<T>::findElem(T p)
{
	typename vector<T>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) return true;
	return false;
}

template <class T>
int RepoSTLTemplate<T>::dim()
{
	return elem.size();
}

template <class T>
T RepoSTLTemplate<T>::getItemFromPos(int i)
{
	return elem[i];
}

template <class T>
RepoSTLTemplate<T>::~RepoSTLTemplate()
{}

template <class T>
vector<T> RepoSTLTemplate<T>::getAll()
{
	return elem;
}
/*
template <class T>
void RepoSTLTemplate<T>::updateElem(T& p, int cakeId, const char* name, const char* ingredients, double price)
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

}*/