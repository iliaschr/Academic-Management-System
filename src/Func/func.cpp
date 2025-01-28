// ../src/Func/func.cpp

#include "func.hpp"

// *****************************************************************************************************************************************************
// Print functions

void printMainMenu() {
    std::cout << "----------------------------------------------\n";
    std::cout << "Menu:\n";
    std::cout << "1) Professors\n";
    std::cout << "2) Students\n";
    std::cout << "3) Courses\n";
    std::cout << "4) Assign Professor(s) to a course.\n";
    std::cout << "5) Enroll a Student to a course.\n";
    std::cout << "6) Get the Students that passed a specific course.\n";
    std::cout << "7) Get a teacher's statistics for all of their courses in a specific semester.\n";
    std::cout << "8) Get a student's grades.\n";
    std::cout << "9) Print the students that can graduate.\n";
    std::cout << "10) Change semester.\n";
    std::cout << "11) Exit.\n";
}

void printPersonMenu(std::string role) {
    std::cout << "\nModify Person Menu:\n";
    std::cout << "1. Change Everything\n";
    std::cout << "2. Change Name\n";
    std::cout << "3. Change Surname\n";
    std::cout << "4. Change Age\n";
    std::cout << "5. Change Phone Number\n";
    std::cout << "6. Change AM\n";

    if (role == "Professor") {
        std::cout << "7. Exit to main menu\n";
        std::cout << "Enter your choice (1-7): ";
    }
    else {
        std::cout << "7. Change Years of Attendance\n";
        std::cout << "8. Exit to main menu\n";
        std::cout << "Enter your choice (1-8): "; 
    }
}

void printCourseMenu() {
    std::cout << "\nModify Course Menu:\n";
    std::cout << "1. Change Everything\n";
    std::cout << "2. Change Name\n";
    std::cout << "3. Change Course Points\n";
    std::cout << "4. Change Course Type\n";
    std::cout << "5. Change Semester of the Course\n";
    std::cout << "6. Exit to main menu\n";
    std::cout << "Enter your choice (1-6): ";
}

// *****************************************************************************************************************************************************
// Clear functions

void clearStdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// *****************************************************************************************************************************************************
// Search functions

bool searchPerson(Secretary* secretary, std::string role, std::string& registrationNumberToFind) {
    std::cout << "Enter a registration number to search for: ";
    std::getline(std::cin, registrationNumberToFind);
    if (secretary->personFound(registrationNumberToFind, role)) {
        std::cout << registrationNumberToFind << " found!\n";
        return true;
    }
    
    std::cout << role << " with registration number: " << registrationNumberToFind << " not found.\n";
    return false;
}

bool searchCourse(Secretary* secretary, std::string& courseToFind) {
    std::cout << "Enter the name of the course to search for: ";
    std::getline(std::cin, courseToFind);
    if (secretary->courseFound(courseToFind)) {
        std::cout << courseToFind << " found.\n";
        return true;
    }

    std::cout << courseToFind << " was not found.\n";
    return false;
}

// *****************************************************************************************************************************************************
// Check Function

void examPeriodCheck(Secretary* secretary) {
    clearConsole();
    switch(secretary->getSemester()) {
        case 1: {   // Winter Semester -> Winter Exam Period
            std::cout << "Courses of the Winter Semester:\n";
            for (const auto course : secretary->getCourses()) {
                if (course->getSemester() % 2 == 1)
                    std::cout << *course << '\n';
            } 
            
            break;
        }
        case 2: {   // Spring Semester -> Spring Exam Period
            std::cout << "Courses of the Spring Semester:\n";
            for (const auto course : secretary->getCourses()) {
                if (course->getSemester() % 2 == 0)
                    std::cout << *course << '\n';
            } 

            break;
        }
        case 3: {   // September Exam Period
            std::cout << "All the Courses:\n";
            for (const auto course : secretary->getCourses()) 
                std::cout << *course << '\n';
            
            break;
        }
        default: {
            break;
        }
    }  
}

// *****************************************************************************************************************************************************
// Choice menu funtions

int choiceMenu1() 
{	
	int answer;
	clearConsole();
	std::cout <<"----------------------------------------------\n";
	std::cout << "1) Add Professor\n";
	std::cout << "2) Edit Professor\n";
	std::cout << "3) Remove Professor\n";
	std::cout << "4) Print professors\n";
	std::cout << "5) Go Back\n";

	std::cout << "Enter choice: ";
	std::cin >> answer;
	std::cout <<"----------------------------------------------\n";
	return answer;
}

