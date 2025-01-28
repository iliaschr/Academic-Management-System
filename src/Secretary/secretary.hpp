// ../src/Secretary/secretary.hpp
#pragma once

#include <algorithm>

#include "../Student/student.hpp"
#include "../Professor/professor.hpp"
#include "../Course/course.hpp"

class Secretary {
    public:
        Secretary();    // Constructor
        ~Secretary();   // Destructor
        
        Secretary(const Secretary& other); // Copy Constructor

        // Overloading + and = operators
        Secretary operator+(Student* student);
        Secretary operator+(Professor* professor);
        Secretary operator+(Course* course);

        Secretary operator=(const Secretary& other);

        // Functions used to find each element
        bool personFound(cstring& am, cstring role) const;
        bool courseFound(cstring& courseName) const;

        // Funtions that return an element in each case, so that we can modify it etc
        Professor* profAccess(cstring& am) const;
        Student* studentAccess(cstring& am) const;
        Course* courseAccess(cstring& courseToFind) const;

        // Get Functions
        std::vector<Professor*> getProfessors() const;
        std::vector<Student*> getStudents() const;
        std::vector<Course*> getCourses() const;
        int getSemester() const;
        int getMandatoryYearsOfStudy() const;
        int getCoursePoints() const;
        std::string getElementType() const;
        string getExamPeriod() const;

        // Set Functions
        void setSemester(cint& semester);
        void setMandatoryYearsOfStudy(cint mandatoryYearsOfStudy);
        void setCoursePoints(cint coursePoints);
        void setElementType(const std::string elementType);
        void setExamPeriod(cstring examPeriod);

        // Overloading output and input operators
        friend std::ostream &operator<<(std::ostream& str, const Secretary& secretary);
        friend std::istream &operator>>(std::istream& str, Secretary& secretary);

        // Functions used to delete elements from the vectors
        bool deleteProf(Professor* prof);
        bool deleteStudent(Student* student);
        bool deleteCourse(Course* course);

        // print
        void printProfsAssgned(Secretary* secretary, Course* course);

    private:
        std::vector<Student*> students;
        std::vector<Professor*> professors;
        std::vector<Course*> courses; 

        int semester;  // it stores the current semester
        int mandatoryYearsOfStudy;  // it stores the mandatory years of study to graduate
        int coursePoints;       // it stores the course points needed to graduate

        std::string elementType;    // variiable used in friend std::ostream &operator<<

        string examPeriod;
};