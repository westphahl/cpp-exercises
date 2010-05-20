#include <new>

#include "utils.h"

using namespace std;

Container::Container()
{
  head_ = NULL;
  tail_ = NULL;
  current_ = NULL;
}

bool Container::add(ITEM* newItem)
{
  // Instead of throwing bad_alloc return a NULL pointer
  C_ELEMENT* newElement = new (nothrow) C_ELEMENT;
  if (newElement == NULL) {
    return false;
  }

  if (tail_ != NULL) {
    tail_->next = newElement;
  } else {
    head_ = newElement;
  }
  newElement->item = newItem;
  newElement->previous = tail_;
  newElement->next = NULL;
  tail_ = newElement;
  return true;
}

bool Container::remove()
{
  if (current_ == NULL) return false;
  
  C_ELEMENT* oldElement = current_;
  current_ = oldElement->next;
  if (current_ != NULL) {
    current_->previous = oldElement->previous;
  } else {
    tail_ = oldElement->previous;
  }
  current_ = oldElement->previous;
  if (current_ != NULL) {
    current_->next = oldElement->next;
  } else {
    head_ = oldElement->next;
  }
  delete oldElement->item;
  delete oldElement;

  return true;
}

void Container::begin()
{
  current_ = head_;
}

void Container::next()
{
  if (current_ != NULL) current_ = current_->next;
}

ITEM* Container::getItem()
{
  if (current_ != NULL) {
    return current_->item;
  } else {
    return NULL;
  }
}
