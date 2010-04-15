#include <string>
#include <iostream>
#include <iomanip>

#include "types.h"

using namespace std;

Medium::Medium()
{
  type_ = "Medium";
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
  cout << left
       << setw(columnWidth * 1.5) << "Signature"
       << setw(columnWidth) << "Type"
       << std::setw(columnWidth * 3) << "Title"
       << setw(columnWidth) << "Available" << endl;
  cout << left
       << setw(columnWidth * 1.5) << signature_
       << setw(columnWidth) << type_
       << setw(columnWidth * 3) << title_
       << setw(columnWidth) << boolalpha 
       << status_ << endl;
}
