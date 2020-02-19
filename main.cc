#include "Sorted_List.h"
#include <iostream>

int main()
{

  Sorted_List empty_list{};
  empty_list.Insert(5);
  empty_list.Insert(1);
  empty_list.Insert(3);
  empty_list.Insert(3);
  empty_list.Insert(7);
  empty_list.Insert(7);
  empty_list.Insert(1);
  empty_list.printall();

  for(int i{0}; i < 14; i++)
  {
    std::cout << empty_list.printList[i] << '\n';
  }

  return 0;
}
