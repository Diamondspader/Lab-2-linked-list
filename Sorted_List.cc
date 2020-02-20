# include "Sorted_List.h"
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <stdexcept>
#include <utility>


Sorted_List::Sorted_List():
       first{nullptr}, last{nullptr}
{
  //construct default
}

Sorted_List::~Sorted_List()
{
  //free memoryspace
  Clear();
}

Sorted_List::Sorted_List(const std::initializer_list<int> v)
{
    for (int i : v)
	   Insert(i);
}

Sorted_List::Sorted_List(const Sorted_List & rhs):
          first{nullptr}, last{nullptr}
{
    if(rhs.first == nullptr)
    {
      return;
    }
    Element* current{};
    Element* rhs_temp{rhs.first};
    first = new Element{nullptr, nullptr, rhs_temp->value};
    current = first;
    rhs_temp = rhs_temp->next;

    while(rhs_temp != nullptr)
    {
        current->next= new Element{current, nullptr, rhs_temp->value};
        current = current->next;
        rhs_temp = rhs_temp->next;
    }
}

//assignment operator
Sorted_List& Sorted_List::operator = (const Sorted_List & rhs)
{
  Sorted_List copy{rhs};
  std::swap(first, copy.first);
  return *this;
}

//move assignment operator
Sorted_List& Sorted_List::operator = (Sorted_List && rhs)
{
    std::swap(first, rhs.first);
    return *this;
}

//move operator
Sorted_List::Sorted_List(Sorted_List && rhs):first{rhs.first}
{
  rhs.first = nullptr;
}

void Sorted_List::Insert(const int & x)
{
  Element* newElem = new Element{nullptr, nullptr, x};
  Element* temp{first};
  if(first == nullptr)
  {
    first = newElem;
    return;
  }
  //insert at front
  if(x < first->value && first->previous == nullptr)
  {
    first->previous = newElem;
    newElem->next = first;
    first = newElem;
    return;
  }
  //insert at the end
  while(temp != last)
  {
    if(x >= temp->value && temp->next == nullptr)
    {
      temp->next = newElem;
      newElem->previous = temp;
      newElem->next = nullptr;
      return;
    }
    //insert in the middle
    else if(x >= temp->value && x <= temp->next->value)
    {
      temp->next->previous = newElem;
      newElem->next = temp->next;
      newElem->previous = temp;
      temp->next = newElem;

      return;
    }
    temp = temp->next;
  }
}

int Sorted_List::Size() const
{
  Element* temp{first};
  int counter{0};
  while(temp!=last)
  {
    counter++;
    temp = temp->next;
  }
  return counter;
}

int Sorted_List::At(const int & key) const
{
  if (Size()<key || key < 0)
  {
    throw std::invalid_argument("out of range");
  }
  Element* temp{first};
  int counter{0};

  while(temp!=last)
  {
    if(counter == key)
    {
      return temp->value;
    }
    temp = temp->next;
    counter++;
  }
  return 0;
}
void Sorted_List::Clear()
{
  while (Size() != 0)
  {
    RemoveAt(0);
  }
}

//remove, brgins at index 0
void Sorted_List::RemoveAt(const int & key)
{
  if (Size() < key || key < 0)
  {
    throw std::invalid_argument("out of range");
  }
  Element* temp{first};

  if(1 == Size())
  {
    delete first;
    first = nullptr;
    return;
  }

  else if(key == 0)
  {
    temp = first->next;
    delete first;
    first = temp;
    first->previous = nullptr;
    return;
  }
  else if (key == Size()-1)
  {
    while  (temp->next != nullptr)
    {
      temp->previous = temp;
      temp = temp->next;
    }
    temp->previous->next=nullptr;
    delete temp;
    return;
  }
  else
  {
    Element* current{temp};

    for (int i{0}; i < key; i++)
    {
      current = temp;
      temp = temp->next;
    }
    temp->next->previous = current;
	  current->next = temp->next;
	  delete temp;
    return;
  }
}

std::ostream& operator<<(std::ostream& os, const Sorted_List& list)
{
  Sorted_List sl{list};
  for(int i{0}; i < sl.Size(); i++)
  {
    os << sl.At(i) << " ";
  }
  return os;
}
