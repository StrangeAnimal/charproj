//============================================================================
// Name        : charproj.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int countSubstring(std::string& str, std::string& sub);
int numchars();
int generatearay(int number,char* chararr);
int printarray(char* charry, int numchars);
void printCombinations(const std::vector<int>& numbers, int size, std::vector<int>& line, std::string& comparearray);



int search(char* chararr, std::string comparr,int size);

int main() {

	std::vector<int> numbers = {0, 1, 2, 3};
	std::vector<int> line;
	int size =5;
	int numberofchars = 0;
	char *chararray;
	std::string charcompare;

	numberofchars = numchars();
    chararray = new char [numberofchars];


	printCombinations(numbers, size,line,charcompare);

    //cout << charcompare;

   generatearay(numberofchars, chararray);
   printarray(chararray,numberofchars);


  search(chararray, charcompare,size );
	return 0;
}


int numchars(){

	int number;
	cout << "Enter the number of chars to generate" << endl;
	cin >> number;
	return number;


}

int generatearay(int number, char* chararr){
	srand(time(NULL));
	int y=0;

	for(int x=0;x< number;x++){

		y = rand() %4;

		switch(y){

		case 0: chararr[x] = 'A';
        break;
		case 1: chararr[x] = 'C';
        break;
		case 2: chararr[x] = 'T';
        break;
		case 3: chararr[x] = 'G';








		}





	}


return 0;

}


int printarray(char* charry, int numchars){

	for(int x=0;x<numchars;x++){

		cout << charry[x];


	}
    cout <<'\n';

	return 0;
}






int search(char* chararr, std::string comparr,int size){

	std::string randomstring = chararr;
	std::string substring;


	int a=0;

	int number=0;
	int total=0;
    float looptimes = pow(size,size);

	for(int x=0;x<looptimes;x++){





		substring = comparr.substr(a,size);

		number = countSubstring(randomstring, substring);
        total = total + number;
		cout << substring << ", "<< number <<'\n';

		a = a+size;


	}
      cout << total;
    return 0;
}


int countSubstring(std::string& str, std::string& sub)
{

    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}


void printCombinations(const std::vector<int>& numbers, int size, std::vector<int>& line, std::string &comparearray) {


    for (unsigned i = 0; i < numbers.size(); i++) {

        line.push_back(numbers[i]);
        if (size <= 1) { // Condition that prevents infinite loop in recursion
        	for (const auto& j : line)
        	                switch(j){

        	                case 0:comparearray.append("A");
        	                break;

        	                case 1:comparearray.append("C");
        	                break;

        	                case 2:comparearray.append("T");
        	                 break;

        	                case 3:comparearray.append("G");




        	                }




        	            line.erase(line.end() - 1);
        } else {
            printCombinations(numbers, size - 1, line,comparearray); // Recursion happens here
            line.erase(line.end() - 1);
        }
    }
}




