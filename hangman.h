#pragma once 
#include <iostream> 
#include <fstream> 
#include <vector>
#include <string> 

using namespace std; 


void readFile(vector<string> &wordList); 
//PRE vector is empty 
//POST vector will be loaded with word from wordList.txt 
void playHangman(const vector<string> &wordList);
//PRE: vector has words to choose 
//POST: play hangman 