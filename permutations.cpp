#include <iostream>
#include "permutations.h"

using namespace std;

Permutations::Permutations(){};
Permutations::~Permutations() {};

bool Permutations::findFactorial(int userInput) {
	int factorialValue = permutationValue;
	if (userInput < 1 && userInput > 25) {
		cout << "Sorry, that input is invalid!" << endl;
		return false;
	}
	for (int i = 1; i <= userInput; i++) {
		factorialValue *= i; // Should multiply iteratively up to the value.
	} 
	permutationValue = factorialValue;// Sets permutation value.
}

void Permutations::generateList(int userInput) {
	vector <int> localList;
	localList.clear(); // Should clear list in case the user wanted to generate another one.s
	localList.reserve(userInput); // Inputs can only be up to 25 anyways
	cout << "{";
	for (int i = 1; i <= userInput; i++) {
		list.push_back(i);
		cout << i << " ";
	}
	cout << "}" << endl;

	list = localList;
}
void Permutations::generatePermutations() {
	// Binary Search to find biggest number in list
	
	// Compare Biggest number to number next to it (on the left of the list)
	// Swap two numbers
	// Rinse and repeat until permutations are done which we will use value here.
}

int Permutations::getFactorial() {
	return permutationValue;
}