#include "../include/Teacher.h"
#include <iostream>

Teacher::Teacher()
{
}

Teacher::~Teacher()
{
}

void Teacher::init(const std::string& name, const int& age)
{
	Person::init(name, age);
}

void Teacher::printInfo()
{
	std::cout << "Teacher name: " << getName() << " Age: " << getAge() << std::endl;
}
