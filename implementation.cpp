#include <iostream>
#include "permutations.h"
#include <fstream>

using namespace std;


int main() {
	Permutations permutations;
	int input = 0;
	bool incorrectInput = false;
	cout << "Please enter a value from 1 to 25" << endl;
	cin >> input;
	while (!incorrectInput) {
		incorrectInput = permutations.userValidation(input);
		if (!incorrectInput) {
			cout << "Value is incorrect!" << endl;
			cout << "Please enter again: ";
			cin >> input;
			incorrectInput = permutations.userValidation(input);
		}
	}
	permutations.findFactorial(input);
	cout << "The factorial of: " << input << "is: " << permutations.getFactorial() << endl;
	permutations.generateList(input);
	permutations.generatePermutations(input);
	return 0;
}
