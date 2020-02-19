# include "Sorted_List.h"

Sorted_List::Sorted_List():
       first{nullptr},
        last{nullptr}
{

}

Sorted_List::Sorted_List(int x, int y, int z):
        first{nullptr}, last{nullptr}, val{0}
{
  Insert(x);
  val = first->value;
  //Insert(y);
  /*
  Element elem{first, last, x};
  first = &elem;
  val = first->value;

  Element elem2{first, last, y};
  first->next = &elem2;
  val = first->next->previous->value;
  Element elem3{first->next, last, z};
  first->next->next = &elem3;
*/
}
// linkedlist.Insert(5);
void Sorted_List::Insert(int x)
{
  Element* temp{first};
  if(first == nullptr)
  {
    first = new Element{first, last, x};
    return;
  }

  if(x > temp->value && temp->next == nullptr)
  {
    new Element{&temp, last, x};
  }


}
