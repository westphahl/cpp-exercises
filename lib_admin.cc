#include <iostream>
#include <stdlib.h>

#include "media/types.h"

using namespace std;

int main()
{
  char command;
  Medium* medium = NULL;
  command = 'q';

  while (true) {
    cout << "What do you want to do?" << endl
            << "m: new medium" << endl
            << "l: list media" << endl
            << "e: borrow last media" << endl
            << "r: return media" << endl
            << "q: quit" << endl
            << endl
            << "Command: ";
    cin >> command;
    cout << endl;
    
    switch (command) {
      case 'm':
        cout << "Please enter media information!" << endl;
        medium = new Medium();
        break;
      case 'l':
        if (medium != NULL) {
          cout << "Media" << endl;
          medium->print();
        }
        break;
      case 'e':
        if (medium != NULL) {
          medium->lendOut();
        } else {
          cout << "Please enter medium first!" << endl;
        }
        break;
      case 'r':
        if (medium != NULL) {
          medium->handIn();
        } else {
          cout << "Please enter medium first!" << endl;
        }
        break;
      case 'q':
        exit(EXIT_SUCCESS);
    }
    cout << endl;
  }
}
