// ../src/Course/course.hpp
#pragma once

#include "../Professor/professor.hpp"

using std::string;

enum class Type {
    Mandatory,
    Elective
};

class Course {
    public:
        // Constructors
        Course();
        Course(cstring& courseName, cint& coursePoints,
            const Type& courseType, cint& semester);

        Course(const Course& other);    // Copy Constructor

        ~Course();  // Destructor

        // Set functions
        void setCourseName(cstring& courseName);
        void setCoursePoints(cint& coursePoints);
        void setCourseType(const Type& courseType);
        void setSemester(cint& semester);
        void setMainProfessor(cstring& mainProfessor);

        // Get Functions
        string getCourseName() const;
        int getCoursePoints() const;
        string getCourseType() const;
        int getSemester() const;
        std::vector<string> getProfessorsAssigned() const;
        string getMainProfessor() const;

        // Function that assigns a professor to the course
        void assignProfessor(cstring registrationNumber);    

        // Function that changes the semester of the course
        void changeSemester(cint& semester);

        // Friend Functions
        friend std::istream& operator>>(std::istream& str, Course& course);
        friend std::ostream& operator<<(std::ostream& str, const Course& course);

    private:
        string courseName;
        int coursePoints;
        Type courseType;
        int semester;

        // in case 1 or more profs are assigned
        // it stores the registration numbers of the professors assigned
        std::vector<string> professorsAssigned; 

        // The main professor of the course
        // He/she is also the professor that enters the grade 
        std::string mainProfessor;

};