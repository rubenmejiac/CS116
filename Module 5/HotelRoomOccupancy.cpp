/* Ruben Mejia Corleto
   04/02/2021
   CS 116 - Professor Flores
   Module 5 Assignment 
   Instructions:
   Write a program that calculates the occupancy rate for a hotel. 
   The program should start by asking the user how many floors the hotel has. 
   A loop should then iterate once for each floor. 
   In each iteration, the loop should ask the user for the number of rooms on the floor and
   how many of them are occupied.  
   After all iterations, the program should display how many rooms the hotel has, 
   how many of them are occupied, how many are unoccupied, and the percentage of rooms that
   are occupied. The percentage may be calculated by dividing the number of rooms occupied 
   by the number of rooms.
   Note: It is traditional that most hotels do not have a thirteenth floor. 
         The loop in this program should skip the entire thirteenth iteration.
   Input Validation: Do not accept a value less than 1 for the number of floors. 
                     Do not accept a number less than 10 for the number of rooms on a floor.
*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    //declare and initialize variables
    int floorRooms = 0;
    float totalRooms = 0.00;
    int totalFloors = 0;
    int floorOccupiedRooms = 0;
    float totalOccupiedRooms = 0.00;
    float percentOccupied = 0.00;

    //Ask for user input and perform logic and calculations
    cout << "Enter number of floors: ";
    cin >> totalFloors;

    while (totalFloors < 1)
    {
        cout << "Number of floors must be 1 or more. Please re-enter ";
        cin >> totalFloors;
    }

    for (int i = 1; i <= totalFloors; i++)
    {
        if (i != 13)
        {
            cout << "Enter the number of rooms on floor " << i << ": ";
            cin >> floorRooms;
            
            while (floorRooms < 10)
            {
                cout << "Number of rooms on floor must be 10 or more. Please re-enter ";
                cin >> floorRooms;
            }

            cout << "How many rooms are occupied? ";
            cin >> floorOccupiedRooms;
            totalRooms += floorRooms;
            totalOccupiedRooms += floorOccupiedRooms;
        }                           
    }
    percentOccupied = (totalOccupiedRooms / totalRooms) * 100;

    //Generate output
    cout << "The hotel has total of " << totalFloors << " floors" << endl;
    cout << "The hotel has total of " << totalRooms << " rooms" << endl;
    cout << "There are " << totalOccupiedRooms << " rooms occupied" << endl;
    cout << "There are " << totalRooms - totalOccupiedRooms << " empty rooms" << endl;
    cout << "The percentage of occupied rooms is: " << setprecision(2) << percentOccupied << "%." << endl;

    return 0;

}

