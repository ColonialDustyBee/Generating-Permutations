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
void Permutations::generatePermutations(int userInput) {
	int factorialValue = permutationValue;
	vector <int> localList = list;
	vector<int>::iterator begin = localList.begin();// Should gather beginning
	vector<int>::iterator end = localList.end() - 1;
	vector <int>::iterator position = localList.end() - 1; // Should gather the position to the very end and then decrease
	while (factorialValue > 0) {
		while (position != begin) { // while the mobile element is greater than the one in front of it AND it's not at the beginning
			if (*position > *position - 1) { // if current one is greater than the one before it (it starts on the right)
				swap(*position, *(position - 1)); // swap it.
				for (auto i : localList) { // prints permutation
					cout << i << " ";
				}
				cout << endl;
				position--; // decrements
				cout << factorialValue << endl;
				factorialValue--;
			}
		}
		
		while (position != end) {
			if (*position < *position + 1) {
				swap(*(position), *(position + 1));
				for (auto i : localList) {
					cout << i << " ";
				}
				cout << endl;
				position++;
				cout << factorialValue << endl;
				factorialValue--;
			}
		}
	}
}

int Permutations::getFactorial() {
	return permutationValue;
}
