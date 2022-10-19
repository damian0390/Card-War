#include "deck.hpp"

  void Deck::create_cards(){
    for(auto i : suit){
      for(auto j : rank){
        name = j + i;

        if (j == "2") power = 2;
        else if (j == "3") power = 3;
        else if (j == "4") power = 4;
        else if (j == "5") power = 5;
        else if (j == "6") power = 6;
        else if (j == "7") power = 7;
        else if (j == "8") power = 8;
        else if (j == "9") power = 9;
        else if (j == "10") power = 10;
        else if (j == "J") power = 11;
        else if (j == "Q") power = 12;
        else if (j == "K") power = 13;
        else if (j == "A") power = 14;

        cards.push_back(Card(name, power));
      }
    }
  }

  void Deck::shuffle_cards(){
    srand( time( NULL ) );
    int iter;
    std::vector<Card> temporary;
    for (int i = 0; i < 52; i++){
      iter = std::rand() % cards.size();
      temporary.push_back(cards[iter]);
      cards.erase(cards.begin() + iter);
    }
    cards = temporary;
  }

  void Deck::deal_cards(Player &player1, Player &player2){
    for (int i = 0; i < 52; i += 2){
      player1.add_card(cards[i]);
      player2.add_card(cards[i+1]);
    }
  }

  void Deck::add_cards(std::vector<Card> &buffer, Player &player){
    for (int i = 0; i < buffer.size(); i++){
      player.add_card(buffer[i]);
    }
  }

  void Deck::compare(std::vector<Card> &buffer, Player &player1, Player &player2){
    if (player1.give_card().power > player2.give_card().power){
        add_cards(buffer, player1);
        buffer.clear();
      } else if (player1.give_card().power < player2.give_card().power){
        add_cards(buffer, player2);
        buffer.clear();
      }
  }

  void Deck::show_draw(Player &player1, Player &player2){
    std::cout<<"---"<<player1.give_card().name<<"--- - ---"<<player2.give_card().name<<"---"<<std::endl;
  }

  void Deck::take_cards(std::vector<Card> &buffer, Player &player1, Player &player2){
    buffer.push_back(player1.give_card());
    buffer.push_back(player2.give_card());
  }

  void Deck::erase_cards(std::vector<Card> &buffer, Player &player1, Player &player2){
    player1.erase_card();
    player2.erase_card();
  }

  void Deck::war(Player &player1, Player &player2){
    std::cout<<"no  "<<player1.show_name()<<" : "<<player2.show_name()<<std::endl;
    int counter = 1;
    std::vector<Card> buffer;
    while (true){
      std::this_thread::sleep_for(std::chrono::milliseconds(100));

      std::cout<<counter<<"   "<<player1.show_size()<<"   "<<player1.give_card().name<<" : "<<player2.give_card().name<<"   "<<player2.show_size()<<std::endl;
      counter ++;

      take_cards(buffer, player1, player2);
      compare(buffer, player1, player2);
      erase_cards(buffer, player1, player2);

      while (!buffer.empty()){
        std::cout<<"draw"<<std::endl;
        if(player1.show_size() == 0 || player2.show_size() == 0){
          break;
        } else if(player1.show_size() == 1 || player2.show_size() == 1){
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          compare(buffer, player1, player2);
          erase_cards(buffer, player1, player2);
          break;
        }else if(player1.show_size() == 2 || player2.show_size() == 2){
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          erase_cards(buffer, player1, player2);
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          compare(buffer, player1, player2);
          erase_cards(buffer, player1, player2);
          break;
        } else {
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          erase_cards(buffer, player1, player2);
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          erase_cards(buffer, player1, player2);
          take_cards(buffer, player1, player2);
          show_draw(player1, player2);
          compare(buffer, player1, player2);
          erase_cards(buffer, player1, player2);
        }
      }

      if (counter % 100 == 0){
        std::cout<<player1.show_name()<<" moved one card"<<std::endl;
        player1.add_card(player1.give_card());
        player1.erase_card();
      }

      if(player1.show_size() == 0 || player2.show_size() == 0){
        break;
      }
    }

    if (player1.show_size() == 0){
      std::cout<<player2.show_name()<<" won";
    } else{
      std::cout<<player1.show_name()<<" won ";
    }
    std::cout<<" in "<<counter - 1<<" moves";
  }