int choiceMenu2() 
{
	int answer;
	clearConsole();
	std::cout <<"----------------------------------------------\n";
    std::cout << "*NOTE: The years the student has attended classes are automatically initialized with 0, to change them you need to \"Menu -> 2) Students -> 2) Edit -> 7) Change Years of Attendance\"*\n";
    std::cout << "1) Add Student\n";
	std::cout << "2) Edit Student\n";
	std::cout << "3) Remove Student\n";
	std::cout << "4) Print Students\n";
	std::cout << "5) Go back\n";

	std::cout << "Enter choice: ";
	std::cin >> answer;
	std::cout <<"----------------------------------------------\n";
	return answer;
}

int choiceMenu3()
{
	clearConsole();
	int answer;
	std::cout <<"----------------------------------------------\n";
	std::cout << "1) Add Course\n";
	std::cout << "2) Edit Course\n";
	std::cout << "3) Remove Course\n";
	std::cout << "4) Print Courses\n";
	std::cout << "5) Go back\n";

	std::cout << "Enter choice: ";
	std::cin >> answer;
	std::cout <<"----------------------------------------------\n";
	return answer;
}

// *****************************************************************************************************************************************************
// Auto add Functions

void autoAddProf (Secretary& secretary) 
{
    Professor prof1("Professor", "One", "0000000000", "0000000000123", 62);
    Professor prof2("Professor", "Two", "1111111111", "1111111111000", 54);

    // Add the new prof to the Secretary's Department
    secretary = secretary + &prof1;
    secretary = secretary + &prof2;

    std::cout << "\nProfessor added to the department:\n" << prof1;
    std::cout << "\nProfessor added to the department:\n" << prof2;
}

void autoAddStudent(Secretary& secretary) 
{
    Student std1("Ilias", "Chrysogelos", "6970000000", "1115202200217", 20);
    Student std2("Emmanouil", "Antonopoulos", "6971111111", "1115202200007", 19);

    secretary = secretary + &std1;
    secretary = secretary + &std2;

    std::cout << "\nStudent added to the Secretary's Department:\n" << std1 << '\n';
    std::cout << "\nStudent added to the Secretary's Department:\n" << std2 << '\n';

}

void autoAddCourse(Secretary& secretary) 
{
    Course c1("Linear Algebra", 6, Type::Mandatory, 1);
    Course c2("Calculus 1", 5, Type::Mandatory, 2);
    Course c3("Circuit Lab", 2, Type::Elective, 3);

    secretary = secretary + &c1;
    secretary = secretary + &c2;
    secretary = secretary + &c3;

    std::cout << "\nCourse added to the Secretary's Department:\n" << c1 << '\n';
    std::cout << "\nCourse added to the Secretary's Department:\n" << c2 << '\n';
    std::cout << "\nCourse added to the Secretary's Department:\n" << c3 << '\n';
}

// *****************************************************************************************************************************************************
// Add Functions

void addProfessor(Secretary& secretary) 
{
    Professor newProfessor;
    std::cout << "Enter information for the new professor:\n";
    std::cin >> newProfessor;

    secretary = secretary + &newProfessor;

    std::cout << "\nProfessor added to the Secretary's Department:\n" << newProfessor << "\n";
}

void addStudent(Secretary& secretary) 
{
    Student newStudent;
    std::cout << "Enter information for the new student:\n";
    std::cin >> newStudent;

    secretary = secretary + &newStudent;

    std::cout << "\nStudent added to the Secretary's Department:\n" << newStudent << "\n";
}

void addCourse(Secretary& secretary) 
{
    Course newCourse;
    std::cout << "Enter information for the new course:\n";
    std::cin >> newCourse;

    secretary = secretary + &newCourse;

    std::cout << "\nCourse added to the Secretary's Department:\n" << newCourse << '\n';
}

void addChoiceProf(Secretary& secretary)
{
    int choice;
    do {
        try {
            std::cout << "Automatically add a professor (1) or Add your own professor (2): ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            if (choice == 1) {
                autoAddProf(secretary);
            } else if (choice == 2) {
                addProfessor(secretary);
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << e.what() << "\n";
        }

    } while (choice != 1 && choice != 2);
}

void addChoiceStudent(Secretary& secretary)
{
    int choice;
    do {
        try {
            std::cout << "Automatically add a student(1) or Add your own student (2): ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            if (choice == 1) {
                autoAddStudent(secretary);
            } else if (choice == 2) {
                addStudent(secretary);
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << e.what() << "\n";
        }

    } while (choice != 1 && choice != 2);
}

