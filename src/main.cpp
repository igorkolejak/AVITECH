#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>

#include "../include/Student.h"
#include "../include/School.h"

void zadanie_1()
{
    School school;

    Student student;
    student.init("Jozko Mrkvicka", 18, 1);
    school.addStudent(student);

    Student student2;
    student2.init("Palko Mrkvicka", 19, 2);
    school.addStudent(student2);
    school.assignStudentToNewClassroom(student2, 5);

    Person* palkoStudentPtr = school.getStudent(0);
    palkoStudentPtr->printInfo();

    Student student3;
    student3.init("Janka Mrkvickova", 20, 3);
    school.addStudent(student3);
}

void process_file(const char* path)
{
    School school;

    school.addCourse("biology");
    school.addCourse("history");
    school.addCourse("sport");

    std::ifstream input_file;
    input_file.open(path);
    if(input_file.is_open())
    {
        std::string line;
        while(std::getline(input_file, line))
        {
            int pos = 0;
            int line_size = line.size();

            std::string name;
            int age = 0;
            std::string section;
            std::string interest;

            pos = line.find_first_of(' ');
            name = line.substr(0, pos);

            line = line.substr(pos+1, line_size-(pos+1));
            pos = line.find_first_of(' ');
            std::stringstream ss;
            ss << line.substr(0, pos);
            ss >> age;

            line = line.substr(pos+1, line_size-(pos+1));
            pos = line.find_first_of(' ');
            section = line.substr(0, pos);

            if(pos != -1)
            {
                line = line.substr(pos+1, line_size-(+1));
                interest = line;
            }

            if(section.compare("student") == 0)
            {
                Student student;
                student.init(name, age, 1);
                school.addStudent(student);


                if(interest.size() > 0)
                {
                    student.interest = interest;
                    school.addStudentToCourse(student);
                }
            }
            else if(section.compare("teacher") == 0)
            {
                Teacher teacher;
                teacher.init(name, age);
                school.addTeacher(teacher);
            }


        }
    }

    std::cout << "All Persons:\n";
    for( Person p : school.getAll() )
    {
        p.printInfo();
    }

    std::cout << "Students in biology course:\n";
    for (Student s : school.getCourseStudents("biology"))
    {
        s.printInfo();
    }
    input_file.close();
}

int main(int argc, char** argv)
{
    SetConsoleOutputCP( CP_UTF8 );

    if (argc < 2)
    {
        zadanie_1();
    }
    else if (argc == 2)
    {
        process_file(argv[1]);
    }
    else
    {
        std::cout << "ERROR: Too many arguments. Cancel processing." << std::endl;
        return 1;
    }
	system("pause");
	return 0;
}
