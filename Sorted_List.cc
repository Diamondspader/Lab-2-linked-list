# include "Sorted_List.h"

Sorted_List::Sorted_List():
    first{}, last{}
{

  first = new Element{};
  last = new Element{};
}

Sorted_List::Sorted_List(int x):
    first{}, last{}
{
  first = new Element{};
  last = new Element{};

}

Sorted_List::insert(const int& x)
{
  Element e = new Element{x};

}
