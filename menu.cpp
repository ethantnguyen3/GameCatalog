#include <iostream>
#include <fstream>
#include <vector>
#include "hangman.h" 
#include "craps.h"  
#include "Blackjack.h" 
using namespace std;
int main() {
  /*
  SET char choice
  PRINT menu 
   
  if choice == b 
    blackjack() 
  if choice == c 
    srand(time(0))
    craps()  
  if choice == h 
    SET play to 'y' 
    while play == 'y' 
      readFile(words)
      playHangman(words) 
      ask user if they want to play again
  if choice == h
    SET play = 'y' 
    SET wordList to empty vector string words
    while play == 'y'  
      readFile(words)
      playHangman(words)
      asks user to play again  
  if choice == q 
    break
  else 
     continue
  */
  char choice = ' ';
  while (choice != 'q') {
    cout << "Games List\n" << "B - Blackjack\n" << "C - Craps\n" << "H - Hangman\n" << "Q - Quit\n"; 
    cout <<  "What game would you like to play? "; //asks what games to play
      cin >> choice;
    if (tolower(choice) == 'b') {
      blackjack(); //runs blackjack
    } 
    else if (tolower(choice) == 'c') {
      srand(time(0));
      playCraps(); //runs craps
    
    } 
    else if (tolower(choice) == 'h') {
      vector<string> words;  
      char play = 'y'; //variable declarations
      while (play == 'y') {
        readFile(words); //reads file wordList.txt
        
        playHangman(words); //plays hangman
        cout << "Would you like to play again? (y/n): ";  //asks to play again
        cin >> play;
    }
    }
    else if (tolower(choice) != 'q' && tolower(choice) != 'b' && tolower(choice) != 'c' && tolower(choice) != 'h') {
      continue; //repeats Game List until user presses valid option
    }
  }
} 



