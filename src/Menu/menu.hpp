// ../src/Menu/menu.hpp
#pragma once

#include <fstream>

#include "../Func/func.hpp"

namespace Menu {
    char modifyPersonMenu(int choice, Person* person);
    
    char modifyCourseMenu(int choice, Course* course);
    
    int semesterMenu();

    void mainMenu(Secretary secretary, int choice);
}
