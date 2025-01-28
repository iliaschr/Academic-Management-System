#pragma once

#include <string>
#include <cctype>
#include <iostream>
#include "../Variables/common_types.h"

namespace Utilities {
    bool isNumberString(cstring& str, bool phoneNumber);
    bool isLetterString(cstring& str);
    bool ageCheck(int age);
    bool semesterCheck(int semester);
}