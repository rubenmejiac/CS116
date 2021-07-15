/*	Ruben Mejia Corleto
	06/02/2021
	CS 116 - Professor Flores
	Final x 
	
	Instructions:
	The file Random.txt contains a long list of random numbers. Download the file to your system, 
	then write a program that opens the file, reads all the numbers from the file, and calculates 
	the following:

	-The number of numbers in the file
	-The sum of all the numbers in the file (a running total)
	-The average of all the numbers in the file
	
	The program should display the number of numbers found in the file, the sum of the numbers, 
	and the average of the numbers.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream indata;
   int num; // variable for reading input value from file
   int cnt = 0; // variable for counting numbers in file
   int suma = 0; // variable to sum values
   double avrage = 0; // variable to calculate the average

   cout << "Numbers in file: reading, counting, averaging" << endl;
   cout << "---------------------------------------------" << endl;

indata.open("Random.txt"); // opens the file
   if(!indata) { // displays error if file is not found
      cerr << "The file is not found." << endl;
      exit(1);
   }

indata >> num;
   while ( !indata.eof() ) { // read until the end-of-file
      cout << num << " " ;
      cnt ++;
      suma = suma + num;
      indata >> num; // signals end-of-file when no value is found
   }

avrage = suma / cnt; // calculate the average

// display the output
cout << "Number of numbers in file:        " << cnt << endl;
cout << "Sum of numbers in file:           " << suma << endl;
cout << "Average value of numbers in file: " << avrage << endl;

indata.close();
cout << "Process completed." << endl;
return 0;
}