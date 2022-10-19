#pragma once
#include <string>

struct Card{
  public:
  Card(std::string n, int pow);

  std::string name;
  int power;
};
