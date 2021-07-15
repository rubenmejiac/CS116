/* Ruben Mejia Corleto
   02/16/2021
   CS 116 - Professor Flores
   Module 2 Assignment 
   This program:
    1) Prompts the user to enter 5 numbers.
    2) Once the user has entered the 5 numbers, the program should calculate and display the average of the 5 numbers. 
*/

#include <iostream>
using namespace std;

int main() {
  //define number variables as float
  float Num1, Num2, Num3, Num4, Num5;
  
  //get user input
  cout << "Enter the first number: ";
  cin >> Num1;
  cout << "Enter the second number: ";
  cin >> Num2;
  cout << "Enter the third number: ";
  cin >> Num3;
  cout << "Enter the fourth number: ";
  cin >> Num4;
  cout << "Enter the fifth number: ";
  cin >> Num5;

  //calculate the average of the 5 numbers
  float Average = (Num1 + Num2 + Num3 + Num4 + Num5) / 5;

  //display the average to the screen
  cout << "The average of the five numbers is: " << Average << endl;

return 0;
}
