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
  void Insert(int x);
  void Delete(int key);
  Sorted_List();
  Sorted_List(int x, int y, int z);
  int get_value(){return val;};
  std::vector<int> printList;
  void printall();

private:

  class Element
  {
  public:
    Element(Element* prev, Element* next, int val):
            previous{prev}, next{next}, value{val}{}

    Element* previous{nullptr};
    Element* next{nullptr};
    int value{};
  };

  Element* first{};
  Element* last{};
  int val{};

};








#endif
