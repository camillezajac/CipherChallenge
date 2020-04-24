#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int chartonum(char cha){
    return ((int)cha) - 97; // ASCII a = 97
}

int main(int argc, char *argv[])
{
	fstream inFile;
	char oneChar;
	char ASCII[128] = {0}; //127 characters of the ASCII +1 
	int frequency[128];
	char code;
	double total;
	
	for(int ASCII = 0; ASCII < 128; ASCII++) //Loop through all the ASCII characters to get the frequency of each
	{
		frequency[ASCII] = 0;
	}

	inFile.open("cipher.txt", ios::in); //Reads file

	if(inFile.fail()) //Check for error opening the file
	{
		cout << "Error: File not found!" << endl << endl; 
	}
	else
	{
		oneChar = inFile.get();

		while(inFile.eof() == false) //End of file
		{
			if(oneChar != ' ')
			{
				frequency[oneChar]++; //When not empty character
				total++;

			}
			oneChar = inFile.get();
			
		}
	}

	inFile.close();

	cout << "The Frequency of the capital letters are: " << endl;
	for(char caps = 'A'; caps <= 'Z'; caps++)
	{

		cout << "Letter " << caps << " is " << setw(4) << frequency[caps] << " times." << endl;
		double frequencyDoub = (double) frequency[caps];
		double percent = (frequencyDoub/total)*100;
		cout << " Percent of total: " << percent << endl;			

	}
	cout << "Total: " << total << endl;

	// cout << "The Frequency of the lower case letters are: " << endl;
	// for(char lower = 'a'; lower <= 'z'; lower++)
	// {
	// 	cout << "Letter " << lower << " is " << setw(4) << frequency[lower] << " times." << endl;
	// }

	return 0; 
}