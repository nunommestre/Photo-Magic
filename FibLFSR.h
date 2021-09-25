#ifndef FIBLFSR_H
#define FIBLFSR_H
#include <iostream>
#include <string>

using namespace std;

class FibLFSR{
	public:
		FibLFSR(string seed);
		int step();
		int generate(int k);
	friend ostream& operator<<(ostream& out, const FibLFSR& right);
	private:
	//Professor said it was ok for taps not to be in constructor so just a 		private string to keep track of the bit-string
		string number;
};
#endif /*FIBLFSR_H*/
