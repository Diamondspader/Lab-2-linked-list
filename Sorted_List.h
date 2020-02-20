#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <sstream>
#include <initializer_list>

class Sorted_List
{
public:
  Sorted_List();
  Sorted_List(const std::initializer_list<int>);
  Sorted_List(const Sorted_List & rhs);
  ~Sorted_List();


  int At(const int & key) const;
  void Insert(const int & x);
  void RemoveAt(const int & key);
  void Clear();
  int Size() const;

  Sorted_List& operator = (const Sorted_List & rhs);
  Sorted_List& operator = (Sorted_List && rhs);
  Sorted_List(Sorted_List && rhs);

private:

  class Element
  {
  public:
    Element();
    Element(int value);
    Element(Element* prev, Element* next, int value):
            previous{prev}, next{next}, value{value}{};

    Element* previous{nullptr};
    Element* next{nullptr};
    int value{};
  };

  Element* first{nullptr};
  Element* last{nullptr};
};

std::ostream& operator<<(std::ostream& os, const Sorted_List& list);

#endif
