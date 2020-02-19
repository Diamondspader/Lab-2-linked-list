#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Sorted_List.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Default constructor")
{
    Sorted_List empty_list;
    Sorted_List linked_list{2,5,7};
    CHECK(linked_list.get_value() == 12);
    

}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases


#if 0

#endif
