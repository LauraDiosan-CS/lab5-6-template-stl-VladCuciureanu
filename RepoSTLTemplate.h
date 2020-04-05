#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Entity.h"

template <class T>
class RepoSTLTemplate
{
private:
	std::vector<T> elem;
public:
	RepoSTLTemplate(){} // Blank constructor
	~RepoSTLTemplate(){} // Destructor

	// Create

	void addElem(T t) { elem.push_back(t); } // Adds given elem.
	
	// Read

	typename std::vector<T>::iterator findElemById(const int entityId) {
		typename std::vector<T>::iterator it;
		it = find_if(this->elem.begin(), this->elem.end(), [entityId](T t) { return ((Entity) t).getId() == entityId; });
		return it;
	}

	std::vector<T> getAll()
	{
		return this->elem;
	}

	// Update

	void updateElem(unsigned int id, T update)
	{
		typename std::vector<T>::iterator it;
		it = findElemById(id);
		*it = update;
	}

	// Delete

	void delElem(unsigned int id)
	{
		typename std::vector<T>::iterator it;
		it = findElemById(id);
		this->elem.erase(it);
	}

	// Misc

	typename std::vector<T>::iterator getEnd()
	{
		return this->elem.end();
	}

	unsigned int dim()
	{
		return this->elem.size();
	}

};