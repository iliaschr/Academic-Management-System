// ../src/Student/student.cpp

#include "student.hpp"

// *****************************************************************************************************************************************************
// Constructors and Destructors

Student::Student() {
    yearsOfAttendace = 0;
    sumOfCoursePoints = 0;
}

Student:: Student(cstring& name, cstring& surname,
    cstring& phoneNumber, cstring& am,
    cint& age) : Person(name, surname, phoneNumber, am, age) 
    {
        yearsOfAttendace = 0;
        sumOfCoursePoints = 0;    
    }

Student::Student(const Student& other) : Person(other) {
    // Deep copy for the vectors
    this->courses.clear();
    for (const auto& course : other.courses) 
        this->courses.push_back(course);

    this->grades.clear();
    for (const auto& grade : other.grades) 
        this->grades.push_back(grade);
    
    this->coursePoints.clear();
    for (const auto& cp : other.coursePoints)
        this->coursePoints.push_back(cp);
}

Student::~Student() {}

// *****************************************************************************************************************************************************
// Add Functions

void Student::addCourse(Course* course, cint semester) {
    if (semester % 2 == course->getSemester() % 2) {
        courses.push_back(course->getCourseName());
        coursePoints.push_back(course->getCoursePoints());
        grades.push_back(0);
    }
    else 
        std::cerr << "The semester of the course " << course->getCourseName() << " doesn't match with the current semester.\n";
}

void Student::addGrade(cdouble& grade, cstring course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    
    int index;
    if (it != courses.end())
        index = std::distance(courses.begin(), it);
    else 
        std::cerr << "Error!\n";

    grades[index] = grade;

    if (grade >= 5)
        sumOfCoursePoints += coursePoints[index];
}

// *****************************************************************************************************************************************************
// Print Functions

void Student::printCourses() {
    for (cstring& i : courses)
        std::cout << i << " ";

    std::cout << "\n\n";
}

void Student::printGrades() {
    for (cdouble& i : grades)
        std::cout << i << " ";

    std::cout << "\n\n";
}

void Student::printStatus() {
    std::cout << "Student " 
              << getName() << " " 
              << getSurname() << ", "
              << getAM() << ", " 
              << "grades:\n";
    
    for (int i = 0 ; i < courses.size(); i++)
        std::cout << courses[i] << ": " << grades[i] << '\n';

    std::cout << "\n\n";
}

// Get Functions

std::vector<string> Student::getCourses() const {return courses;}

std::vector<double> Student::getGrades() const {return grades;}

double Student::getGradeInCourse(Student* student, string courseToFind) {
    int i = 0;
    for (const auto& course : student->getCourses()) {
        if (course == courseToFind) {
            return grades[i];
        }  

        i++;
    }

    return 0;   // in case the course is not found
}

int Student::getYearsOfAttendace() const {return yearsOfAttendace;}

int Student::getCoursePoints() const {return sumOfCoursePoints;}

// *****************************************************************************************************************************************************
// Set Functions

void Student::setYearsOfAttendace(cint yearsOfAttendace) {this->yearsOfAttendace = yearsOfAttendace;}

void Student::setCoursePoints(cint sumOfCoursePoints) {this->sumOfCoursePoints = sumOfCoursePoints;}