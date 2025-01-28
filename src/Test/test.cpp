#include "../Func/func.hpp"
#include <stdlib.h>
#include "acutest.h"
#include <vector>

using namespace std;
/*
Testing mostly student functions since it's the same as Professor and Course's functions.
Testing Add, Edit, Remove, Find, Assign, Enroll, Passed
*/
void test_add(void)
{
  Student std1("Ilias", "Chrysogelos", "0000000000", "1115202200217", 20);
  Student std2("Emmanouil", "Antonopoulos", "6971111111", "1115202200007", 19);
  
  Secretary secr;
  
  secr = secr + &std1;
  secr = secr + &std2;

  TEST_ASSERT(std1.getName() == "Ilias");
  TEST_ASSERT(std1.getSurname() == "Chrysogelos");
  TEST_ASSERT(std1.getPhoneNumber() == "0000000000");
  TEST_ASSERT(std1.getAM() == "1115202200217");
  TEST_ASSERT(std1.getAge() == 20);

  TEST_ASSERT(!(std2.getName() == "Ilias"));
  TEST_ASSERT(!(std2.getSurname() == "Chrysogelos"));
  TEST_ASSERT(!(std2.getPhoneNumber() == "0000000000"));
  TEST_ASSERT(!(std2.getAM() == "1115202200217"));
  TEST_ASSERT(!(std2.getAge() == 20));

  vector<Student*> students = secr.getStudents();

  // Check if the vector contains the correct number of students
  TEST_ASSERT(students.size() == 2);

  // Test attributes of the first student
  TEST_ASSERT(students[0]->getName() == "Ilias");
  TEST_ASSERT(students[0]->getSurname() == "Chrysogelos");
  TEST_ASSERT(students[0]->getPhoneNumber() == "0000000000");
  TEST_ASSERT(students[0]->getAM() == "1115202200217");
  TEST_ASSERT(students[0]->getAge() == 20);

  // Test attributes of the second student
  TEST_ASSERT(students[1]->getName() == "Emmanouil");
  TEST_ASSERT(students[1]->getSurname() == "Antonopoulos");
  TEST_ASSERT(students[1]->getPhoneNumber() == "6971111111");
  TEST_ASSERT(students[1]->getAM() == "1115202200007");
  TEST_ASSERT(students[1]->getAge() == 19);
}

void test_edit(void) 
{
  Student std1("Ilias", "Chrysogelos", "0000000000", "1115202200217", 20);
  Student std2("Emmanouil", "Antonopoulos", "6971111111", "1115202200007", 19);
  
  std1.setAge(19);
  std2.setAge(20);

  TEST_ASSERT(std1.getAge() == 19);
  TEST_ASSERT(std2.getAge() == 20);
}

void test_remove(void) {
  Student std1("Emmanouil", "Antonopoulos", "6971111111", "1115202200007", 19);

  Secretary secr;
  secr = secr + &std1;

  vector<Student*> students = secr.getStudents();
  TEST_ASSERT(students.size() == 1);
  secr.deleteStudent(students[0]);

  students = secr.getStudents();
  TEST_ASSERT(students.size() == 0);
}

void test_assign(void) 
{
  Professor prof1("Professor", "One", "0000000000", "0000000000123", 62);
  Course c1("Linear Algebra", 6, Type::Mandatory, 1);

  c1.assignProfessor("0000000000123");
 
  vector<string> assignedProfessor = c1.getProfessorsAssigned();
  TEST_ASSERT(assignedProfessor.size() == 1);
  TEST_ASSERT(assignedProfessor[0] == "0000000000123");
  
}

void test_enroll(void) 
{
  Course c1("Linear Algebra", 6, Type::Mandatory, 1);
  Student std1("Ilias", "Chrysogelos", "0000000000", "1115202200217", 20);
  std1.addCourse(&c1, 1);
  vector<string> courses = std1.getCourses();
  TEST_ASSERT(courses.size() == 1);
  TEST_ASSERT(courses[0] == "Linear Algebra");
}

void test_passed(void)
{
  Course c1("Linear Algebra", 6, Type::Mandatory, 1);
  Student std1("Ilias", "Chrysogelos", "0000000000", "1115202200217", 20);
  Professor prof1("Professor", "One", "0000000000", "0000000000123", 62);
  
  c1.assignProfessor("0000000000123");
  
  std1.addCourse(&c1, 1);
  
  prof1.enterGrade(&std1, &c1, 10);

  TEST_ASSERT(std1.getGradeInCourse(&std1, "Linear Algebra") == 10);
  
  Secretary secr;
  
  secr = secr + &std1;
  secr = secr + &c1;
  secr = secr + &prof1;

  vector<Student*> students = secr.getStudents();
  secr.setCoursePoints(5);
  std1.setYearsOfAttendace(5);
  secr.setMandatoryYearsOfStudy(4);

  TEST_ASSERT((std1.getCoursePoints() >= secr.getCoursePoints()) 
        && (std1.getYearsOfAttendace() >= secr.getMandatoryYearsOfStudy()));
}

TEST_LIST = {
  {"test_add", test_add},
  {"test_edit", test_edit},
  {"test_remove", test_remove},
  {"test_assign", test_assign},
  {"test_enroll", test_enroll},
  {"test_passed", test_passed},
  {NULL, NULL}
};
