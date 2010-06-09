#include <iostream>
#include <iomanip>
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
        if (!media_c.add(new Medium())) exit(EXIT_FAILURE);
        break;
      case 'b':
        if (!media_c.add(new Book())) exit(EXIT_FAILURE);
        break;
      case 'v':
        if (!media_c.add(new Video())) exit(EXIT_FAILURE);
        break;
      case 'l':
        cout << right
             << setw(columnWidth * 0.8) << "Signatur"
             << setw(columnWidth * 0.5) << " "
             << left
             << setw(columnWidth) << "Type"
             << setw(columnWidth * 2.5) << "Title"
             << setw(columnWidth) << "Status"
             << setw(columnWidth) << "Furter Information" << endl;
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
            media->borrow();
          }
        }
        break;
      case 'r':
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            media->handBack();
          }
        }
        break;
      case 'd':
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            if (!media_c.remove()) exit(EXIT_FAILURE);
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
