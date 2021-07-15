/* Ruben Mejia Corleto
   05/23/2021
   CS 116 - Professor Flores
   Module 9 x Programming Assignment
   Write a program that dynamically allocates an array large enough to hold a user-defined 
   number of test score. Once all the score are entered, the array should be passed to 
   a function that sorts them in ascending order. 
   Another function should be called that calculates the average score. 
   The program should display the sorted list of score and averages with appropriate 
   headings. Use pointer notation rather than array notation whenever possible.
   Input Validation: Do not accept negative numbers for test score.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Functions
void inputData(double *, int);
void sortValues(double *, int);
double calcAverage(double *, int);
void displayData(double *, double, double);

int main() {
	int score;
	double *myArray, valAverage;		

	cout << "How many scores do you want to average? ";
	cin >> score;

	myArray = new double[score];	
	inputData(myArray, score);
	sortValues(myArray, score);
	valAverage = calcAverage(myArray, score);
	displayData(myArray, score, valAverage);

	return 0;
}

void inputData(double *myArray, int score) {
	cout << "Enter each score \n";
	for (int i = 0; i < score; i++)	{
		do
		{
			cout << "Score number " << (i + 1) << ": ";
			cin  >> *(myArray + i);

			if (*(myArray + i) < 0)
			{
				cout << "The score cannot be negative.\n"
					 << "Please re-enter: ";
			}

		} while (*(myArray + i) < 0);
	}
}

void sortValues(double *myArray, int score) {
	int findValues, minIndex;
	double minValue;

	for (findValues = 0; findValues < (score - 1); findValues++)
	{
		minIndex = findValues;
		minValue = *(myArray + findValues);
		for (int i = findValues + 1; i < score; i++) {
			if (*(myArray + i) < minValue) {
				minValue = *(myArray + i);
				minIndex = i;
			}
		}
		*(myArray + minIndex) = *(myArray + findValues);
		*(myArray + findValues) = minValue;
	}
} 

double calcAverage(double *myArray, int score) {
	double totalVal;

	for (int i = 0; i < score; i++)	{
		totalVal += *(myArray + i);
	}

	return totalVal / score;
} 

void displayData(double *myArray, double score, double Avg) {
	cout << "Number of scores: " << score << endl;
	cout << "Scores in ascending order: \n";
	cout << fixed << showpoint << setprecision(2);
  for (int i = 0; i < score; i++)	{
		cout << "#" << (i + 1) << ": " << *(myArray + i) << endl;
	}
		cout << "Average score: " << Avg << endl; 
}