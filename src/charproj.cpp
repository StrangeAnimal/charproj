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
using namespace std;
int countSubstring(std::string& str, std::string& sub);
int numchars();
int generatearay(int number,char* chararr);
int printarray(char* charry, int numchars);



int gencompare(char* chcompare);
int printcompare(char* chcompare);
int search(char* chararr, char* comparr);

int main() {
	int numberofchars = 0;
	char *chararray;//hello
	char charcompare[1024];
	numberofchars = numchars();
    chararray = new char [numberofchars];

   generatearay(numberofchars, chararray);
   printarray(chararray,numberofchars);
  gencompare(charcompare);
   //printcompare();
  search(chararray, charcompare);
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

int gencompare(char* chcompare){

	int a=0;
	int b=1;
	int c=2;
	int d=3;


	for(int e=0;e<4;e++){


		for(int f=0;f<4;f++){


			for(int g=0;g<4;g++){


				for(int h=0;h<4;h++){

					switch(e){

							case 0: chcompare[a] = 'A';
					        break;
							case 1: chcompare[a] = 'C';
					        break;
							case 2: chcompare[a] = 'T';
					        break;
							case 3: chcompare[a] = 'G';
					}


					switch(f){
					         case 0: chcompare[b] = 'A';
					         break;
					         case 1: chcompare[b] = 'C';
					         break;
					         case 2: chcompare[b] = 'T';
					         break;
					         case 3: chcompare[b] = 'G';


					}

					switch(g){
					case 0: chcompare[c] = 'A';
                    break;
                    case 1: chcompare[c] = 'C';
					break;
				    case 2: chcompare[c] = 'T';
					break;
					case 3: chcompare[c] = 'G';
					}


					switch(h){
				    case 0: chcompare[d] = 'A';
					break;
					case 1: chcompare[d] = 'C';
			        break;
			        case 2: chcompare[d] = 'T';
			        break;
				    case 3: chcompare[d] = 'G';
										}


					a = a+4;
					b = b+4;
					c = c+4;
					d = d+4;

					}












			}



		}






	}




return 0;
}


int printcompare(char* chcompare){

	for(int x=0;x<1024;x++){

		cout << chcompare[x];
        if((x%4) ==3){
        	cout <<',';


        }


        if(x%120 == 0){

        	cout << '\n';

        }
	}


	return 0;
}

int search(char* chararr, char* comparr){

	std::string randomstring = chararr;
	std::string substring;
	int a=0;
	char intermediate[4];
	int number=0;
	int total=0;
	for(int x=0;x<256;x++){

		intermediate[0] = comparr[a];
		intermediate[1] = comparr[a+1];
		intermediate[2] = comparr[a+2];
		intermediate[3] = comparr[a+3];
		substring = intermediate;

		number = countSubstring(randomstring, substring);
        total = total + number;
		cout << comparr[a] << comparr[a +1] << comparr[a +2] << comparr[a+3] << "= " << number <<'\n';

		a = a+4;


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





