#include "Sorted_List.h"
#include <iostream>
#include <sstream>

int main()
{
  std::stringstream ss;
  Sorted_List empty_list{1,2,3,4,5};

  //empty_list.Clear();
  empty_list.print();

  std::cout <<"\nthe size of this dig is:" << empty_list.Size() << '\n';
  
   ss << empty_list;
   std::string str;
   ss >> str;
   std::cout << str;
  return 0;
}
