#include <iostream>
#include <stdlib.h>

#include "media/types.h"

using namespace std;

const int arraySize = 50;

void addMedia(Medium* medium, Medium* media[], int arraySize) {
  int i;
  for (i = 0; i < arraySize; i++) {
    if (media[i] == NULL) {
      media[i] = medium;
      break;
    }
  }
  if (i == arraySize) {
    cerr << "Exeeded array size of " << arraySize << "Elements!" << endl;
  }
}

int main()
{
  char command = 'q';
  Medium* media[arraySize];
  
  // Initialize array with NULL values
  int i;
  for (i = 0; i < arraySize; i++) {
    media[i] = NULL;
  }

  while (true) {
    cout << "What do you want to do?" << endl
            << "m: new medium" << endl
            << "b: new book" << endl
            << "v: new video" << endl
            << "l: list media" << endl
            << "e SIGNATURE: borrow media" << endl
            << "r SIGNATURE: return media" << endl
            << "q: quit" << endl
            << endl
            << "Command: ";
    cin >> command;
    cout << endl;
    
    switch (command) {
      case 'm':
        addMedia(new Medium(), media, arraySize);
        break;
      case 'b':
        addMedia(new Book(), media, arraySize);
        break;
      case 'v':
        addMedia(new Video(), media, arraySize);
        break;
      case 'l':
        cout << "Media Library" << endl;
        int i;
        for (i = 0; i < arraySize; i++) {
          if (media[i] == NULL) {
            break;
          }
          media[i]->print();
        }
        break;
      case 'e':
        //if (medium != NULL) {
        //  medium->lendOut();
        //} else {
        //  cout << "Please enter medium first!" << endl;
        //}
        break;
      case 'r':
        //if (medium != NULL) {
        //  medium->handIn();
        //} else {
        //  cout << "Please enter medium first!" << endl;
        //}
        break;
      case 'q':
        exit(EXIT_SUCCESS);
    }
    cout << endl;
  }
}
