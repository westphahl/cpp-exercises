#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

#include "types.h"

using namespace std;


Book::Book() : Medium(0)
{
  cout << "Please enter info for book: signature, pages and title" << endl;
  type_ = "Book";
  status_ = available;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Error: Please enter only integers." << endl;
  }
  return pages;
}

void Book::print()
{
  cout << right
       << setw(columnWidth * 1) << signature_
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << type_
       << setw(columnWidth * 2.5) << title_.substr(0, titleLimit)
       << setw(columnWidth) << boolalpha;
  if (status_ == true) {
    cout << setw(columnWidth) << "avail.";
  } else {
    cout << setw(columnWidth) << "unavail.";
  }
  cout << "Pages " << pages_ << endl;
}
