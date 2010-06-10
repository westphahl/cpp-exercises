#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

#include "../media/types.h"


typedef Medium ITEM;

class c_element
{
  ITEM* item;
  c_element* previous;
  c_element* next;
  friend class Container;
};


class Container
{
  public:
    Container();
    bool add(ITEM* newItem);
    bool remove();
    void begin();
    void next();
    ITEM* getItem();
  protected:
    c_element* head_;
    c_element* tail_;
    c_element* current_;
};

#endif
