#include <iostream>
#include <vector>
#include "Header.h"
#include <limits>

using namespace std;

int main() {

    cout << "What would you like to do?\n\n";
    cout << "1. Solve a factorial n!\n";
    cout << "2. Solve 3rd degree polynomial equations. \n";
    cout << "3. Simple math equatitions on two terms\n";

    validateIntInput();
    //Asks for another number if the number does not correspond to one of the given options.
    while (input1 < 0 || input1 >= 4) {
        cout << "Please choose a valid option: ";
        validateIntInput();
    }

    int result;
    switch (input1) {
    case 1:
        cout << "Decide the factorial: ";
        validateIntInput();
        result = factorial(input1);
        cout << result;
        break;
    case 2:
        polynomialMenu();
        break;
    case 3:
        simpleCalculator();
        break;

    }
    return 0;
}
