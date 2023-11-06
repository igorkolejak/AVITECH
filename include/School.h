#pragma once

#include <vector>

#include "Student.h"
#include "Teacher.h"
#include "Course.h"

class School
{
private:
	std::vector<Course *> _courses;
	std::vector<Student> _students;
	std::vector<Teacher> _teachers;
public:
	School();
	~School();

	void assignStudentToNewClassroom(Student student, int newClassroomNumber);

	void addStudentToCourse(Student student);

    void addStudent(Student& student);
    void addTeacher(Teacher& teacher);
    void addCourse(const char* name);

    Student* getStudent(const std::size_t& index);
    Teacher* getTeacher(const std::size_t& index);
    std::vector<Student> getCourseStudents(std::string name);

    std::vector<Person> getAll();
};

