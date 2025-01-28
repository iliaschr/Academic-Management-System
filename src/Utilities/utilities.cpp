#include "utilities.hpp"

namespace Utilities {
    bool isNumberString(cstring& str, bool phoneNumber) {
        if (phoneNumber) {
            for (auto c : str) {
                if (!std::isdigit(c) || str.length() != 10)
                    return false;
            }
        }
        else {
            for (auto c : str) {
                if (!std::isdigit(c) || str.length() != 13)
                    return false;
            }
        }

        return true;
    }

    bool isLetterString(cstring& str) {
        int count = 0;
        
        for (char c : str) {
            if (count == 0 || count == str.length() - 1) {
                if (c == '-')
                    return false;
            }

            if (!std::isalpha(c) && c != '-') 
                return false;
        
            count++;
        }

        return true;
    }

    bool ageCheck(int age) {
        return (age >= 17 && age <= 100);
    }

    bool semesterCheck(int semester){
        if (semester < 1 || semester > 3)
            return false;
            
        return true;
    }
}
