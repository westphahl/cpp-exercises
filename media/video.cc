#include <string>
#include <iostream>
#include <iomanip>

#include "types.h"

using namespace std;

Video::Video() : Medium(0)
{
  cout << "Please enter info for video: signature, length and title" << endl;
  type_ = "Video";
  status_ = true;
  signature_ = readSignature();
  length_ = readLength();
  title_ = readTitle();
}

float Video::readLength()
{
  float length = 0;

  cout << "Length: ";
  while (!(cin >> length)) {
    cin.clear();
    cin.ignore(999, '\n');
    cerr << "Error: Please enter only float values." << endl;
  }
  return length;
}

void Video::print()
{
  cout << right
       << setw(columnWidth * 0.8) << signature_
       << setw(columnWidth * 0.5) << " "
       << left
       << setw(columnWidth) << type_
       << setw(columnWidth * 2.5) << title_
       << setw(columnWidth) << boolalpha;
  if (status_ == true) {
    cout << setw(columnWidth) << "avail.";
  } else {
    cout << setw(columnWidth) << "unavail.";
  }
  cout << "Length " << setprecision(2) << fixed << length_ << " min" << endl;
}
