//Uddeep Karki
//CS202 UAF
//Jan 14, 2021
//WAP and use if/else, a function call , switch, while, do while, for(normal), for(range based)

#include <iostream>
#include <vector>

int getSquare (const int&);


int main() {
    std::cout << "Hello, World!" << std::endl;
    int inputNumber;

    if (std::cin>>inputNumber && inputNumber > 0 ) { //Maybe use getline to make bombproof code.
        // Using switch for even or odd
        switch ( inputNumber % 2 ) {
            case 1:
                std::cout << inputNumber << " is odd " << std::endl;
                break;
            default: // case even
                std::cout <<inputNumber << " is even. " << std::endl;
                break;
        }

        // Get squre of number through function call
        std::cout << "The square of " << inputNumber << " is " << getSquare(inputNumber) << std::endl;

        // while loop to input number from that inputNumber to 1 inclusive

        std::vector <int> vecInt; //declaring empty vector of integers

        while ( inputNumber > 0 ) {
            // This loop pushes the number from 1, to inputNumber into the vecInt in the reverse order.
            vecInt.push_back(inputNumber);
            --inputNumber;
        }

        std::cout << "The numbers from " << inputNumber << " to 1 in reverse order " ;
        // for loop range based. that displays the numbers in the vector
        for ( const auto &i : vecInt ) {
            std:: cout << i << " " ;
        }
        std::cout << std::endl;

        int beginningNumber = *vecInt.begin(); // will get back the number
        //Could use vector front member function i.e beginningNumber = vecInt.front();

        //We know that there is atleast 1 number because of the if statement and
        //So I am using do while loop

        std::cout << "The squares of the number starting from the " << beginningNumber << " to 1 inclusive :";
        do {
            std::cout << getSquare(beginningNumber)<< " "; //Prints the squares
            --beginningNumber;
        } while (beginningNumber > 0);
        std::cout << std::endl;
        // for loop (normal) using iterators

        std::cout << "The 2* multiplse of the number in the vector in the reverse order : " ;
        for ( auto it = vecInt.rbegin() ; it != vecInt.rend() ; ++it ) {
            std:: cout << 2 * (*it) << " ";
        }
        std::cout << std::endl;
    }
    else
        std:: cout << "Enter valid number that is greater than 0 " << std::endl;
    return 0;
}

int getSquare ( const int &number) {
    return number * number;
}
