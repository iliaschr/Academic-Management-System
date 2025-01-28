// ../src/Professor/professor.cpp

#include "professor.hpp"
#include "../Course/course.hpp"
#include "../Student/student.hpp"

// *****************************************************************************************************************************************************
// Constructors and Destructors

Professor::Professor() {}

Professor::Professor(cstring& name, cstring& surname,
        cstring& phoneNumber, cstring& am,
        cint& age) : Person(name, surname, phoneNumber, am, age) {}

Professor::Professor(const Professor& other) : Person(other) {coursesTaught = other.coursesTaught;}

Professor& Professor::operator=(const Professor& other) {
    if (this != &other) {
        Person::operator=(other);

        coursesTaught = other.coursesTaught;
    }

    return *this;
}

Professor::~Professor() {}

// *****************************************************************************************************************************************************

void Professor::assignCourse(cstring courseName) {coursesTaught.push_back(courseName);}

void Professor::enterGrade(Student* student, Course* course, cdouble& grade) {
    bool courseFound = false;

    for (cstring& i : student->getCourses())  {
        if (i == course->getCourseName()) {
            student->addGrade(grade, course->getCourseName());
            courseFound = true;
            break;
        }
    }

    if (!courseFound)
        std::cout << "Error! Could not find this course...\n";
}

void Professor::printCoursesTaught() {
    std::cout << "Professor " 
              << getName() << " " 
              << getSurname() << ", " 
              << getAM() << ", assigned courses:\n"; 
    
    for (cstring& i : coursesTaught) 
        std::cout << i << "\t\t";

    std::cout << '\n';
}

std::vector<string> Professor::getCoursesTaught() const {return coursesTaught;}