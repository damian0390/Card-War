#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "card.hpp"

class Player{
  public:
  std::string name;
  std::vector<Card> my_cards;

  void set_name();
  void add_card(Card card);
  int show_size();
  Card give_card();
  void erase_card();
  std::string show_name();
};
