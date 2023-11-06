#include "School.h"

School::School()
{
}

School::~School()
{
}

void School::assignStudentToNewClassroom(Student student, int newClassroomNumber)
{
	student.classroomNumber = newClassroomNumber;
}

void School::addStudentToCourse(Student student)
{
    for(Course *c : _courses)
    {
        if(c->name == student.interest)
        {
            c->students.push_back(student);
        }
    }
}

void School::addStudent(Student& student)
{
    _students.push_back(student);
}

void School::addTeacher(Teacher& teacher)
{
    _teachers.push_back(teacher);
}

void School::addCourse(const char* name)
{
    Course* course = new Course;
    course->name = name;
    _courses.push_back(course);
}

std::vector<Person> School::getAll()
{
    std::vector<Person> result;
    for(Student s : _students)
    {
        result.push_back(s);
    }

    for(Teacher t : _teachers)
    {
        result.push_back(t);
    }
	return result;
}

Student* School::getStudent(const std::size_t& index)
{
	return &_students[index];
}

Teacher* School::getTeacher(const std::size_t& index)
{
	return &_teachers[index];
}


std::vector<Student> School::getCourseStudents(std::string name)
{
    for(Course *c : _courses)
    {
        if(c->name == name)
        {
            for(Student s : c->students)
            {
                s.printInfo();
            }
            return c->students;
        }
    }
}
