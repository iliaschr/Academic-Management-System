// ../src/Menu/menu.cpp

#include "menu.hpp"

namespace Menu {
    char modifyPersonMenu(int choice, Person* person, std::string role) 
    {
        clearConsole();
        printPersonMenu(role);
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter new information for the person:\n";
                std::cin >> *person;  // Use overloaded operator>> for Person
                std::cout << "Updated information for the person:\n" << *person;
                break;
            }
            case 2: {
                clearStdin();

                std::string name;
                std::cout << "Enter New Name: ";
                std::getline(std::cin , name);
                person->setName(name);
                break;
            }
            case 3: {
                std::string surname;
                std::cout << "Enter New Surname: ";
                std::getline(std::cin , surname);
                person->setSurname(surname);
                break;
            }
            case 4: {
                int age;
                std::cout << "Enter New Age: ";
                std::cin >> age;
                person->setAge(age);
                break;
            }
            case 5: {
                std::string phone;
                std::cout << "Enter New Phone Number: ";
                std::getline(std::cin , phone);
                person->setPhoneNumber(phone);
                break;
            }
            case 6: {
                std::string AM;
                std::cout << "Enter New Registration Number: ";
                std::getline(std::cin , AM);
                person->setAM(AM);
                break;
            }
            case 7: {
                if (role == "Professor")
                    std::cout << "Exiting modify menu. Returning to the main menu.\n";
                else {
                // if its not a professor then it breaks the case and returns choice 
                // so that we can modify the years of attendance of the student.
                // This is needed because we cannot modify the years through person.
                    return 7;
                }

                break;
            }
            case 8: {
                // if role == student then we go back to the main menu
                // if the role is professor then it goes to the default case and prints the error,
                // thats why there is no need for break outside the if state
                if (role == "Student") {
                    std::cout << "Exiting modify menu. Returning to the main menu.\n";
                    break;
                }
            }
            default:
                std::cerr << "Invalid choice. Please enter a number between 1 and 7.\n";
        }

        return choice;
    }

    char modifyCourseMenu(int choice, Course* course) 
    {
        clearConsole();
        printCourseMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter new information for the course:\n";
                std::cin >> *course;
                std::cout << "Update information for the course:\n" << *course;

                break;
            case 2: {
                clearStdin();

                std::string courseName;
                std::cout << "Enter course name: ";
                std::getline(std::cin, courseName);
                course->setCourseName(courseName);

                break;
            }
            case 3: {
                clearStdin();

                int coursePoints;
                std::cout << "Enter course points: ";
                std::cin >> coursePoints;
                course->setCoursePoints(coursePoints);

                break;
            }
            case 4: {
                clearStdin();

                std::string courseType;
                std::cout << "Enter course type: ";
                if (courseType == "Mandatory")
                    course->setCourseType(Type::Mandatory);
                else
                    course->setCourseType(Type::Elective);
                

                break;
            }
            case 5: {
                clearStdin();

                int semester;
                std::cout << "Enter semester: ";
                std::cin >> semester;
                course->setSemester(semester);

                break;
            }
            case 6: 
                std::cout << "Exiting modify menu. Returning to the main menu.\n";
                break;
            default:
                std::cerr << "Invalid choice. Please enter a number between 1 and 6.\n";
        }

        return choice;
    }

    void courseModifyMenu(Secretary& secretary) 
    {
        std::string courseToFind;
        if (searchCourse(&secretary, courseToFind)) {
            Course* course = secretary.courseAccess(courseToFind);
            std::cout << *course;

            int modifyChoice;
            std::cout << "What do you want to modify?\n";
            int choice;
            while (true) {
                choice = modifyCourseMenu(choice, course);
                if (choice == 6)
                    break;
            }
        }
    }

    void editProf (Secretary& secretary) 
    {
        // Getting a registration number to search for the professor that the secretary
        // wants to modify
        std::string registrationNumberToFind;
        if (searchPerson(&secretary, "Professor", registrationNumberToFind)) {
            int choice;
            Professor* prof = secretary.profAccess(registrationNumberToFind);
            std::cout << *prof;

            int modifyChoice;
            std::cout << "What do you want to modify?\n";
            while (true) {
                choice = modifyPersonMenu(modifyChoice, prof, "Professor");
                if (choice == 7)
                    break;
            }
        }
    }
    
    void editStudent(Secretary& secretary) 
    {
        // Getting a registration number to search for the professor that the secretary
        // wants to modify
        std::string registrationNumberToFind;
        if (searchPerson(&secretary, "Student", registrationNumberToFind)) {
            Student* student = secretary.studentAccess(registrationNumberToFind);
            std::cout << *student;

            int modifyChoice;
            std::cout << "What do you want to modify?\n";
            int choice;
            while (true) {
                choice = modifyPersonMenu(modifyChoice, student, "Student");
                if (choice == 7) {
                    int years;
                    std::cout << "Enter new Years of Attendance: ";
                    std::cin >> years;
                    student->setYearsOfAttendace(years);
                }
                else if (choice == 8)
                    break;
            }
        }
    }

    int semesterMenu() 
    {
        clearConsole();
        std::cout << "Set Semester\n"
            << "What's the semester? (Enter the corresponding number)\n"
            << "1. Winter Semester\n"
            << "2. Spring Semester\n";

        int semester;
        do {
            std::cout << "Enter the number of the desired semester: ";
            std::cin >> semester;
            if (!Utilities::semesterCheck(semester)) {
                std::cerr << "Invalid semester number. Please enter a valid number. (1 <= semester <= 5)" << std::endl;
            }
        } while (!Utilities::semesterCheck(semester));
        return semester;
    }

    void mainMenu(Secretary secretary, int choice) 
    {
        bool dontExitProgram = true;

        std::cin >> secretary;

        secretary.setSemester(semesterMenu());

        while (dontExitProgram) {
            printMainMenu();

            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                int answer;

                // (1) Professors
                case 1: {
                    switch (choiceMenu1()) {
                        // 1) Add professor
                        case 1: {
                            addChoiceProf(secretary);
                            break;
                        }

                        // 2) Edit
                        case 2: {
                            clearStdin();
                            editProf(secretary);
                            break;
                        }

                        // 3) Remove
                        case 3: {
                            clearStdin();
                            removeProf(secretary);
                            break;
                        }

                        // 4) Print 
                        case 4: {
                            secretary.setElementType("Professor");
                            std::cout << secretary;
                            break;
                        }

                        // 5) Go back
                        case 5: {
                            break;
                        }

                        default:
                            std::cerr << "Invalid choice. Please enter a number between 1 and 5.\n";
                            break;
                    }

                    break;
                }

                // (2) Students
                case 2: {
                    switch (choiceMenu2()) {
                        // Add Student
                        case 1:{
                            addChoiceStudent(secretary);
                            break;
                        }

                        // Edit
                        case 2: {
                            clearStdin();
                            editStudent(secretary);
                            break;
                        }

                        // Remove 
                        case 3: {
                            clearStdin();
                            removeStudent(secretary);
                            break;
                        }

                        // Print 
                        case 4: {
                            secretary.setElementType("Student");
                            std::cout << secretary;
                            break;
                        }

                        // Return to main menu
                        case 5: {
                            break;
                        }

                        

                        default:
                            std::cerr << "Invalid choice. Please enter a number between 1 and 4.\n";
                            break;

                    }

                    break;
                }

                // (3) Courses
                case 3: {               
                    switch (choiceMenu3()) {
                        // Add Course
                        case 1:{
                            addChoiceCourse(secretary);
                            break;
                        }

                        // Edit
                        case 2: {
                            clearStdin();
                            courseModifyMenu(secretary);
                            break;
                        }

                        // Remove
                        case 3: {
                            clearStdin();
                            removeCourse(secretary);
                            break;
                        }

                        // Print courses
                        case 4: {
                            secretary.setElementType("Course");
                            std::cout << secretary;
                            break;
                        }

                        // Go back
                        case 5: 
                            break;

                        default:
                            std::cerr << "Invalid choice. Please enter a number between 1 and 4.\n";
                            break;
                    }

                    break;
                }

                // (4) Assign Professor(s) to a course
                case 4: {
                    clearStdin();
                    assignAProfessor(secretary);
                    break;
                }

                // (5) Enroll a student to a course
                case 5: {
                    clearStdin();
                    studentEnroll(secretary);
                    break;
                }

                // (6) Print and save to file the students that passed a course
                case 6: {
                    examPeriodCheck(&secretary);
                    clearStdin();           
                    saveStudentsPassed(secretary);
                    break;
                }

                // (7) Print a professor's stats for all of his courses
                case 7: {
                    clearStdin();
                    profStats(secretary);
                    break;
                }

                // (8) Print a student's grades for a specific semester or for all the semesters
                case 8: {
                    clearStdin();                    
                    studentsGrade(secretary);
                    break;
                }
                    
                // (9) Print the students that can graduate
                case 9: {
                    graduateStudents(secretary);
                    break;
                }

                case 10: {
                    changeSemester(secretary);
                    break;
                }

                // (11) Exit the program
                case 11: {
                    std::cout << "Exiting the program. Goodbye!\n";
                    dontExitProgram = false;
                    break;
                }
            }
        }       
    }
}
