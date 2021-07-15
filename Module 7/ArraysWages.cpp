/* Ruben Mejia Corleto
   05/09/2021
   CS 116 - Professor Flores
   Module 7 Assignment 
   Instructions:
    Write a program which uses the following arrays:

    1. empID: An array of 7 integers to hold employee identification numbers. The array should be initialized with the following values: 1, 2, 3, 4, 5, 6, 7.
    2. Hours: an array of seven integers to hold the number of Hours worked by each employee.
    3. payRate: an array of seven doubles to hold each employee’s hourly pay rate.
    4. Wages: an array of seven doubles to hold each employee’s gross salary.
    The program should display each employee number and ask the user to enter that employee’s Hours and pay rate. 
    It should then calculate the gross Wages for that employee (Hours times pay rate) and store them in the Wages array. 
    After the data has been entered for all the employees, the program should display each employee’s identification number and gross Wages.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void inputEmployee(const int, const int[], double[], double[], double[]);
void displayEmployee(const int, const int[], const double[]);
int validateUserInput(int, int = 0);
double validateUserInput(double, double = 8.00);

int main()
{
    const int numberEmployees = 7;
    int empID[] = {1, 2, 3, 4, 5, 6, 7};

    double Hours[numberEmployees],
           payRate[numberEmployees], 
           Wages[numberEmployees];

    inputEmployee(numberEmployees, empID, Hours, payRate, Wages);

    displayEmployee(numberEmployees, empID, Wages);

    return 0;
}

void inputEmployee(const int numberEmployees, 
                     const int empID[],
                     double Hours[],
                     double payRate[],
                     double Wages[])
{
    for (int i = 0; i < numberEmployees; i++)
    {
        cout << "Enter info for employee number " << empID[i] << ":" << endl; 
        cout << "Hours worked:  ";
        Hours[i] = validateUserInput(Hours[i]);
        cout << "Pay rate:     $";
        payRate[i] = validateUserInput(payRate[i]);
        Wages[i] = Hours[i] * payRate[i];
        cout << endl;
    }
}

void displayEmployee(const int numberEmployees, 
                         const int empID[], 
                         const double Wages[])
{
    cout << setprecision(2) << fixed;
    cout << "Results: " << endl;
    for (int i = 0; i < numberEmployees; i++)
    {
        cout << "Employee number " << empID[i] << " earned a gross wage of: $" << Wages[i] << endl;
    }

}

int validateUserInput(int empNumber, int condition_number)
{
    while (!(cin >> empNumber) || empNumber < condition_number)
    {
        cout << "Input number must be "
             << condition_number
             << " or greater: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return empNumber;
}

double validateUserInput(double empNumber, double condition_number)
{
    while (!(cin >> empNumber) || empNumber < condition_number)
    {
        cout << "Input number must be "
             << condition_number
             << " or greater: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return empNumber;
}
