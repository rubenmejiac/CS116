#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {
  int Digits;
  std::cout << "Enter last 2 digits of student ID ";
  std::cin >> Digits;
  int Answer1 = (Digits + 5) * 2;
  int step1 = Answer1 / 5;
  int remain = Answer1 % 5;
  int Answer2 = pow(remain, 2);
   
  
  std::cout << "Answer1: " << Answer1 << " ";
  std::cout << "Answer2: " << Answer2;
}