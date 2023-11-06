#pragma once

#include "Person.h"

class Teacher : public Person
{
public:
	Teacher();
	~Teacher();

	virtual void init(const std::string& name, const int& age);

	virtual void printInfo();
};

