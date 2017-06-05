/*
UNFINISHED
Makes a huge file of verbs that have multiple per line into a one per line
file
*/

#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::cout << "Starting" << std::endl;

	std::string filename = "verbs2.txt";
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	//open input stream
	std::ifstream filein;
	filein.open(filename, std::ifstream::in);
	if(!filein.good()){
		std::cout << "ERR could not open file" << std::endl;
		return 1;
	}
	std::cout << "Opened input" << std::endl;

	//open output stream
	std::ofstream fileout;
	fileout.open("verbs3.txt");
	if(!fileout.good()) {
		std::cout << "ERR could not open file" << std::endl;
		return 1;
	}
	std::cout << "Opened output" << std::endl;

	//iterate through the input file
	//each line is in this format:
	//60	fly	flew	flown	flies	flying
	//want that to have no number, and one word per line
	std::cout << "Altering File" << std::endl;
	std::string currentline;
	std::string currentword;
	std::string currentchar;
	bool isnumber = false;
	while(getline(filein,currentline)) {
		//iterate through the line
		//std::cout << "Gotline ";
		for(int i = 0; i < currentline.length(); i++) {
			currentchar = currentline[i]; isnumber = false;

			//check for whitespace
			// if (currentchar.find("1234567890") != std::string::npos)
			// 	isnumber = true;
			if (currentchar.find("\t\n ") != std::string::npos) {
				// if (currentword.find("0123456789") == std::string::npos)
				std::cout << "Writing word" << std::endl;
				fileout << currentword + "\n";
				currentword = "";
			}
			else
				currentword += currentchar;
		}
		currentword = "";
	}

	std::cout << "Finished" << std::endl;
	return 0;
}
