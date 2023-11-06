#pragma once

#include <string>

class Person
{
private:
	std::string _name;
	int _age;

public:
	Person();
	~Person();

	virtual void init(const std::string& name, const int& age);

	virtual std::string getName();
	virtual int getAge();

	virtual void printInfo();
};

