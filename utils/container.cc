#include "utils.h"

Container::Container()
{
  head_ = NULL;
  tail_ = NULL;
  current_ = NULL;
}

bool Container::add(ITEM* newItem)
{
  C_ELEMENT* newElement = new C_ELEMENT;
  if (tail_ != NULL) {
    tail_->next = newElement;
  } else {
    head_ = newElement;
  }
  newElement->item = newItem;
  newElement->last = tail_;
  newElement->next = NULL;
  tail_ = newElement;
  return true;
}

bool Container::remove()
{
  C_ELEMENT* oldElement = current_;
  current_ = oldElement->next;
  if (current_ != NULL) {
    current_->last = oldElement->last;
  } else {
    tail_ = oldElement->last;
  }
  current_ = oldElement->last;
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
