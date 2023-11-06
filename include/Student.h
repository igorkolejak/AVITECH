#pragma once

#include "Person.h"

class Student : public Person
{
private:
    bool _is_classroomNumber_set;

public:
	int classroomNumber;
	std::string interest;

	Student();
	~Student();

	virtual void init(const std::string& name, const int& age, const int& ClassroomNumber);

	virtual void printInfo();
};

