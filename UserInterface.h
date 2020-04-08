#pragma once
#include "Service.h"
#include <string>
#include <iostream>

class UserInterface
{
private:
	Service service;
	bool exitTrigger = false;
	void handleAddCake();
	void handleDisplayCakes();
	void handleUpdateCake();
	void handleDeleteCake();
public:
	UserInterface();
	UserInterface(const Service& service);
	~UserInterface();
	void startLoop();
};

