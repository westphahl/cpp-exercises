#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <string>


const int columnWidth = 15;

class Medium
{
  public:
    Medium();
    std::string getType();
    std::string getTitle();
    bool isAvailable();
    virtual void print();
    virtual ~Medium() {};
    void lendOut();
    void handIn();
  private:
    int signature_;
    std::string type_;
    std::string title_;
    bool status_;
    int getSignature();
    int readSignature();
    std::string readTitle();
};

/*
class Book: public Medium
{
  public:
    Book();
    void print();
  private:
    int pages_;
    int readPages();
};


class Video: public Medium
{
  public:
    Video();
    void print();
  private:
    float length_;
    int readLength();
};
*/

#endif
