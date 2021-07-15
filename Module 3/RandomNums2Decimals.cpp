/* Ruben Mejia Corleto
   03/04/2021
   CS 116 - Professor Flores
   Module 3 Assignment 
   This program:
   1) Generates two positive integers at random within the 1 – 10 range.
   2) Displays the sum, difference, product and quotient of the
      two randomly generated numbers
   3) The results must be displayed with two decimal places after
      the decimal point 
*/

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
  
  //Generate two random numbers between 1 and 10
  srand(static_cast<unsigned>(time(0)));
  int randomNum1 = rand() % 10 + 1;
  int randomNum2 = rand() % 10 + 1;
  cout << "Random generated numbers are: " << randomNum1 << " and " << randomNum2 << endl;
  cout << endl;

  //Declare variables for operations with both numbers
  float sumNumbers = randomNum1 + randomNum2;
  float diffNumbers = randomNum1 - randomNum2;
  float prodNumbers = randomNum1 * randomNum2;
  float quotNumbers = (float)randomNum1 / (float)randomNum2;
  
  //Set the precision to display results with two decimal places
  cout << setprecision(2);
  cout << fixed;

  //Display the results of each calculation
  cout << "Sum of " << randomNum1 << " + " << randomNum2 << " is: " << sumNumbers << endl;
  cout << "Difference of " << randomNum1 << " - " << randomNum2 << " is: " << diffNumbers << endl;
  cout << "Product of " << randomNum1 << " * " << randomNum2 << " is: " << prodNumbers << endl;
  cout << "Quotient of " << randomNum1 << " / " << randomNum2 << " is: " << quotNumbers << endl;
  
  return 0;
}