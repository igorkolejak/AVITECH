#include <iostream>

#include "Person.h"

Person::Person()
{
}

Person::~Person()
{
}

void Person::init(const std::string& name, const int& age)
{
	_name = name;
	_age = age;
}

std::string Person::getName()
{
	return _name;
}

int Person::getAge()
{
	return _age;
}

void Person::printInfo()
{
	std::cout << "Name: " << _name << " Age: " << _age << std::endl;
}
