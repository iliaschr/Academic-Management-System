// ../src/Person/person.hpp
#pragma once

#include <ostream>
#include <limits>

#include "../Utilities/utilities.hpp"

using std::string;

class Person {
    public:
        // Constructors
        Person(); 
        Person(cstring& name, cstring& surname, cstring& phoneNumber, cstring& am, cint& age);
        
        ~Person(); // Destructors

        // Set Functions
        void setName(cstring& name);
        void setSurname(cstring& surname);
        void setAge(cint& age);
        void setPhoneNumber(cstring& phoneNumber);
        void setAM(cstring& am);

        // Get Functions
        string getName() const;
        string getSurname() const;
        int getAge() const;
        string getPhoneNumber() const;
        string getAM() const;
        int getCount() const;

        // Overloading output & input operators
        friend std::ostream &operator<<(std::ostream& str, const Person& person);
        friend std::istream &operator>>(std::istream& str, Person& person);

    private:
        string name;
        string surname;
        int age;
        string phoneNumber;
        string am;          // Registration Number
        static int count;   // Counts objects
};