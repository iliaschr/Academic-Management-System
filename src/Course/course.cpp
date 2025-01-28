// ../src/Course/course.cpp
#include "course.hpp"

class Secretary;    // Forward Declaration

// *****************************************************************************************************************************************************
// Constructors and Destructors

Course::Course() {}

Course::Course(cstring& courseName, cint& coursePoints,
            const Type& courseType, cint& semester) 
            : courseName(courseName), coursePoints(coursePoints),
            courseType(courseType), semester(semester) {}

Course::Course(const Course& other) {
   // Copy non-pointer members
    this->courseName = other.courseName;
    this->coursePoints = other.coursePoints;
    this->courseType = other.courseType;
    this->semester = other.semester;
    this->mainProfessor = other.mainProfessor;

    // Deep copy for the professorsAssigned vector
    this->professorsAssigned.clear();
    for (const auto& professor : other.professorsAssigned) {
        this->professorsAssigned.push_back(professor);
    }
}

Course::~Course() {}

// *****************************************************************************************************************************************************
// Set Functions

void Course::setCourseName(cstring& courseName) {this->courseName = courseName;}

void Course::setCoursePoints(cint& coursePoints) {this->coursePoints = coursePoints;}

void Course::setCourseType(const Type& courseType) {this->courseType = courseType;}

void Course::setSemester(cint& semester) {this->semester = semester;}

void Course::setMainProfessor(cstring& mainProfessor) {this->mainProfessor = mainProfessor;}

// *****************************************************************************************************************************************************
// Get Functions

string Course::getCourseName() const {return courseName;}

int Course::getCoursePoints() const {return coursePoints;}

string Course::getCourseType() const {
    switch (courseType) {
        case Type::Mandatory:
            return "Mandatory";
        case Type::Elective:
            return "Elective";
        default:
            return "Unknown course type";
    }    
}

int Course::getSemester() const {return semester;}

std::vector<string> Course::getProfessorsAssigned() const {return professorsAssigned;}

string Course::getMainProfessor() const {return mainProfessor;}

// *****************************************************************************************************************************************************

void Course::assignProfessor(const std::string registrationNumber) {professorsAssigned.push_back(registrationNumber);}

void Course::changeSemester(cint& semester) {this->semester = semester;}

// *****************************************************************************************************************************************************
// Friend Functions

std::istream& operator>>(std::istream& str, Course& course) {
    str.clear();
    str.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Course Name: ";
    getline(str, course.courseName);

    std::cout << "Enter Course Points: ";
    std::cin >> course.coursePoints;

    str.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string typeOfCourse;
    std::cout << "Enter Course Type: ";
    getline(str, typeOfCourse);
    if (typeOfCourse == "Mandatory")
        course.courseType = Type::Mandatory;
    else 
        course.courseType = Type::Elective;

    std::cout << "Enter the Semester the Course is on: ";
    std::cin >> course.semester;

    return str;
}

std::ostream& operator<<(std::ostream& str, const Course& course) {
    str << "Course Name: " << course.courseName << '\n';
    str << "Course Points: " << course.coursePoints << '\n';
    str << "Course Type: " << course.getCourseType() << '\n';
    str << "Semester: " << course.semester << '\n';

    return str;
}