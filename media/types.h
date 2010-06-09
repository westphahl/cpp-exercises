#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <string>
#include <iostream>

const int columnWidth = 10;
const int titleLimit = 20;


class Medium
{
  public:
    Medium();
    Medium(int i) {};
    std::string getType();
    std::string getTitle();
    bool isAvailable();
    virtual void print();
    virtual ~Medium() {};
    void borrow();
    void handBack();
    int getSignature();
  protected:
    int signature_;
    std::string type_;
    std::string title_;
    bool status_;
    int readSignature();
    std::string readTitle();
};


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
    float readLength();
};

#endif
