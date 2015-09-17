#ifndef DECK_H
#define DECK_H
#include "card.h"

class deck {
 public:
  deck();
  ~deck();
  card DealNextCard();
  static void Shuffle();
  static int current_time_nano();
  static int chkRNG();
};

#endif
