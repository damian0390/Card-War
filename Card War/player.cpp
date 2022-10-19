#include "player.hpp"

  void Player::set_name(){
    std::cout<<"What is your name?"<<std::endl;
    std::cin>>name;
  }

  void Player::add_card(Card card){
    my_cards.push_back(card);
  }

  int Player::show_size(){
    return my_cards.size();
  }

  Card Player::give_card(){
    return my_cards[0];
  }

  void Player::erase_card(){
    my_cards.erase(my_cards.begin());
  }

  std::string Player::show_name(){
    return name;
  }
