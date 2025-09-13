#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val)
{
  if(head_ == nullptr){
    // list is empty
    Item* firstItem = new Item();
    head_ = firstItem; 
    tail_ = firstItem; 
    head_->val[head_->first] = val;
    firstItem->last++;
    size_++;
  }
  else{
    if(tail_->last+1 <= ARRSIZE ){ 
      // theres room so add the val
      tail_->val[tail_->last] = val;
      tail_->last = tail_->last+1;
      size_++;
    }
    else{
      // no room so need to alloc a new item
      Item* lastItem = new Item();
      tail_->next = lastItem;
      lastItem->prev = tail_; 
      tail_= lastItem;
      size_++;
      tail_->val[tail_->last] = val;
      tail_->last ++;
    }
  }
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back()
{
  if(head_ == nullptr){
    return;
  }

  tail_->last --;
  size_--;

  // if popping the last remaining elelemnt in an item, remove the item, deallocate
  if(tail_->last - tail_->first == 0){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_!=nullptr){
      tail_->next = nullptr;
    }
    else{
      head_ = nullptr;
    }
    delete temp;
  }
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val)
{
  if(head_ == nullptr){
    // list is empty
    Item* firstItem = new Item();
    head_ = firstItem; 
    tail_ = firstItem; 
    // adding val in the first spot of the array
    head_->val[head_->first] = val;
    firstItem->last++;
    size_++;
    return;
  }
  if(head_->first > 0){
    // theres room so add the val
    head_->first--;
    head_->val[head_->first] = val; 
    size_++;
  }
  else{
    // no room so need to alloc a new item
    Item* firstItem = new Item();
    firstItem ->first = firstItem->last = ARRSIZE;
    head_->prev = firstItem;
    firstItem->next = head_; 
    head_= firstItem;
    
    head_->first --;
    head_->val[head_->first] = val;
    size_++;
  }
  
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front()
{
  if(head_ == nullptr){
    return;
  }

  head_->first++;
  size_--;

  // if popping the last remaining elelemnt in an item, remove the item, deallocate
  if(head_->last == head_->first){
    Item* temp = head_;
    head_ = head_->next;
    if(head_!=nullptr){
      head_->prev = nullptr;
    }
    else{
      tail_ = nullptr;
    }
    delete temp;
  }
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return NULL;
  }

  Item* temp = head_;
  size_t totalIndex = 0;

  while(temp != nullptr){
    size_t numElements = temp->last - temp->first;
    if(loc < numElements + totalIndex){
      size_t indexInItem = loc - totalIndex;
      return &(temp->val[temp->first + indexInItem]);
    }
    totalIndex += numElements;
    temp = temp->next;
  }
  return NULL;

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
