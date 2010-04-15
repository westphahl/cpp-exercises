#include <string>
#include <iostream>
#include <iomanip>

#include "types.h"

using namespace std;

Book::Book() : Medium(0)
{
  cout << "Please enter info for book: signature, pages and title" << endl;
  type_ = "Book";
  status_ = true;
  signature_ = readSignature();
  pages_ = readPages();
  title_ = readTitle();
}

int Book::readPages()
{
  int pages = 0;

  cout << "Pages: ";
  while (!(cin >> pages)) {
    cin.clear();
    cin.ignore(999, '\n');
    cerr << "Error: Please enter only integers." << endl;
  }
  return pages;
}

void Book::print()
{
  cout << right
       << setw(columnWidth * 0.8) << signature_
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << type_
       << setw(columnWidth * 2.5) << title_
       << setw(columnWidth) << boolalpha
       << setw(columnWidth) << status_ 
       << "Pages " << pages_ << endl;
}
