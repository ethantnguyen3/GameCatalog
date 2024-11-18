#include <iostream>
#include <fstream>
#include <vector>
#include "hangman.h"
using namespace std;

void readFile(vector<string> &wordList) { 
  /*
  ifstream inFile; 
  inFile.open("wordList.txt"); 
  if !file.isopen 
    PRINT "could not open file" 
  SET tempword 
  getline(inFile, tempword) 
  while inFile.good 
     wordList.push_back(tempWord)
     getline(inFile, tempWord) 
  close file
  */
  ifstream inFile;
  //var declaration
  //open file    
  inFile.open("wordList.txt");
  //verify it is open 
  if (!inFile.is_open()) {
    cout << "Could not open the file\n"; 
    return;
  }
  //read 
  string tempWord; 
  getline(inFile, tempWord); 
  while (inFile.good()) {
    wordList.push_back(tempWord); 
    getline(inFile, tempWord);
  }
  //close
  inFile.close();
}

 
void playHangman(const vector<string>& wordList) { 
  //choose random word from wordList (0-size()-1) and store as string 
  //create a string of questionmarks of the length of word chosen 
  //set number of guesses to 6   
  //while (word != ?word && number of guesses != 0 )
  //  guess a letter
  //  is letter in the word? if so, update ???? word  
  //  if user gets a letter right, 
  //    fill in question mark in the correct position
    //else   
    //   reduce the number of guesses
    //   message to user ?? word and number of guesses left 
  //  if word == ?word 
  //    message to user "you win"
  //  if at 0 number of guesses - they lost 
  //    break
  
  
  //whole function from chatgpt using psuedocode provided in-class
    srand(static_cast<unsigned int>(time(0))); //randomizes words
    string chosenWord = wordList[rand() % wordList.size()]; //random word from wordList
    string hiddenWord(chosenWord.length(), '?'); //question marks for the length of the word
    int guessesLeft = 6;

    cout << "Welcome to the Hangman Game!";
    cout << "Hangman - Your word is " << hiddenWord << "\n";
    
    while (hiddenWord != chosenWord && guessesLeft > 0) {
        char guess;
        
        cout << "Enter your guess: "; //asks user for a character
        cin >> guess; 
      

        if (chosenWord.find(guess) != string::npos) {
          //if the guess is in the word, update the hidden word with the correct letter
            for (size_t i = 0; i < chosenWord.length(); ++i) {
              //iterates through chosenWord length to replace ? with the correct letter
                if (chosenWord[i] == guess) {
                    hiddenWord[i] = guess;
                    cout << "Nice guess! You hav " << guessesLeft << " guesses left. "; 
                    cout << "Your current word: " << hiddenWord << "\n";
                }
            }
        } else {
          //when user gets letter wrong
            cout << "Sorry! Guess is not valid. You have " << guessesLeft << " guesses left. ";
            cout << "Your current word: " << hiddenWord << "\n";
            guessesLeft--; //reduces guesses
        }

        

        if (hiddenWord == chosenWord) {
            cout << "Nice Guess! You WIN!!!! The word was " << chosenWord << "\n"; //win condition
        } else if (guessesLeft == 0) {
            cout << "Sorry, you ran out of guesses. The correct word was: " << chosenWord << "\n"; //lose condition
        }
    }
}

   
  

