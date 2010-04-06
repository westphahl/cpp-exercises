#include <iostream>

#include "media_types.h"


int main()
{
  char command;
  Medium* medium = NULL;
  command = 'q';

  while (true) {
    std::cout << "What do you want to do?" << std::endl
            << "m: new medium" << std::endl
            << "l: list media" << std::endl
            << "e: borrow last media" << std::endl
            << "r: return media" << std::endl
            << "q: quit" << std::endl
            << "Command: ";
    std::cin >> command;
    
    switch (command) {
      case 'm':
        std::cout << "Please enter media information!" << std::endl;
        medium = new Medium();
        break;
      case 'l':
        if (medium != NULL) {
          std::cout << "Media" << std::endl;
          medium->print();
        }
        break;
      case 'e':
        if (medium != NULL) {
          medium->lendOut();
        }
        break;
      case 'r':
        if (medium != NULL) {
          medium->handIn();
        }
        break;
      case 'q':
        exit(0);
    }
  }
}
