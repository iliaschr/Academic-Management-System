// include/student.hpp

#pragma once

#include <vector>

#include "../Person/person.hpp"
#include "../Course/course.hpp"
#include "../Func/func.hpp"

class Student : public Person {
    public:
        // Constructors
        Student();
        Student(cstring& name, cstring& surname,
        cstring& phoneNumber, cstring& am,
        cint& age);

        Student(const Student& other);  // Copy constructor

        // Destructor
        ~Student();

        // Functions that add an element to the vectors
        void addCourse(Course* course, cint semester);
        void addGrade(cdouble& grade, cstring course);

        // Print Functions
        void printCourses();
        void printGrades();
        void printStatus();

        // Get Functions
        std::vector<string> getCourses() const;
        std::vector<double> getGrades() const;
        double getGradeInCourse(Student* student, string courseToFind);
        int getYearsOfAttendace() const;
        int getCoursePoints() const;

        // Set Functions
        void setYearsOfAttendace(cint yearsOfAttendace);
        void setCoursePoints(cint sumOfCoursePoints);

    private:
        std::vector<string> courses;    // courses the student is studying
        std::vector<int> coursePoints;  // the points for every course taken
        std::vector<double> grades;     // the grades of the student in each course

        int yearsOfAttendace;
        int sumOfCoursePoints;
};