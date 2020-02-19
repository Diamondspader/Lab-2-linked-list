# include "Sorted_List.h"
#include <vector>
Sorted_List::Sorted_List():
       first{nullptr}, last{nullptr}
{
}

Sorted_List::Sorted_List(int x, int y, int z):
       first{nullptr}, last{nullptr}, val{}
{
  Insert(x);
  val = first->value;
}

void Sorted_List::Insert(int x)
{
  Element* temp{first};
  if(first == last)
  {
    first = new Element{first, last, x};
    return;
  }

  if(x < temp->value && temp->previous == nullptr)
  {
    first = new Element{nullptr, temp, x};
    temp->previous = first;
    return;
  }
  do{
    if(x > temp->value && temp->next == last)
    {
      temp->next = new Element{temp, last, x};
      return;
    }

    if(x >= temp->value && x <= temp->next->value)
    {
      temp->next->previous = new Element{temp, temp->next, x};
      temp->next = temp->next->previous;

      return;
    }
    temp = temp->next;
  }while(temp != last);
}

void Sorted_List::delete(int key)
{
  
}



void Sorted_List::printall()
{
  printList.push_back(first->value);
  printList.push_back(first->next->value);
  printList.push_back(first->next->next->value);
  printList.push_back(first->next->next->next->value);
  printList.push_back(first->next->next->next->next->value);
  printList.push_back(first->next->next->next->next->next->value);
  printList.push_back(first->next->next->next->next->next->next->value);
  printList.push_back(first->next->next->next->next->next->next->previous->value);
  printList.push_back(first->next->next->next->next->next->next->previous->previous->value);
  printList.push_back(first->next->next->next->next->next->next->previous->previous->previous->value);
  printList.push_back(first->next->next->next->next->next->next->previous->previous->previous->previous->value);
  printList.push_back(first->next->next->next->next->next->next->previous->previous->previous->previous->previous->value);
  printList.push_back(first->next->next->next->next->next->next->previous->previous->previous->previous->previous->previous->value);

}
