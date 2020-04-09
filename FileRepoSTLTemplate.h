#pragma once
#include "RepoSTLTemplate.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

template <class T>
class FileRepoSTLTemplate : public RepoSTLTemplate<T>
{
private:
	char* fileName;

public:
	/*
	Blank constructor
	*/
	FileRepoSTLTemplate() {}

	/*
	Parameterized constructor
	*/
	FileRepoSTLTemplate(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->load();
	}

	/*
	Destructor
	*/
	~FileRepoSTLTemplate() {}

	void addElem(T t)
	{
		RepoSTLTemplate<T>::addElem(t);
		this->save();
	}

	void updateElem(unsigned int id, T update)
	{
		RepoSTLTemplate<T>::updateElem(id, update);
		this->save();
	}

	void delElem(unsigned int id)
	{
		RepoSTLTemplate<T>::delElem(id);
		this->save();
	}

	void save()
	{
		if (this->fileName == NULL)
			return;
		std::ofstream out(this->fileName);
		out << this->dim() << '\n';
		for (T t : this->getAll())
		{
			out << t << '\n';
		}
		out.close();
	}

	void load()
	{
		try {
			if (this->fileName == NULL)
				return;
			std::ifstream in(this->fileName);
			int size;
			in >> size;
			in.get();
			for (int i = 0; i < size; i++)
			{
				T t;
				std::string inStr;
				getline(in, inStr);
				t.fromString(inStr);
				this->addElem(t);
			}
			in.close();
		}
		catch (int e) {
			std::cout << "Failed loading from file.\n";
		};
	}
};

