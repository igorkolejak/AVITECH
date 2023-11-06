#include "../include/Student.h"
#include <iostream>
#include <string>

Student::Student():
    _is_classroomNumber_set(false)
{
}

Student::~Student()
{
}

void Student::init(const std::string& name, const int& age, const int& ClassroomNumber)
{
	Person::init(name, age);
	classroomNumber = ClassroomNumber;
	_is_classroomNumber_set = true;

}

void Student::printInfo()
{
	std::cout << "Name: " << getName() << " Age: " << getAge();

	if(_is_classroomNumber_set)
    {
        std::cout << " Classroom: " << classroomNumber;
    }

    std::cout << std::endl;
}
