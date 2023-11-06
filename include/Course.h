#pragma once

#include <vector>
#include <string>

#include "../include/Student.h"

class Course
{
public:
    std::vector<Student> students;
    std::string name;
	Course();
	~Course();
};

