#include <string>
#include <iostream>

#include "media_types.h"


Medium::Medium()
{
  title_ = "Medium";
  signature_ = readSignature();
  title_ = readTitle();
  status_ = true;
}

int Medium::getSignature()
{
  return signature_;
}

int Medium::readSignature()
{
  int signature = 0;

  std::cout << "Signature: ";
  std::cin >> signature;
  return signature;
}

std::string Medium::readTitle()
{
  std::string title = "";
  
  std::cout << "Title: ";
  std::cin >> title;
  return title;
}

void Medium::lendOut()
{
  if (status_ == true) {
    status_ = false;
    std::cout << "Thank your for returning this media!" << std::endl;
  } else {
    std::cout << "Sorry, medium not available!" << std::endl;
  }
}

void Medium::handIn()
{
  if (status_ == false) {
    status_ = true;
  } else {
    std::cout << "You already returned this media." << std::endl;
  }
}

void Medium::print()
{
  std::cout << "print media" << std::endl;
}
