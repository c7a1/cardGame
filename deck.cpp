#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "card.h"
#include "deck.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <chrono>
using namespace std;
using namespace boost;

const int NUM_TOTAL_CARDS = 52;
const int NUM_SUITS = 4;
const int NUM_FACE = 13;
card cardArray[NUM_TOTAL_CARDS];
int usedCards[NUM_TOTAL_CARDS];

random::mt19937 rng(time(NULL)%233);

deck::deck(){
 Shuffle();
 int cardCount = 0;
 for(int i = 0; i < NUM_SUITS; i++){
  for (int j = 0; j < NUM_FACE; j++){
   cardArray[cardCount] = card(i, j);
   cardCount++;
  }
 }
}
deck::~deck(){}

void deck::Shuffle(){
 for(int i = 0;i<52;i++){
  usedCards[i] = 90;
 }
}

card deck::DealNextCard(){
 int temp;
 temp = chkRNG();
 return cardArray[temp];
}

int deck::chkRNG(){
 random::uniform_int_distribution<int> cardrng(0,51);
 int temprng = cardrng(rng);
  if(temprng == usedCards[temprng]){
   temprng = deck::chkRNG();
  }
 usedCards[temprng] = temprng;
 //cout << "Range is: " << temprng << "\n";
 return temprng;
}
