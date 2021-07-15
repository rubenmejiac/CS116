/* Ruben Mejia Corleto
   04/14/2021
   CS 116 - Professor Flores
   Module 6 Assignment 
   Instructions:
    A particular talent competition has five judges, each of whom awards a score between 0 and 10 to each performer. 
    Fractional scores, such as 8.3, are allowed. A performer’s final score is determined by dropping the highest 
    and lowest score received, then averaging the three remaining scores. 
    Write a program that uses this method to calculate a contestant’s score. It should include the following functions:

    1. void getJudgeData( ) should ask the user for a judge’s score, store it in a reference parameter variable, 
    and validate it. This function should be called by main once for each of the five judges.
    2.  void calcScore( ) should calculate and display the average of the three scores that remain after dropping 
    the highest and lowest scores the performer received. This function should be called just once by main and 
    should be passed the five scores.
    
    The last two functions, described below, should be called by calcScore, which uses the returned information to 
    determine which of the scores to drop:

    3.  double findLowest( ) should find and return the lowest of the five scores passed to it.
    4.  double findHighest( ) should find and return the highest of the five scores passed to it.
    
    Input Validation: Do not accept judge scores lower than 0 and higher than 10.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void getJudgeData(double &, string);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);
double validation(double);

int main()
{
    double score1, score2, score3, score4, score5;

    getJudgeData(score1, "1");
    getJudgeData(score2, "2");
    getJudgeData(score3, "3");
    getJudgeData(score4, "4");
    getJudgeData(score5, "5");
    
    calcScore(score1, score2, score3, score4, score5);
    return 0;
}

/*
  void getJudgeData():
  ask the user for a judge’s score, store it in a reference parameter 
  and validate it. This function it's called by main() for every one of the five judges
 */
void getJudgeData(double &score, string score_num)
{
    if (score_num == "1")
        score_num = "1";
    else if (score_num == "2")
        score_num = "2";
    else if (score_num == "3")
        score_num = "3";
    else if (score_num == "4")
        score_num = "4";
    else if (score_num == "5")
        score_num = "5";
    cout << "Score for Judge " 
         << score_num 
         <<  ": ";
    score = validation(score);
}

/*
  calcScore(): 
  calculates and displays the average of the three scores left
  after discarding the lowest and the highest scores
*/ 
void calcScore( double score1, double score2,
                double score3, double score4,
                double score5 )
{
    double lowest = findLowest(score1, score2, score3, score4, score5),
           highest = findHighest(score1, score2, score3, score4, score5),
           average,
           suma = score1 + score2 + score3 + score4 + score5;

    suma -= lowest;
    suma -= highest;

    average = suma / 3;

    cout << endl << "Lowest:   " << lowest << endl
         << "Highest:  " << highest << endl
         << "Average score for performer:  " << average << endl
         << endl;
}

/*
  findLowest():
  Finds and returns the lowest of the passed five scores                 
*/
double findLowest( double score1, double score2,
                   double score3, double score4,
                   double score5 )
{
    double lowest = min({score1, score2, score3, score4, score5});
    return lowest;
}

/*
  findHighest():
  Finds and returns the highest of the passed five scores                 
*/
double findHighest( double score1, double score2,
                    double score3, double score4,
                    double score5 )
{
    double highest = max({score1, score2, score3, score4, score5});
    return highest;
}

/*
  validation() function:                  
  validates input for a values between 0 and 10
 */
double validation(double num)
{
    while(!(cin >> num) || (num < 0 || num > 10))
    {
        cout << "Error, input should be between 0 and 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}
