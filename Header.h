#pragma once
#include <limits>
using namespace std;

int mathArray1[4] = { 0,0,0,0 };
int mathArray2[4] = { 0,0,0,0 };
int intInput = 0;

///<summary>
///This function checks if the cinput is an integer, clears the cinput and asks to retype it if not an integer.
///Using this means you will use validateInput(); and intInput as your integer to check for valid input. 
///This approach needs of the limits library.
///</summary>
void validateIntInput() {
	cin >> intInput;
	while (!cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter a valid number.";
		cin >> intInput;
	}
}
///<summary>
///This function asks the user to fill out the two different arrays and multiplies each array and puts the result into multiplyArray
///Prints out the multiplyArray array with proper exponents
///</summary>
void multiplyArrays() {

	//7 is the max length of two functions with 3 polynomials multiplied together
	int multiplyArray[7] = { 0,0,0,0,0,0,0 };
	int product = 0;

	//The next two for-loops asks the user for the 4 numbers for the two arrays of polynomials.
	for (int i = 0; i < 4; i++) {
		cout << "Decide the number n * (x)^" << 3 - i << " ";
		validateIntInput();
		mathArray1[i] = intInput;

	}
	cout << "Second function.\n\n";
	for (int i = 0; i < 4; i++) {
		cout << "Decide the number n * (x)^" << 3 - i << " ";
		validateIntInput();
		mathArray2[i] = intInput;

	}
	//multiplies each value of the first array with each value of the second array and adds the result into the multiplyArray position of the appropriate polynomial
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			product = mathArray1[i] * mathArray2[j];
			multiplyArray[j + i] += product;
		}

	}
	//Prints the results of the multiplication with a specific exception for the last 2 values which does not have a polynomial higher than 1
	cout << "The result is:\n";
	for (int i = 0; i < 5; i++) {
		cout << multiplyArray[i] << "x^" << 6 - i << " + ";
	}
	cout << multiplyArray[5] << "x + ";
	cout << multiplyArray[6];
}

/// <summary>
/// Asks the user for two functions with 3 polynomials, adds them together and prints the result.
/// </summary>
void addArrays() {
	int additionArray[4] = { 0,0,0,0 };
	//next two for loops asks the user for the numbers for the two arrays of polynomials.
	for (int i = 0; i < 4; i++) {
		cout << "Decide the number n * (x)^" << 3 - i << " ";
		validateIntInput();
		mathArray1[i] = intInput;
	}
	cout << "Second function.\n\n";
	for (int i = 0; i < 4; i++) {
		cout << "Decide the number n * (x)^" << 3 - i << " ";
		validateIntInput();
		mathArray2[i] = intInput;
	}
	//adds the two mathArrays and their result into the additionArray
	for (int i = 0; i < 4; i++) {
		additionArray[i] = mathArray1[i] + mathArray2[i];
	}
	//prints out the addition result with an exception for the last value which does not have an x or a polynomial higher than 1
	for (int i = 0; i < 3; i++) {
		cout << additionArray[i] << "x^" << 3 - i << " + ";
	}
	cout << additionArray[3];
}

/// <summary>
/// Asks the user for a function with 3 polynomials and derivates it, printing out the result.
/// </summary>
void derivateArrays() {
	int derivationArray[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++) {
		cout << "Decide the number n * (x)^" << 3 - i << " ";
		validateIntInput();
		mathArray1[i] = intInput;
		derivationArray[i] = (mathArray1[i] * (3 - i));
	}
	//written seperately as they all want to show seperate things
	cout << derivationArray[0] << "x^2 + ";
	cout << derivationArray[1] << "x + ";
	cout << derivationArray[2];

}

/// <summary>
/// When called with an integer "n" higher than 0, calculates the value "n!" and returns it.
/// If called with an integer lower than 0, asks the user for one higher than 0.
/// </summary>
/// <param name="n"></param>
/// <returns>factorial</returns>
int factorial(int n) {
	int result;

	while (n <= 0) {
		cout << "Choose a whole number higher than 0: ";
		validateIntInput();
		n = intInput;
	}
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		result = n * factorial(n - 1);
	}
	return result;
}

/// <summary>
/// Clears the console.
/// Polynomial math with 3rd degree polynomials, addition, derivation and multiplication.
/// Calls either addArray(); derivateArray(); or multiplyArrays(); depending on user choice.
/// </summary>
void polynomialMenu() {
	system("cls");
	cout << "What would you like to do?\n\n";
	cout << "1. Add two functions with 3 polynomials together\n";
	cout << "2. Derivate a polynomial\n";
	cout << "3. Decide and multiply 2 f unctions with 3 polynomials\n";

	validateIntInput();
	while (intInput < 1 || intInput >= 4) {
		cout << "Please choose a valid option: ";
		validateIntInput();
	}
	switch (intInput) {
	case 1:
		addArrays();
		break;
	case 2:
		derivateArrays();
		break;
	case 3:
		multiplyArrays();
		break;
	}
}

/// <summary>
/// A simple calculator that asks for two inputs and a choice between addition, subtraction, multiplication and division.
/// Prints the result of the two numbers combined with the operator. 
/// </summary>
void simpleCalculator() {

	int simpleCalcChoice = 0;
	float number1 = 0;
	float number2 = 0;
	float result = 0;


	cout << "Welcome to the simple calculator, pick which operator you'd like to use.\n";
	cout << "1. Addition.  +  \n";
	cout << "2. Subtraction.  -  \n";
	cout << "3. Multiplication.  *  \n";
	cout << "4. Division.  /  \n";
	cout << "5. Quit the program.";

	//The "switch" for the simple calculator. Asks for another number if the number does not correspond to a valid option.
	validateIntInput();
	simpleCalcChoice = intInput;
	while (simpleCalcChoice < 1 || simpleCalcChoice > 5) {
		cout << "Please choose a valid option: ";
		validateIntInput();
		simpleCalcChoice = intInput;
	}

	if (simpleCalcChoice == 5) {
		cout << "You quit the program.\n";
		return;
	}
	//Asks for the two numbers used for the next operation. 
	cout << "Choose the first number: \n";
	validateIntInput();
	number1 = intInput;
	cout << "Choose the second number: \n";
	validateIntInput();
	number2 = intInput;

	//Prints the result based on previous choice and number inputs.
	switch (simpleCalcChoice) {

	case 1:
		result = number1 + number2;
		cout << number1 << " + " << number2 << " = " << result;
		break;
	case 2:
		result = number1 - number2;
		cout << number1 << " - " << number2 << " = " << result;
		break;
	case 3:
		result = number1 * number2;
		cout << number1 << " * " << number2 << " = " << result;
		break;
	case 4:
		result = number1 / number2;
		cout << number1 << " / " << number2 << " = " << result;
		break;
	}
}