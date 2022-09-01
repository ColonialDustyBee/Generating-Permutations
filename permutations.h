#ifndef PERMUTATIONSHEADER_H
#define PERMUTATIONSHEADER_H
#include <vector>
using namespace std;


class Permutations {
	private:
		signed long long int permutationValue = 1; // It'll suffer an overflow problem if we ONLY make it an int value.
		vector <int> list;

	public:
	// Member Functions
		Permutations(); 
		~Permutations();
		bool userValidation(int);
		void findFactorial(int);
		void generateList(int);
		void generatePermutations();
		int getFactorial();

};
#endif
