#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include "types.h"

using namespace std;


StatusError::StatusError(string source)
{
  source_ = source;
}

string StatusError::message()
{
  ostringstream os;
  os << "Error on borrowing/returning '" << source_ << "'.";
  return os.str();
}

Medium::Medium()
{
  cout << "Please enter info for medium: signature and title" << endl;
  type_ = "Medium";
  status_ = available;
  signature_ = readSignature();
  title_ = readTitle();
}

int Medium::readSignature()
{
  int signature = 0;

  cout << "Signature: ";
  while (!(cin >> signature)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Error: Please enter only integers." << endl;
  }
  return signature;
}

int Medium::getSignature()
{
  return signature_;
}

string Medium::readTitle()
{
  string title = "";
  
  cin.ignore();
  cout << "Title: ";
  getline(cin, title);
  return title;
}

void Medium::borrow()
{
  if (status_ == available) {
    status_ = unavailable;
  } else {
    throw StatusError(title_);
  }
}

void Medium::handBack()
{
  if (status_ == unavailable) {
    status_ = available;
    cout << "Thank your for returning this media!" << endl;
  } else {
    throw StatusError(title_);
  }
}

void Medium::printTitles()
{
  cout << right
       << setw(columnWidth * 1) << "Signature"
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << "Type"
       << setw(columnWidth * 2.5) << "Title"
       << setw(columnWidth) << "Status"
       << setw(columnWidth) << "Furter Information" << endl;
}

void Medium::print()
{
  cout << right
       << setw(columnWidth * 1) << signature_
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << type_
       << setw(columnWidth * 2.5) << title_.substr(0, titleLimit)
       << setw(columnWidth) << boolalpha;
  if (status_ == available) {
    cout << setw(columnWidth) << "avail." << endl;
  } else {
    cout << setw(columnWidth) << "unavail." << endl;
  }
}
