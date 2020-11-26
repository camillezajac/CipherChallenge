#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int chartonum(char cha){
    return ((int)cha) - 97; // ASCII a = 97
}

int main(int argc, char *argv[]) {
	fstream inFile;
	char oneChar;
	char ASCII[128] = {0}; //127 characters of the ASCII +1 
	int frequency[128];
	char code;
	double total;
	
	//frequency of each ASCII char
	for(int ASCII = 0; ASCII < 128; ASCII++) {
		frequency[ASCII] = 0;
	}

	inFile.open("cipher.txt", ios::in); //Reads file
	if(inFile.fail()) {
		cout << "Error: File not found!" << endl << endl; 
	} else {
		oneChar = inFile.get();
		while(inFile.eof() == false) {
			//When not empty character
			if(oneChar != ' ') {
				frequency[oneChar]++; 
				total++;
			}
			oneChar = inFile.get();
		}
	}
	inFile.close();
	
	cout << "Frequency of uppercase letters: " << endl;
	for(char caps = 'A'; caps <= 'Z'; caps++) {
		cout << caps << ": " << setw(4) << frequency[caps] << " times." << endl;
		double frequencyDoub = (double) frequency[caps];
		double percent = (frequencyDoub/total)*100;
		cout << " Percent of frequency: " << percent << endl;			
	}
	cout << "Total: " << total << endl;

	// cout << "Frequency of the lower case letters: " << endl;
	// for(char lower = 'a'; lower <= 'z'; lower++)
	// {
	// 	cout << lower << ": " << setw(4) << frequency[lower] << " times." << endl;
	// }

	return 0; 
}
