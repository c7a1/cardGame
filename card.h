#ifndef CARD_H
#define CARD_H

class card {
 public:
  int position;
  int suit;
  int face;
  int value;
  std::string getFace();
  std::string getType();
  card ();
  card(int, int);
};
#endif