void addChoiceCourse(Secretary& secretary)
{
    int choice;
    do {
        try {
            std::cout << "Automatically add a course (1) or Add your own course (2): ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            if (choice == 1) {
                autoAddCourse(secretary);
            } else if (choice == 2) {
                addCourse(secretary);
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << e.what() << "\n";
        }

    } while (choice != 1 && choice != 2);
}

// *****************************************************************************************************************************************************
// Remove Functions

void removeProf(Secretary& secretary) 
{
    // Getting a registration number to search for the professror that the secretary
    // wants to remove
    std::string registrationNumberToFind;
    if (searchPerson(&secretary, "Professor", registrationNumberToFind)) {
        Professor* prof = secretary.profAccess(registrationNumberToFind);
        std::cout << *prof;

        char deleteChoice;
        std::cin.clear();
        std::cout << "Are you sure you want to delete this professor? [Y/n]: "; 
        std::cin >> deleteChoice;
        if (deleteChoice == 'Y' || deleteChoice == 'y') {
            if (secretary.deleteProf(prof))
                std::cout << "Professor Removed\n\n";
            else 
                std::cout << "Error Removing the professor...\n\n";
        }

        delete prof;
    }
}

void removeStudent(Secretary& secretary) 
{
    // Getting a registration number to search for the professror that the secretary
    // wants to remove
    std::string registrationNumberToFind;
    if (searchPerson(&secretary, "Student", registrationNumberToFind)) {
        Student* student = secretary.studentAccess(registrationNumberToFind);
        std::cout << *student;

        char deleteChoice;
        std::cin.clear();
        std::cout << "Are you sure you want to delete this professor? [Y/n]: "; 
        std::cin >> deleteChoice;
        if (deleteChoice == 'Y' || deleteChoice == 'y') {
            if (secretary.deleteStudent(student))
                std::cout << "Professor Removed\n\n";
            else 
                std::cout << "Error Removing the professor...\n\n";
        }

        delete student;
    }
}

void removeCourse(Secretary& secretary) 
{
    std::string courseToFind;
    if (searchCourse(&secretary, courseToFind)) {
        Course* course = secretary.courseAccess(courseToFind);
        std::cout << *course;

        char deleteChoice;
        std::cin.clear();
        std::cout << "Are you sure you want to delete this course? [Y/n]: "; 
        std::cin >> deleteChoice;
        if (deleteChoice == 'Y' || deleteChoice == 'y') {
            if (secretary.deleteCourse(course))
                std::cout << "Course Removed\n\n";
            else 
                std::cout << "Error Removing the course...\n\n";
        }   

        delete course;  
    }
}

// *****************************************************************************************************************************************************

void profStats(Secretary& secretary) 
{
    // Getting a registration number to search for the professor thet the 
    // secretary wants to modify
    std::string registrationNumberToFind;
    if (searchPerson(&secretary, "Professor", registrationNumberToFind)) {
        Professor* prof = secretary.profAccess(registrationNumberToFind);
        std::cout << *prof;

        for (const auto& course : prof->getCoursesTaught()) {
            int countOfStudentsTested = 0;
            double sumOfGrades = 0;

            for (auto& student : secretary.getStudents()) {
                double prevSumOfGrades = sumOfGrades;

                double grade = student->getGradeInCourse(student, course);
                sumOfGrades += grade;
            
                if (sumOfGrades != prevSumOfGrades)
                    countOfStudentsTested++;
            }

            std::cout << "Average Grade in " << course << ": " << sumOfGrades / countOfStudentsTested << "\n\n";
        }
    }
}

void studentsGrade(Secretary& secretary) 
{
    // Getting a registration number to search for the professor that the secretary
    // wants to modify
    std::string registrationNumberToFind;
    if (searchPerson(&secretary, "Student", registrationNumberToFind)) {
        Student* student = secretary.studentAccess(registrationNumberToFind);
        std::cout << *student;

        int semester;
        do {
            try {
                std::cout << "Get grades for 1) Winter Semesters, 2) Spring Semesters, 3) All the Semesters ";
                std::cin >> semester;

                if (semester < 1 || semester > 3) 
                    throw std::out_of_range("Invalid semester choice. Please enter a number between 1 and 3.");
            } 
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } while (semester < 1 || semester > 3);

        if (semester == 1) {
            for (const auto& courseName : student->getCourses()) {
                Course* course = secretary.courseAccess(courseName);
                if (course->getSemester() % 2 == 1) 
                    std::cout << "Course: " << course->getCourseName() << ", Grade: " << student->getGradeInCourse(student, course->getCourseName()) << '\n';
            }
        }
        else if (semester == 2) {
            for (const auto& courseName : student->getCourses()) {
                Course* course = secretary.courseAccess(courseName);
                if (course->getSemester() % 2 == 0) 
                    std::cout << "Course: " << course->getCourseName() << ", Grade: " << student->getGradeInCourse(student, course->getCourseName()) << '\n';
            }
        }
        else {
            for (const auto& courseName : student->getCourses()) {
                Course* course = secretary.courseAccess(courseName);
                std::cout << "Course: " << course->getCourseName() << ", Grade: " << student->getGradeInCourse(student, course->getCourseName()) << '\n';
            }
        }
    }
}

