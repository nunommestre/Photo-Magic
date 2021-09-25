/*
 * Nuno Mestre
 * 09/24/2021
 * Class for my FibLFSR implementation used in PhotoMagic to randomize pixel colors.
*/ 
 #include "FibLFSR.h"

FibLFSR::FibLFSR(string seed){
	for(int i = 0; i < 16; i++){
		number.push_back(seed.at(i));
	}
}
int FibLFSR::step(){
	int XORresult = 0;
	//Determines XOR of the zero index and second index(15th and 13th bit)
	if((number.at(0) == '1' && number.at(2) != '1') || (number.at(0) != '1' && number.at(2) == '1')){
		XORresult = 1;
	}
	else{
		XORresult = 0;
	}
	//XOR of the first XOR and the 3rd index (12th bit)
	if((XORresult == 1 && number.at(3) != '1') || (XORresult != 1 && number.at(3) == '1')){
		XORresult = 1;
	}
	else{
		XORresult = 0;
	}
	//XOR of the second XOR and the 5th index (10th bit)
	if((XORresult == 1 && number.at(5) != '1') || (XORresult != 1 && number.at(5) == '1')){
		XORresult = 1;
	}
	else{
		XORresult = 0;
	}
	//shift all the bits down one spot to the left
	for(int i = 1; i <= 15; ++i){
		number.at(i-1) = number.at(i);
	}
	//Pushback new bit onto the end
	number.at(15) = XORresult;

	return XORresult;
}
int FibLFSR::generate(int k){
	int decVal = 0;
	//Every time step = one the one will multiply by two every step
	for(int i = 0; i < k; i++){
		decVal = (2 * decVal) + step();
	}

	return decVal;
}
ostream& operator<<(ostream& out, const FibLFSR& right){
	out << right.number;
	return out;
}
