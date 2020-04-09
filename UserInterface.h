#pragma once
#include "Service.h"
#include <string>
#include <iostream>

class UserInterface
{
private:
	Service service;
	bool exitTrigger = false;

	/*
	Handles user input for adding cakes.
	*/
	void handleAddCake();

	/*
	Handles user input for displaying cakes.
	*/
	void handleDisplayCakes();

	/*
	Handles user input for updating cakes.
	*/
	void handleUpdateCake();

	/*
	Handles user input for deleting cakes.
	*/
	void handleDeleteCake();

	/*
	Handles user input for displaying ingredients avg.
	*/
	void handleDisplayAvg();
public:
	UserInterface(); // Blank constructor
	UserInterface(const Service& service); // Parameterized constructor.
	~UserInterface(); // Destructor
	void startLoop(); // Starts UI loop
};

