#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

#include "../media/types.h"

typedef Medium ITEM;


struct c_element
{
  ITEM* item;
  struct c_element* previous;
  struct c_element* next;
};
typedef struct c_element C_ELEMENT;


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
    C_ELEMENT* head_;
    C_ELEMENT* tail_;
    C_ELEMENT* current_;
};

#endif
