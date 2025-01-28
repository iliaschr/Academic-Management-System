// ../src/Professor/professor.hpp
#pragma once 

#include <vector>

#include "../Person/person.hpp"

// Forward Declaration
class Course;
class Student;

class Professor : public Person {
    public:
        // Constructors 
        Professor();
        Professor(cstring& name, cstring& surname,
        cstring& phoneNumber, cstring& am,
        cint& age);

        Professor(const Professor& other);  // Copy constructor
        Professor& operator=(const Professor& other);
        
        ~Professor();   // Destructor

        // Function that assigns a course to the professor
        void assignCourse(cstring courseName);

        // Function used to enter a grade to a student by the professor
        void enterGrade(Student* student, Course* course, cdouble& grade);

        void printCoursesTaught();

        std::vector<string> getCoursesTaught() const;
    private:
        std::vector<string> coursesTaught;
};