#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "card.h"

using namespace std;


card::card () {
}
int suit;
int face;
int value = 0;


card::card(int suit, int face) {
	this->face = face;
	this->suit = suit;
	this->value = face+1;
}
//int card::getValue() {
//	return value;
//}
std::string card::getType() {
  switch(this->suit)
  {
    case 0: return "Daimond";
    case 1: return "Club";
    case 2: return "Heart";
    case 3: return "Spade";
    default: return "";
  }
}
std::string card::getFace() {
	switch(this->face)
  {
    case 0: return "ACE";
    case 10: return "JACK";
    case 11: return "QUEEN";
    case 12: return "KING";
    default: return std::to_string(this->value);
  }
}
