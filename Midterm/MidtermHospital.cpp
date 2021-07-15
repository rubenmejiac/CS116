/* Ruben Mejia Corleto
  05/07/2021
  CS 116 - Professor Flores
  Midterm. 
  Instructions:
   Write a program that computes and displays the charges for a patient’s hospital stay. First, the program should ask if the patient was admitted as an inpatient or an outpatient. 
   If the patient was an inpatient, the following data should be entered:
    - The number of days spent in the hospital
    - The daily rate
    - Hospital medication charges
    - Charges for hospital services (lab tests, etc.) 
   The program should ask for the following data if the patient was an outpatient:
    - Charges for hospital services (lab tests, etc.)
    - Hospital medication charges
   The program should use two overloaded functions to calculate the total charges. One of the functions should accept arguments for the inpatient data, while the other function accepts arguments for outpatient information. Both functions should return the total charges.
   Input Validation: do not accept negative numbers for any data.
*/

#include <iostream>
using namespace std;

double computeTotalCharges(double, double);
double computeTotalCharges(double, double, double, double);
char userInput(char);
double validationInput(double);

int main()
{
    char choice;
    double daysHosp, rateDaily, medicationCharges,
           serviceCharge, totalCharges;

    cout << "This program will compute hospital patient charges."       << endl
         << "What was the patient type?" << endl
         << "In-patient or an Out-patient?" << endl
         << "Enter 'I' ('i') for In-patient or 'O' ('o') for Out-patient: " << endl;

    choice = userInput(choice);
    if ((choice == 'I') || (choice == 'i')) {
        cout << "Number of days in the hospital: ";
        daysHosp = validationInput(daysHosp);
        cout << "Daily room rate: $";
        rateDaily = validationInput(rateDaily);
        cout << "Medication charges: $";
        medicationCharges = validationInput(medicationCharges);
        cout << "Lab fees and other service charges: $";
        serviceCharge = validationInput(serviceCharge);
        totalCharges = computeTotalCharges(daysHosp, rateDaily, medicationCharges, serviceCharge);
        cout << "The total charges are: $" << totalCharges << endl;
    }
    else {
        cout << "Medication charges: $";
        medicationCharges = validationInput(medicationCharges);
        cout << "Lab fees and other service charges: ";
        serviceCharge = validationInput(serviceCharge);
        totalCharges = computeTotalCharges(medicationCharges,
                                              serviceCharge);
        cout << "The total charges are: $" << totalCharges << endl;
    }
    return 0;
}

char userInput(char letter) {
    cin >> letter;
    while (!((letter == 'I') || (letter == 'i') || (letter == 'O') || (letter == 'o')))
    {
        cout << "Please enter I (i) or O (o): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> letter;
    }
    return letter;
}

double validationInput(double num) {
    while(!(cin >> num) || num < 0)
    {
        cout << "Number must be 0 or greater. Please re-enter: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

double computeTotalCharges(double medicationCharges, 
                             double serviceCharge) {
     return medicationCharges + serviceCharge;
}

double computeTotalCharges(double daysHosp, 
                             double rateDaily, 
                             double medicationCharges, 
                             double serviceCharge) {
     return (daysHosp * rateDaily) + medicationCharges + serviceCharge;
}