#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <vector>
//#include <initializer_list>
//Least requirements:
//Sorted Insert (doublets allowed) *done*
//deletion
//search
//write as output on a sstream
//if index out of range, give exception

class Sorted_List
{
public:
  Sorted_List();


  void Insert(int x);
  void print();
  int get_val(){return val;};

private:

  class Element
  {
  public:
    Element(Element* prev, Element* next, int value):
            previous{prev}, next{next}, value{value}{};
    Element* previous{nullptr};
    Element* next{nullptr};
    int value{};
  };

  Element* first{nullptr};
  Element* last{nullptr};
  int val{};

};








#endif
