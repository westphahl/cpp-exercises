#include <iostream>
#include <stdlib.h>

#include "utils/utils.h"
#include "media/types.h"

using namespace std;


int main()
{
  char command = 'q';
  Container media_c = Container();
  Medium* media = NULL;
  int signature = 0;

  while (true) {
    cout << "What do you want to do?" << endl
         << "m: create new medium" << endl
         << "b: create new book" << endl
         << "v: create new video" << endl
         << "l: list all media" << endl
         << "e SIGNATURE: borrow media with the given signature" << endl
         << "r SIGNATURE: return media with the given signature" << endl
         << "d SIGNATURE: delete media with the given signature" << endl
         << "q: quit" << endl
         << endl
         << "Command: ";
    cin >> command;
    cout << endl;
    
    switch (command) {
      case 'm':
        media_c.add(new Medium());
        break;
      case 'b':
        media_c.add(new Book());
        break;
      case 'v':
        media_c.add(new Video());
        break;
      case 'l':
        cout << "Media Library" << endl;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) media->print();
        break;
      case 'e':
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            media->lendOut();
          }
        }
        break;
      case 'r':
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            media->handIn();
          }
        }
        break;
      case 'd':
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            media_c.remove();
          }
        }
        break;
      case 'q':
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) media_c.remove();
        exit(EXIT_SUCCESS);
    }
    cout << endl;
  }
}
