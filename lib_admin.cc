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
        // Add medium.
        if (!media_c.add(new Medium())) exit(EXIT_FAILURE);
        break;
      case 'b':
        // Add book.
        if (!media_c.add(new Book())) exit(EXIT_FAILURE);
        break;
      case 'v':
        // Add video.
        if (!media_c.add(new Video())) exit(EXIT_FAILURE);
        break;
      case 'l':
        // List all media.
	      Medium::printTitles();
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) media->print();
        break;
      case 'e':
        // Borrow medium with given signature.
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            try {
              media->borrow();
            }
            catch (StatusError e) {
              cout << e.message() << endl;
            }
          }
        }
        break;
      case 'r':
        // Return medium with given signature.
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            try {
              media->handBack();
            }
            catch (StatusError e) {
              cout << e.message() << endl;
            }
          }
        }
        break;
      case 'd':
        // Delete medium with given signature.
        cin >> signature;
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) {
          if (media->getSignature() == signature) {
            if (!media_c.remove()) exit(EXIT_FAILURE);
            delete media;            
          }
        }
        break;
      case 'q':
        // On exit remove all container elements.
        for (media_c.begin();
            (media = media_c.getItem()) != NULL;
             media_c.next()) media_c.remove();
        exit(EXIT_SUCCESS);
    }
    cout << endl;
  }
}
