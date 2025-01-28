// ../src/Secretary/secretary.cpp

#include "secretary.hpp"

// *****************************************************************************************************************************************************
// Constructors and Destructors

Secretary::Secretary() {
    mandatoryYearsOfStudy = 0;
    coursePoints = 0;
}

Secretary::~Secretary() {
    for(auto person : professors)
        delete person;
    
    for (auto person : students)
        delete person;

    for (auto course : courses)
        delete course;
    
    professors.clear();
    students.clear();
    courses.clear();
}


Secretary::Secretary(const Secretary& other) {
    for (const auto& person : other.students) {
        students.push_back(new Student(*person));
    }

    for (const auto& person : other.professors) {
        professors.push_back(new Professor(*person));
    }

    for(const auto& course : other.courses)
        courses.push_back(new Course(*course));
}

// *****************************************************************************************************************************************************
// Overloading + and = operators functions

Secretary Secretary::operator+(Student* student) {
    students.push_back(new Student(*student));
    return *this;
}

Secretary Secretary::operator+(Professor* professor) {
    professors.push_back(new Professor(*professor));
    return *this;
}

Secretary Secretary::operator+(Course* course) {
    courses.push_back(new Course(*course));
    return *this;
}

Secretary Secretary::operator=(const Secretary& other) {
    if (this != &other) {
        // Clear existing students
        for (auto person : students) {
            delete person;
        }
        students.clear();

        // Copy new students
        for (const auto& person : other.students) {
            students.push_back(new Student(*person));
        }
    
        for (auto person : professors) {
            delete person;
        }
        professors.clear();

        // Copy new students
        for (const auto& person : other.professors) {
            professors.push_back(new Professor(*person));
        }

        for (auto course : courses) {
            delete course;
        }
        courses.clear();

        // Copy new students
        for (const auto& course : other.courses) {
            courses.push_back(new Course(*course));
        }
    }

    return *this;
}

// *****************************************************************************************************************************************************
// Functions used to find an element

bool Secretary::personFound(cstring& am, cstring role) const {
    if (role == "Professor") {
        for (const auto& person : professors) {
            if (am == person->getAM())
                return true;
        }
    } 
    else if (role == "Student") {
        for (const auto& person : students) {
            if (am == person->getAM())
                return true;
        }
    }

    return false;
}

bool Secretary::courseFound(cstring& courseName) const {
    for (const auto& course : courses) {
        if (courseName == course->getCourseName())
            return true;
    }

    return false;
}

// *****************************************************************************************************************************************************
// Access Functions

Student* Secretary::studentAccess(cstring& am) const {
    for (const auto& person : students) {
        if (am == person->getAM())
            return person; // Return the pointer to the found person
    }

    return nullptr; // Return nullptr if not found
}

Professor* Secretary::profAccess(cstring& am) const {
    for (const auto& person : professors) {
        if (am == person->getAM())
            return person;
    }

    return nullptr;
}

Course* Secretary::courseAccess(cstring& courseToFind) const {
    for (const auto& course : courses) {
        if (courseToFind == course->getCourseName())
            return course;
    }

    return nullptr;
}

// *****************************************************************************************************************************************************
// Get Functions

std::vector<Professor*> Secretary::getProfessors() const {return professors;}

std::vector<Student*> Secretary::getStudents() const {return students;}

std::vector<Course*> Secretary::getCourses() const {return courses;}

int Secretary::getSemester() const {return this->semester;}

int Secretary::getMandatoryYearsOfStudy() const {return mandatoryYearsOfStudy;}

int Secretary::getCoursePoints() const {return coursePoints;}

std::string Secretary::getElementType() const {return elementType;}

string Secretary::getExamPeriod() const {return examPeriod;}

// *****************************************************************************************************************************************************
// Set Functions

void Secretary::setSemester(cint& semester) {this->semester = semester;}

void Secretary::setMandatoryYearsOfStudy(cint mandatoryYearsOfStudy) {this->mandatoryYearsOfStudy = mandatoryYearsOfStudy;}

void Secretary::setCoursePoints(cint coursePoints) {this->coursePoints = coursePoints;}

void Secretary::setElementType(cstring elementType) {this->elementType = elementType;} 

void Secretary::setExamPeriod(cstring examPeriod) {this->examPeriod = examPeriod;}

// *****************************************************************************************************************************************************
// Overloading input and output operators functions


std::ostream &operator<<(std::ostream& str, const Secretary& secretary) {
    if (secretary.getElementType() == "Professor") {
        for (const auto person : secretary.getProfessors())
            str << *person << '\n';
    }
    else if (secretary.getElementType() == "Student") {
        for (const auto person : secretary.getStudents())
            str << *person << '\n';       
    }
    else if (secretary.getElementType() == "Course") {
        for (const auto course : secretary.getCourses())
            str << *course << '\n';
    }
        
    return str;
}

std::istream &operator>>(std::istream& str, Secretary& secretary) {
    std::cout << "----------------------------------------------\n";
    std::cout << "Graduation Information:\n";
    std::cout << "Years of attendace needed: ";
    str >> secretary.mandatoryYearsOfStudy;
    std::cout << "Course points needed: ";
    str >> secretary.coursePoints;

    return str;
}

// *****************************************************************************************************************************************************
// Delete Functions

bool Secretary::deleteProf(Professor* prof) {
    auto it = find(professors.begin(), professors.end(), prof);
    if (it != professors.end()) {
        professors.erase(it);
        return true;
    }
    
    return false;
}

bool Secretary::deleteStudent(Student* student) {
    auto it = find(students.begin(), students.end(), student);
    if (it != students.end()) {
        students.erase(it);
        return true;
    }
    
    return false;
}

bool Secretary::deleteCourse(Course* course) {
    auto it = find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it);
        return true;
    }
    
    return false;
}

// *****************************************************************************************************************************************************

void Secretary::printProfsAssgned(Secretary* secretary, Course* course) {
    for (const auto& regNumberOfProfessor : course->getProfessorsAssigned()) {
        if (secretary->personFound(regNumberOfProfessor, "Professor")) {
            Professor* prof = secretary->profAccess(regNumberOfProfessor);
            std::cout << prof;
        }
    }
}