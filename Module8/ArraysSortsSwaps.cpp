/* Ruben Mejia Corleto
   05/15/2021
   CS 116 - Professor Flores
   Module 8 Quiz 
   Instructions:
   Write a program that uses two identical arrays of at least 20 integers. 
   It should call a function that uses the bubble sort algorithm to sort one of the arrays in ascending order. 
   The function should keep count of the number of exchanges it makes. 
   The program then should call a function that uses the selection sort algorithm to sort the other arrays. 
   It should also keep count of the number of exchanges it makes. Display these values on the screen. 
*/

#include <iostream>
using namespace std;

// Functions
void bubbleSort(int[], int, int&);
void selectionSort(int[], int, int&);
void displayResults(int, int);
int main()
{
	const int arraySize = 20;
	int firstArray[arraySize] =  {2, 19, 6, 99, 1, 28, 3, 50, 42, -1, -10, 9, 7, 63, 0, 5, -2, 33, 4, 76};
	int secondArray[arraySize] = {2, 19, 6, 99, 1, 28, 3, 50, 42, -1, -10, 9, 7, 63, 0, 5, -2, 33, 4, 76};
    int swaps1 = 0;
    int swaps2 = 0;
	bubbleSort(firstArray, arraySize, swaps1);
	selectionSort(secondArray, arraySize, swaps2);
	displayResults(swaps1, swaps2);
}

/* displayResults function 
   Displays the number of swaps each alogrithm made
*/
void displayResults(int swaps1, int swaps2)
{	
	cout << "Number of swaps made by the sort algorithms:\n";
	cout << "Bubble Sort:    " << swaps1 << endl;
	cout << "Selection Sort: " << swaps2 << endl;
}

/* bubbleSort function
   Does an ascending bubble sort on an array and counts the number of swaps it makes
*/
void bubbleSort(int array[], int arraySize, int &Exch)
{
	int temp;
	bool swap;

	do
	{ 	swap = false;
		for (int count = 0; count < (arraySize - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
				Exch++;
			}
		}
	} while (swap);
 }

/* selectionSort function
   Makes an ascending selection sort on an array and counts the number of swaps it makes
*/
void selectionSort(int array[], int arraySize, int &swaps2)
{
	int startScan, minIndex, minValue;

	for (int startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
				swaps2++;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
