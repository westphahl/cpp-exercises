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
  c_element* newElement = new (nothrow) c_element;
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
  c_element* oldElement = current_;
  if (current_ == NULL) return false;
   
  current_ = oldElement->next;
  // Check if old element was tail
  if (current_ != NULL) {
    current_->previous = oldElement->previous;
  } else {
    tail_ = oldElement->previous;
  }

  current_ = oldElement->previous;
  // Check if old element was head
  if (current_ != NULL) {
    current_->next = oldElement->next;
  } else {
    head_ = oldElement->next;
    begin();
  }
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
