#include <iostream>
#include <iomanip>

#include "types.h"

using namespace std;

Medium::Medium()
{
  cout << "Please enter info for medium: signature and title" << endl;
  type_ = "Medium";
  status_ = true;
  signature_ = readSignature();
  title_ = readTitle();
}

int Medium::readSignature()
{
  int signature = 0;

  cout << "Signature: ";
  while (!(cin >> signature)) {
    cin.clear();
    cin.ignore(999, '\n');
    cerr << "Error: Please enter only integers." << endl;
  }
  return signature;
}

string Medium::readTitle()
{
  string title = "";
  
  cin.ignore();
  cout << "Title: ";
  getline(cin, title);
  return title;
}

void Medium::lendOut()
{
  if (status_ == true) {
    status_ = false;
  } else {
    cout << "Sorry, medium not available!" << endl;
  }
}

void Medium::handIn()
{
  if (status_ == false) {
    status_ = true;
    cout << "Thank your for returning this media!" << endl;
  } else {
    cout << "You already returned this media." << endl;
  }
}

void Medium::print()
{
  cout << right
       << setw(columnWidth * 0.8) << signature_
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << type_
       << setw(columnWidth * 2.5) << title_
       << setw(columnWidth) << boolalpha 
       << status_ << endl;
}
