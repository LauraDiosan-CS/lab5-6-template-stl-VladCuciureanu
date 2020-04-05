#pragma once
class Entity
{
protected:
	unsigned int entityId;
public:
	Entity();
	Entity(unsigned int id);
	Entity(const Entity& e);
	virtual ~Entity();
	virtual unsigned int getId();
	virtual void setId(unsigned int id);
};