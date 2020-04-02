#pragma once
#include <vector>

template <class T>
class RepoSTLTemplate
{
private:
	std::vector <T> elem;

public:

	//Blank constructor
	RepoSTLTemplate()
	{}

	//Adds given elem to vector
	void addElem(T p)
	{
		elem.push_back(p);
	}

	//Deletes given elem from vector
	void delElem(T s)
	{
		typename std::vector<T>::iterator it;
		it = find(elem.begin(), elem.end(), s);
		if (it != elem.end()) elem.erase(it);
	}

	//Searches for given elem in vector.
	bool findElem(T p)
	{
		typename std::vector<T>::iterator it;
		it = find(elem.begin(), elem.end(), p);
		if (it != elem.end()) return true;
		return false;
	}

	//Returns size of vector.
	int dim()
	{
		return elem.size();
	}

	//Returns item from given position in vector.
	T getItemFromPos(int i)
	{
		return elem[i];
	}

	//Returns all items from vector.
	std::vector<T> getAll()
	{
		return elem;
	}

	//Destructor
	~RepoSTLTemplate()
	{}

	//Updates given elem with new elem.
	void updateElem(T& original, const T newValues)
	{
		for (int i = 0; i < elem.size(); i++)
		{
			if (elem[i] == original)
				elem[i] = newValues;
		}
	}
};
