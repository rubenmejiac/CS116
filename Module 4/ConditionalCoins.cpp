/* Ruben Mejia Corleto
   03/18/2021
   CS 116 - Professor Flores
   Module 4 Assignment 
   This program:
   1. Prompts the user to enter a positive integer, think of this integer as representing a specific number of pennies.
   2. Calculates and displays the least possible number of coins (quarters, dimes, nickels and cents) that may be used to represent the number of pennies entered by the user. 
   For example: If the user enters 28, then the program should display 1 quarter and 3 pennies.
   The program displays the results using proper grammar (singular or plural). 
*/

#include <iostream>
using namespace std;

int main()
{
	int amountPennies, quarters, dimes, nickles, pennies;

	//ask the user for input
  cout << "Please enter the number of pennies: ";
	cin >> amountPennies;

	//find the number of quarters
	quarters = amountPennies / 25;
	amountPennies = amountPennies % 25;

	//find the number of dimes
	dimes = amountPennies / 10;
	amountPennies = amountPennies % 10;

	//find the number of nickles
	nickles = amountPennies / 5;
	amountPennies = amountPennies % 5;

	//find number of pennies
	pennies = amountPennies;

	//output the results to screen, excluding coins with
  //zero values and formatting singular or plural coin names
	cout << "Change:" << endl;
	cout <<  endl;
	if (quarters != 0) {
      if (quarters == 1)
        cout << quarters << " quarter" << endl;    
  else 
    cout << quarters << " quarters" << endl;
  }

  if (dimes != 0) {
      if (dimes == 1)
        cout << dimes << " dime" << endl;    
  else 
    cout << dimes << " dimes" << endl;
  }

	if (nickles != 0) {
      if (nickles == 1)
        cout << nickles << " nickel" << endl;    
  else 
    cout << nickles << " nickels" << endl;
  }  

  if (pennies != 0) {
      if (pennies == 1)
        cout << pennies << " penny" << endl;    
  else 
    cout << pennies << " pennies" << endl;
  }
	return 0;

}
