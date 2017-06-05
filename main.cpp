/*
Grant Cox
grantcox167@gmail.com
RandomSentence - a simple sentence generator that is helping me get used to Git
6/5/2017
*/


#include <iostream>
#include <fstream>
//#include <random>
#include <vector>
#include <string>

std::vector<std::string> populateVector(std::string filename);

int main(int argc, char* argv[]) {
     //populate vectors
     std::cout << "Populating vectors" << std::endl;
     std::vector<std::string> nouns, verbs, prepositions, adjectives;
     nouns = populateVector("nouns.txt");
     verbs = populateVector("verbs.txt");
     prepositions = populateVector("prepositions.txt");
     adjectives = populateVector("adjectives.txt");

     std::string message = "Press any key for a random sentence. Press 'q' to exit.\n";
     std::cout << message;
     std::string userin = "";

     /*
     generate secret number between 1 and 10:
     iSecret = rand() % 10 + 1;
     */
     int adjrand, preprand, nounrand, verbrand, nounrand2;
     while(userin != "q") {
          //get random nums
          adjrand = rand() % 1347 + 1; preprand = rand() % 70 + 1;
          nounrand = rand() % 4554 + 1; verbrand = rand() % 1011 + 1;
          nounrand2 = rand() % 4554 + 1;

          std::cout << adjectives[adjrand] << " " << nouns[nounrand] << " " <<
               verbs[verbrand] << " " << prepositions[preprand] << " " <<
               nouns[nounrand2] << std::endl;

          std::cin >> userin;
     }

}


//populates vector of nouns, prepositions, or verbs, returns vector
std::vector<std::string> populateVector(std::string filename) {
     std::ifstream filein(filename,std::ifstream::in);
     if(!filein.good())
          std::cout << "error opening file " << filename << std::endl;

     std::vector<std::string> objects;
     std::string line;

     while(getline(filein,line))
          objects.push_back(line);

     return objects;
}