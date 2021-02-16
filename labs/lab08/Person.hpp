//
// Created by uddeepk on 1/21/21.
//

#ifndef LAB01R_PERSON_HPP
#define LAB01R_PERSON_HPP

#include <string>

class Person {
    friend std::ostream& operator<<(std::ostream &os, const Person &p) ;
    friend Person operator+( const Person &person1, const Person &person2);
public:
    Person();
    Person(const Person &per);
    Person(std::string const &str);
    ~Person(); //destructor

//    Person operator+(  const Person &person2); // LOok at note, only global variables better in this case.

    std::string getName() const;
    static int getInstances()  {return _instances;}
private:
    const std::string _name;
    static int _instances ;
};
void passByValue (Person per);
void displayNameFiveTimes (Person &per); //passes by reference
Person combineTwoNames ( const Person &per1, const Person &per2); //returns Person

#endif //LAB01R_PERSON_HPP
