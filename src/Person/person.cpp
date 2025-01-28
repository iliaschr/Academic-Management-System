// ../src/Person/person.hpp

#include "person.hpp"

int Person::count = 0;

// *****************************************************************************************************************************************************
// Constructors and Destructors

Person::Person(): name(" "), surname(" "), age(0) , phoneNumber(" "), am(" ") {
    count++;
}

Person::Person(cstring& name, cstring& surname, cstring& phoneNumber, cstring& am, cint& age)
    :   name(name), surname(surname), age(age), phoneNumber(phoneNumber), am(am) {
    count++;
}

Person::~Person() {
    count--;
}

// *****************************************************************************************************************************************************
// Set Functions

void Person::setName(cstring& name) {
    if (Utilities::isLetterString(name)) {
        this->name = name;
    } 
    else {
        std::cerr << "Invalid name. Please enter a valid letter string." << std::endl;
    }
}

void Person::setSurname(cstring& surname) {
    if (Utilities::isLetterString(surname)) {
        this->surname = surname;
    } 
    else {
        std::cerr << "Invalid surname. Please enter a valid letter string." << std::endl;
    }
}

void Person::setAge(cint& age) {
    if (Utilities::ageCheck(age)) {
        this->age = age;
    }
    else {
        std::cerr << "Invalid age number. Please enter a valid age number (17 <= age <= 100)." << std::endl;
    }
}

void Person::setPhoneNumber(cstring& phoneNumber) {
    if (Utilities::isNumberString(phoneNumber, true)) {
        this->phoneNumber = phoneNumber;
    } 
    else {
        std::cerr << "Invalid phone number. Please enter a valid number string. (Size 10)" << std::endl;
    }
}


void Person::setAM(cstring& am) {
    if (Utilities::isNumberString(am, false)) {
        this->am = am;
    } 
    else {
        std::cerr << "Invalid registration number. Please enter a valid number string. (Size 13)" << std::endl;
    }
}

// *****************************************************************************************************************************************************
// Get Functions

string Person::getName() const {
    return name;
}

string Person::getSurname() const {
    return surname;
}

int Person::getAge() const {
    return age;
}

string Person::getPhoneNumber() const {
    return phoneNumber;
}

string Person::getAM() const {
    return am;
}

int Person::getCount() const {
    return count;
}

// *****************************************************************************************************************************************************
// Friend Functions

std::ostream &operator<<(std::ostream& str, const Person &person) {
    str << "Name: " << person.getName() << '\n';
    str << "Surname: " << person.getSurname() << '\n';
    str << "Age: " << person.getAge()<< '\n';
    str << "Phone Number (Size 10): " << person.getPhoneNumber() << '\n';
    str << "Registration Number (Size 13): " << person.getAM() << '\n';

    return str;
}

std::istream &operator>>(std::istream& str, Person &person) {
    do {
        std::cout << "Enter Name: ";
        // Discarding newline characters
        str.clear(); 
        str.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        getline(str, person.name);
        if (!Utilities::isLetterString(person.name)) {
            std::cerr << "Invalid name.\nIn case the person has two names you must use \"-\"(for example Hlias-Emmanouil). Please enter a valid name string." << std::endl;
        }
    } while (!Utilities::isLetterString(person.name));

    do {
        std::cout << "Enter Surname: ";
        getline(str, person.surname);
        if (!Utilities::isLetterString(person.surname)) {
            std::cerr << "Invalid surname.\nIn case the person has two names you must use \"-\"(for example Hlias-Emmanouil). Please enter a valid letter string." << std::endl;
        }
    } while (!Utilities::isLetterString(person.surname));

    do {
        str.clear(); 

        std::cout << "Enter Age: ";
        str >> person.age;
        if (!Utilities::ageCheck(person.age)) {
            std::cerr << "Invalid age number. Please enter a valid age number (17 <= age <= 100)." << std::endl;
        }
    } while (!Utilities::ageCheck(person.age));

    str.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Enter Phone Number: ";
        getline(str, person.phoneNumber);
        if (!Utilities::isNumberString(person.phoneNumber, true)) {
            std::cerr << "Invalid phone number. Please enter a valid number string. (Size 10)" << std::endl;
        }
    } while (!Utilities::isNumberString(person.phoneNumber, true));

    do {
        str.clear(); 

        std::cout << "Enter Registration Number: ";
        getline(str, person.am);
        if (!Utilities::isNumberString(person.am, false)) {
            std::cerr << "Invalid registration number. Please enter a valid number string. (Size 13)" << std::endl;
        }
    } while (!Utilities::isNumberString(person.am, false));

    return str;
}
