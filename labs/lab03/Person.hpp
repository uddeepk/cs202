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
    void setName (std::string newName);
    std::string getName() const;
private:
    std::string _name;
};

#endif //LAB01R_PERSON_HPP
