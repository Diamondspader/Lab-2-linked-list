#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <initializer_list>



//pointer = memory adress of another var
//reference = another name for the same var
//a = 10    sätter a till 10
//*p = &a   minneadressen *p innehåller var a :edit *p and a will be edited




class Sorted_List
{

public:
  Sorted_List();
  Sorted_List(int x);

  insert(const int& x);


private:
  class Element
  {
  public:
    Element(Element prev, Element next, int val);
    Element():previous{nullptr}, next{nullptr};

    Element* previous{nullptr};
    Element* next{nullptr};
    int value{};
  };
  Element* first{};
  Element* last{};
};








#endif
