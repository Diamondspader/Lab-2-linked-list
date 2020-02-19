# include "Sorted_List.h"
#include <iostream>
Sorted_List::Sorted_List():
       first{nullptr}, last{nullptr}
{
}


void Sorted_List::Insert(int x)
{
  Element* newElem = new Element{nullptr, nullptr, x};
  Element* temp{first};
  if(first == nullptr)
  {
    first = newElem;
    //delete newElem;
    return;
  }
  //insert at front
  if(x < first->value && first->previous == nullptr)
  {
    first->previous = newElem;
    newElem->next = first;
    first = newElem;
    //delete newElem;
    return;
  }
  //insert at the end
  while(temp != last)
  {
    if(x > temp->value && temp->next == last)
    {
      temp->next = newElem;
      newElem->previous = temp;
      newElem->next = last;
      //delete newElem;
      return;
    }

    if(x > temp->value && x < temp->next->value)
    {
      temp->next->previous = newElem;
      newElem->next = temp->next;
      newElem->previous = temp;
      temp->next = newElem;
      //delete newElem;
      return;
    }

    temp = temp->next;
  }
}

void Sorted_List::print()
{
  Element* temp{first};
  while(temp != last)
  {
    std::cout << temp->value << '\n';
    temp = temp->next;
  }
}
