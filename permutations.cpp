#include <iostream>
#include <iterator>
#include "permutations.h"
#include <algorithm>

using namespace std;

Permutations::Permutations(){};
Permutations::~Permutations() {};

// Methods

bool Permutations::userValidation(int userInput) {
	if (userInput < 1 || userInput > 25) {
		return false;
	}
	else {
		return true;
	}
}

void Permutations::findFactorial(int userInput) {
	int factorialValue = permutationValue;
	for (int i = 1; i <= userInput; i++) {
		factorialValue *= i; // Should multiply iteratively up to the value.
	} 
	permutationValue = factorialValue;// Sets permutation value.
}

void Permutations::generateList(int userInput) {
	vector <int> localList;
	localList.clear(); // Should clear list in case the user wanted to generate another one.s
	localList.reserve(userInput); // Inputs can only be up to 25 anyways
	for (int i = 1; i <= userInput; i++) {
		localList.push_back(i);
		//cout << i << " ";
	}
	cout << endl;

	list = localList;
}
void Permutations::generatePermutations(int userInput) {
	int factorialValue = permutationValue;
	vector <int> localList = list;
	vector<int>::iterator beginPO = localList.begin();// Should gather beginning
	vector<int>::iterator endPO = localList.end() - 1;
	vector <int>::iterator position = localList.end() - 1;// Should gather the position to the very end and then decrease
	bool reachedRight = false;
	bool reachedLeft = false;
	factorialValue--;
	for (auto i : localList) {
		cout << i << " ";
	}
	cout << endl;
	while (factorialValue > 0) {
		while (beginPO != position) {
			vector<int>::iterator largestMobileElement = max_element(begin(localList), end(localList)); // find max element
			swap(*(largestMobileElement), *(position - 1));
			position--;
			factorialValue--;
			for (auto i : localList) { // prints permutation
				cout << i << " ";
			}
			cout << endl;
			if (position == beginPO) {
				reachedLeft = true;
			}
		}
		while (endPO != position) {
			vector<int>::iterator largestMobileElement = max_element(begin(localList), end(localList)); // find max element
			if (reachedLeft == true) {
				swap(*(largestMobileElement + 1), *(position + 1));
				if (*(position) > *(position + 1)) {
					reachedLeft = false;
				}
			}
			else {
				swap(*largestMobileElement, *(position + 1));
			}
			for (auto i : localList) {
				cout << i << " ";
			}
			cout << endl;
			position++;
			factorialValue--;
		}
	}
}

int Permutations::getFactorial() {
		return permutationValue;
}
