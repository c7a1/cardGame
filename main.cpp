#include <iostream>
#include <boost/graph/graph_concepts.hpp>
//#include <QCoreApplication>
#include "card.h"
#include "deck.h"
using namespace std;

deck z;
card playerhand[5];
card aihand[5];
card playedCards[5];
bool playing = true;

bool menu(){
 string play;
 cout << "Play or quit? [P]: ";
 cin >> play;
 if (play == "" || play == "p" || play == "P"){
  return playing;
 }
 else{
   return false;
 }
}
void raisePot(){
  
}
void displayPlayerHand(){
 for(int i=0; i < 5; i++){
  cout << "Card " << i+1 <<": \n";
  cout << playerhand[i].getFace() + "\n";
  cout << playerhand[i].getType() + "\n\n";
 }
}
void replaceCards(){
  string yn;
  for(int i = 0; i < 5; i++){
  cout << playerhand[i].getFace() << "\n";
  cout << playerhand[i].getType() << "\n";
  cout << "Replace card? [Y/N]: ";
  cin >> yn;
  if(yn == "y" || yn == "Y"){
   playerhand[i] = z.DealNextCard();
  }
 }
 displayPlayerHand();
}
void HRF(int round){
  string hrf;
  if(round != 0){
    cout << "Hold/Raise/Fold (H/R/F) [H]: ";
    cin >> hrf;
    if (hrf == "r" || hrf == "R"){
     raisePot();
    }
    else if(hrf == "f" || hrf == "F"){
      playing = false;
    }
  }
  else{
    cout << "Hold/Replace/Fold (H/R/F) [H]: ";
    cin >> hrf;
    if (hrf == "r" || hrf == "R"){
     replaceCards();
    }
    else if(hrf == "f" || hrf == "F"){
      playing = false;
    }
  }
}
void dealHands(){
 for(int i=0; i < 5; i++){
  cout << "Getting card...\n";
  playerhand[i] = z.DealNextCard();
  aihand[i] = z.DealNextCard();
 }
}
void playCards(int i){
  int j = 0;
  int x = 0;
  while(j < i && x < 5){
    if(playedCards[x].value == 0){
      playedCards[x] = z.DealNextCard();
      x++;
      j++;
    }
    else{
      x++;
    }
  }
}
void displayCards(int round){
  string cards;
  if(round == 1){
    for(int i = 0; i < 3; i++){
      cards = cards + ""+playedCards[i].getFace()+" of "+playedCards[i].getType() + "\n";
    }
  }
  else if(round == 2){
    for(int i = 0; i < 4; i++){
      cards = cards + ""+playedCards[i].getFace()+" of "+playedCards[i].getType() + "\n";
    }
  }
  else if(round == 3){
    for(int i = 0; i < 5; i++){
      cards = cards + ""+playedCards[i].getFace()+" of "+playedCards[i].getType() + "\n";
    }
  }
  else{ cards = "soemthing broke...";}
  cout << cards;
}
void startGame(){
 int round = 0;
 dealHands();
 displayPlayerHand();
 while(playing && round < 4){
  if(round == 1){
   playCards(3);displayCards(round);
  }
  else if(round == 2 || round == 3){
    playCards(1);displayCards(round);
  }
  HRF(round);
  round++;
 }
}
  
int main(){
 while (menu()){
  z.Shuffle();
  startGame();
 }
 return 0;
}
