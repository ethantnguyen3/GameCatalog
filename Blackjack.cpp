#include <iostream>  
#include "Blackjack.h" 
#include <vector>  
void createDeck(vector<Card> &deck) {
/*
srand(time(0)); 
SET Card tempCard 
create deck (1-12) with suites (1-4) and store in vector 
shuffles deck using for loop and random number generator 
  SET tempCard to deck[i] 
  SET idx to random number between 0 and 51 
  SET deck[i] TO deck[idx] 
  SET deck[idx] TO tempCard
*/
  srand(time(0)); //ensures that numbers will be different
  Card tempCard; 
  for (int i = 1; i <= 13; i++) {   
    //loops to create tempCard
    for(int j = 1; j <= 13; j++) {
      tempCard.suit = i; //initalizes suit
      tempCard.value = j; //initalizes value
      deck.push_back(tempCard);
    }
  }

  for (int i = 0; i < 52; i++) {
    tempCard = deck[i]; //variable delcarations
    int idx = rand()%52; 
    deck[i] = deck[idx]; //swaps cards through randomziing
    deck[idx] = tempCard; 
}

}
int calcHand(vector<Card> hand) {
  /*
  SET sum to 0 
  for int i = 0; i < hand.size(); i++ 
    if hand[i].value == 1 and sum <= 21 
        sum += 11 
        if sum > 21 
          sum -= 10 
      continue 
    if hand[i].value > 10 
      sum += 10 
      continue  
    sum += hand[i].value
  */
  int sum = 0; 
  for (int i = 0; i < hand.size(); i++) {
    if (hand[i].value == 1 && sum <= 21) {
      sum += 11; //Ace can become 11 or 1
      if (sum > 21) {
        sum -= 10;
      }
      continue;
    }  
    if (hand[i].value > 10) {
      sum +=10; //king, queen, jack
      continue;
    }
    sum += hand[i].value;

  }
  return sum;
}
void showHand(vector<Card> &hand) {
  /*
  for int i = 0; i < hand.size(); i++ 
    PRINT hand suit and value
  */
  //prints out what the user/cpu has on hand
  for (int i = 0; i < hand.size(); i++) {
    cout << hand[i].suit << " " << hand[i].value << endl;
  } 
}
Card dealCard(vector<Card> &deck) {
  /*
  SET topCard to first index of deck 
  SET deck.erase(deck.begin()) to remove topCard from deck 
  return topCard
  */

  Card topCard = deck[0]; 

  deck.erase(deck.begin()); //initalizes first card before removing it
  return topCard;
}

void blackjack () { //Please note this might take a couple of times to run (it sometimes just outputs Player's Hands on replit)
  /*
  SET play to 'y' 
  while tolower(play) == 'y' 
    set deck to vector of cards, player, dealer  
    SET Card tempCard
    char another = 'Y'
    int playerTotal = 0, dealerTotal = 0 
    createDeck(deck) 
    SET tempCard to dealCard(theDeck)
    PRINT player's hand and total
    Deal CPU hand until dealerTotal >= 17
    WHILE another == 'y' 
      PRINT another card (depending if first run or not) with the other cards 
      CALCULATES playerTotal 
      if playerTotal > 21 
        PRINT player loses  
        Ask to play again
        break 
      Clear hands
      ASKS if user wants another card 
    If user doesn't play again, 
      break;
      
    IF another == 'n' 
      PRINT cpu's hand
      IF dealerTotal > 21 
        PRINT player wins
      ELSE IF playerTotal > dealerTotal 
        PRINT player wins 
      ELSE IF playerTotal < dealerTotal 
        PRINT CPU wins 
      ELSE IF playerTotal == dealerTotal 
        PRINT push
      
  clears player and dealer's hands 
  asks if user wants to play again
  */
//variable declaration
  char play = 'y';



  vector<Card> theDeck, player, dealer;  
  //Card tempCard; 
  char another;
  while (tolower(play) == 'y') {
    


    
    int playerTotal = 0, dealerTotal = 0; 
    createDeck(theDeck);  //deck created
     



    cout << "Player's hand: " << endl; //first card(s) dealed
    player.push_back(dealCard(theDeck)); 
    player.push_back(dealCard(theDeck));
    playerTotal = calcHand(player); //calculates player's total 
    
    showHand(player);
    cout << "Total: " << playerTotal << endl;
    dealer.push_back(dealCard(theDeck)); 
    dealer.push_back(dealCard(theDeck)); 
    cout << "Would you like to take another card? (Y/N): ";
    cin >> another; 
    dealerTotal = calcHand(dealer);  
    
    while (dealerTotal < 17) { 
      //from chatgpt
      dealer.push_back(dealCard(theDeck)); 
      dealerTotal = calcHand(dealer); //displays dealer's hand
    }
    
    while (another == 'Y') { 
      //from chatGPT

      player.push_back(dealCard(theDeck)); //another card added
      
      showHand(player); //displays all cards
      playerTotal = calcHand(player); //calculates total of values 
      cout << "Total: " << playerTotal << endl;
      if (playerTotal > 21) {
        cout << "OOPS - PLAYER WENT OVER 21. COMPUTER WINS!!" << endl;  //displays who wins
        another = 'n';
        player.clear(); //from chatgpt
        dealer.clear(); //clears hands from player and dealer
         cout << "Would you like to play again? (Press Y to continue): "; //ask to play again
         cin >> play; 
        break;
      } 
      cout << "Would you like to take another card? (Y/N): ";

      cin >> another; 
      cout << "Player's hand: " << endl;
      
    }

    if (tolower(play) == 'n') {
      break;
    }
    if (dealerTotal > 21) {
      cout << "COMPUTER WENT OVER 21. PLAYER WINS!!" << endl;
      player.clear(); //from chatgpt
      dealer.clear(); //clears hands from player and dealer
       cout << "Would you like to play again? (Press Y to continue): "; //ask to play again
      cin >> play; 
    if (tolower(play) == 'y') {
      continue;
    } 
      else {
        break;
      }
    }
    if (another == 'N') {
      
        cout << "Computer's hand: " << endl;
        showHand(dealer); //displays cpu hand
      
      //displays who wins
      
      if (playerTotal > dealerTotal) {
        cout << "*****PLAYER WINS*****" << endl; 
      }
      else if (playerTotal < dealerTotal) {
        cout << "*****PLAYER LOSES*****" << endl; 
      } 
      else if (playerTotal == dealerTotal) {
        cout << "*****PUSH*****" << endl;
      }  

      

      } 

    } 

    player.clear(); //from chatgpt
    dealer.clear(); //clears hands from player and dealer
     cout << "Would you like to play again? (Press Y to continue): "; //ask to play again
     cin >> play; 
    

    }





