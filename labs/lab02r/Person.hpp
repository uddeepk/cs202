//
// Created by uddeepk on 1/21/21.
//

#ifndef LAB01R_PERSON_HPP
#define LAB01R_PERSON_HPP

#include <string>

class Person {
public:
    Person();
    Person(const Person &per);
    Person(std::string const &str);
    ~Person(); //destructor

    std::string getName() const;
private:
    const std::string _name;
};
void passByValue (Person per);
void displayNameFiveTimes (Person &per); //passes by reference
Person combineTwoNames ( const Person &per1, const Person &per2); //returns Person

#endif //LAB01R_PERSON_HPP
