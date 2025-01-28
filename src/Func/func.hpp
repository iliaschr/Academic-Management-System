// ../src/Func/func.hpp
#pragma once

#include <cstdlib>
#include <fstream>

#include "../Secretary/secretary.hpp"

class Secretary;

// Function that prints the main menu
void printMainMenu();

// Function that prints the menu for the Person elements
void printPersonMenu(std::string role);

// Function that prints the menu for the Course elementes
void printCourseMenu();

// Fucntion that clears the stdin
void clearStdin();

// Function that clears the console
void clearConsole();

// Function that searches for a Person element (Professor or Student) in the secretary department
bool searchPerson(Secretary* secretary, std::string role, std::string& registrationNumberToFind);

// Function that searches for a course in the secretary department
bool searchCourse(Secretary* secretary, std::string& courseToFind);

// Function that checks the exam period
void examPeriodCheck(Secretary* secretary);

// Function that print the choice menu for the professors and returns the answer
int choiceMenu1();

// Function that print the choice menu for the students and returns the answer
int choiceMenu2();

// Function that print the choice menu for the courses and returns the answer
int choiceMenu3();

// Function that auto adds professor elements to the secretary department
void autoAddProf (Secretary& secretary);

// Function that auto adds student elements to the secretary department
void autoAddStudent(Secretary& secretary);

// Function that auto adds courses elements to the secretary department
void autoAddCourse(Secretary& secretary);

// Function that adds professor manualy to the secretary department
void addProfessor(Secretary& secretary);

// Function that adds student manualy to the secretary department
void addStudent(Secretary& secretary);

// Function that adds course manualy to the secretary department
void addCourse(Secretary& secretary);

// Function that makes you choose if you want to add automatically or manually professor elment
void addChoiceProf(Secretary& secretary);

// Function that makes you choose if you want to add automatically or manually student element
void addChoiceStudent(Secretary& secretary);

// Function that makes you choose if you want to add automatically or manually course element
void addChoiceCourse(Secretary& secretary);

// Function that removes a professor from secretary department
void removeProf(Secretary& secretary);

// Function that removes a professor from secretary department
void removeStudent(Secretary& secretary);

// Function that removes a course from secretary department
void removeCourse(Secretary& secretary);

// Function that print the stats of a professor
void profStats(Secretary& secretary);

// Function that prints a students grades for a specific semester 
// or for all the semesters
void studentsGrade(Secretary& secretary);

// Function that prints the students that can graduate
void graduateStudents(Secretary& secretary);

// Function that changes the semester
void changeSemester(Secretary& secretary);

// Function used to assign a professor to course,
// it uses the assignProfessor function from course.hpp
void assignAProfessor(Secretary& secretary);

// Function used to enroll a student to a course
void studentEnroll(Secretary& secretary);

// Function used to save the students that passed a specific course to the file
// studentsThatPassed.txt
void saveStudentsPassed(Secretary& secretary);