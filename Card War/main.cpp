#include <iostream>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

int main() {
  Deck d;
  d.create_cards();
  d.shuffle_cards();

  Player player1;
  Player player2;
  std::cout<<"Player 1"<<std::endl;
  player1.set_name();
  std::cout<<"Player 2"<<std::endl;
  player2.set_name();
  d.deal_cards(player1, player2);
  d.war(player1, player2);
}
