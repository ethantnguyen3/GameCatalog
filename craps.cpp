#include "craps.h"
#include <iostream>
using namespace std; 
int rollDice(int &die1, int &die2) {
  /* 
  die1 = rand() % 6 + 1; 
  die2 = rand() % 6 + 1; 
  return die1+die2
  */
  die1 = rand() % 6 + 1; //rolls first and second dice
  die2 = rand() % 6 + 1; 

  return die1 + die2; //sum of both dice
} 


void playCraps() {


  /*
  SET char play = 'y' 
  WHILE networth > 0 AND play == 'y'
    SET double networth = 50.00 
    SET double wager = 0.00
    WHILE networth < wager 
       PRINT error message and reask user for wager
    if 7 or 11 - you win
      ELSE if 2,3 or 12 - you lose
      ELSE 
        SET point value 
        ROLL Dice 
        WHILE (sum != point && sum != 7) {
          ROLL Dice
        TEST sum for WIN or LOSE
      } 
  IF networth > 0 
     PRINT networth 
  ELSE 
    PRINT "You are broke"
  */
  //variable declarations
  char play = 'Y'; 
  double netWorth = 50.00; 

  while (tolower(play) == 'y' && netWorth > 0) { 
    double wager; //initalize wager every time loop plays
    cout << "Your net worth is: $" << netWorth << ". Please enter your bet: ";  
    cin >> wager;  
    while (wager > netWorth) {
      cout << "Your net worth is only: $" << netWorth << ". Please adjust your bet: "; //error message if wager too high
      cin >> wager;
    }
    int d1 = 0, d2 = 0, sum = 0;
    sum = rollDice(d1, d2); //rolls dice for the first time
    cout << "You rolled: " << d1 << " + " << d2 << " = " << sum << endl;


  if (sum == 7 || sum == 11) {
    cout << "Yay, you win!!" << endl; //win conditions
    netWorth += wager; //adds to wager
  }
  else if (sum == 2 || sum == 3 || sum == 12) {
    cout << "Sorry, but you lost!!" << endl;  //lose conditions
    netWorth -= wager; //subtracts from wager
 }
  else {
    cout << "\nPoint is " << sum << endl;
    int point_value = sum; //initalize point_value 
    sum = rollDice(d1, d2); //rolls dice for the second time

    cout << "You rolled: " << d1 << " + " << d2 << " = " <<   sum << endl;
    while (sum != point_value && sum != 7) { 
      //keeps on rolling dice until it hits point or 7 
      sum = rollDice(d1, d2);
      cout << "You rolled: " << d1 << " + " << d2 << " = " <<  sum << endl; 
    }
    if (sum == point_value) {
      cout << "Yay, you Win!!" << endl; //win condition
      netWorth += wager; //adds to net worth
    }
    else {
      cout << "Sorry, but you lost!!" << endl; //lose condition
      netWorth -= wager; //subtracts from net worth
    } 

  }
    cout << "Would you like to go again? Y or N "; 
    cin >> play;
  } 
  if (netWorth > 0) {
    cout << "Thank you for playing. Your net worth is: " << netWorth << endl; //outputs net worth if user still has money
  } 
  else {
    cout << "Sorry - you are out of money. Don't make us escort you out - that would be embarrassing!!" << endl; //forces user to leave if they are out of money
  }
}