void graduateStudents(Secretary& secretary) 
{
    clearConsole();
    std::cout << "Students that can graduate:\n";
    for (const auto student : secretary.getStudents()) {
        if ((student->getCoursePoints() >= secretary.getCoursePoints()) 
        && (student->getYearsOfAttendace() >= secretary.getMandatoryYearsOfStudy())) {
            std::cout << *student;
        }
    }
}

void changeSemester(Secretary& secretary)
{
    clearConsole();
    int semester;
    std::cout << "Semesters: (1) Winter, (2) Spring, (3) None(September examination)\n";
    std::cout << "Enter the semester you want: ";
    std::cin >> semester;
    while (!Utilities::semesterCheck(semester)) {
        std::cerr << "Input error. Semester can be either (1) Winter, (2) Spring, (3) None(September examination): ";
        std::cin >> semester;
    }
    
    secretary.setSemester(semester);
    std::cout << "The semester now is: " << secretary.getSemester() << "\n";
}

void assignAProfessor(Secretary& secretary)
{
    std::string courseToFind;
    if (searchCourse(&secretary, courseToFind)) {
        Course* course = secretary.courseAccess(courseToFind);
        std::cout << *course;

        std::cin.clear();

        std::string registrationNumberToFind;
        if (searchPerson(&secretary, "Professor", registrationNumberToFind)) {
            Professor* prof = secretary.profAccess(registrationNumberToFind);
            std::cout << *prof;

            course->assignProfessor(prof->getName());
            prof->assignCourse(course->getCourseName());

            std::cout << "Professor: " << prof->getSurname() << " " << prof->getName() << ", " << prof->getAM() << "- assigned to course: " << course->getCourseName() << ".\n\n";                     
        }

        secretary.printProfsAssgned(&secretary, course);
    }
}

void studentEnroll(Secretary& secretary) 
{
    std::string courseToFind;
    if (searchCourse(&secretary, courseToFind)) {
        Course* course = secretary.courseAccess(courseToFind);
        std::cout << *course;

        std::cin.clear();

        std::string registrationNumberToFind;
        if (searchPerson(&secretary, "Student", registrationNumberToFind)) {
            Student* student = secretary.studentAccess(registrationNumberToFind);
            std::cout << *student;

            student->addCourse(course, secretary.getSemester());
            std::cout << "Student -" << student->getSurname() << " " << student->getName() << ", " << student->getAM() << "- enrolled to course: " << course->getCourseName() << ".\n\n";
        }
    }
}

void saveStudentsPassed(Secretary& secretary)
{
    std::string courseToFind;
    if (searchCourse(&secretary, courseToFind)) {
        Course* course = secretary.courseAccess(courseToFind);
        
        Professor* prof = secretary.profAccess(course->getMainProfessor());
        
        std::ofstream outputFile("studentsPassed.txt"); // Save Secretary's information to a text file
        if (outputFile.is_open())
            outputFile << "Course: " << course->getCourseName() << '\n';

        std::cout << "Students that passed " << courseToFind << ": \n";
        for (auto& student : secretary.getStudents()) {
            for (auto& courseTaken : student->getCourses()) {

                if (course->getCourseName() == courseTaken) {
                    // TODO: check for clearstdin and use util to check grade
                    double grade;
                    while (true) {
                        std::cout << "Enter grade for " << student->getSurname() << " - " << student->getAM() << " in " << course->getCourseName() << ": ";
                        std::cin >> grade;

                        if (std::cin.fail()) {
                            // Input is not a valid double
                            std::cin.clear(); // Clear the error flag
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                            std::cerr << "Invalid input. Please enter a valid grade." << std::endl;
                        } else {
                            // Input is valid
                            break;
                        }
                    }

                    prof->enterGrade(student, course, grade);

                    if (grade >= 5) {
                        std::cout << *student;

                        if (outputFile.is_open())
                            outputFile << *student;
                    }

                    break;
                }
            }

        }

        outputFile.close();
    }
}