#include "Sorted_List.h"
#include <iostream>

int main()
{

  Sorted_List empty_list{};
  empty_list.Insert(9);
  empty_list.Insert(3);
  empty_list.Insert(5);
  empty_list.Insert(7);
  empty_list.Insert(1);
  empty_list.print();

  return 0;
}
