#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include "card.hpp"
#include "player.hpp"

class Deck{
  public:
  std::vector<std::string> suit = {"H","T","C","P"};
  std::vector<std::string> rank = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
  std::vector<Card> cards;
  int power;
  std::string name;

  void create_cards();
  void shuffle_cards();
  void deal_cards(Player &player1, Player &player2);
  void add_cards(std::vector<Card> &buffer, Player &player);
  void compare(std::vector<Card> &buffer, Player &player1, Player &player2);
  void show_draw(Player &player1, Player &player2);
  void take_cards(std::vector<Card> &buffer, Player &player1, Player &player2);
  void erase_cards(std::vector<Card> &buffer, Player &player1, Player &player2);
  void war(Player &player1, Player &player2);

};
