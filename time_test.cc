#include <string>
#include <iostream>
#include <sstream>
#include <utility>
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
    Sorted_List List;
    CHECK(List.Size() == 0);
    List.Insert(1);
    List.Insert(2);
    List.Insert(6);
    CHECK(List.Size()==3);
    CHECK_FALSE(List.Size()==2);

    //Check value
    CHECK(List.At(0)==1);
    CHECK(List.At(2)==6);

    //Check clear
    List.Clear();
    CHECK(List.Size()==0);

}
TEST_CASE ("initializer_list")
{
    Sorted_List l{1,2,3,4};
    CHECK(l.Size()==4);
    l.RemoveAt(0);
    CHECK(l.Size()==3);
    CHECK(l.At(1)==3);
    CHECK(l.At(2)==4);
    l.Clear();
    CHECK(l.Size()==0);

    l.Insert(2);
    CHECK(l.Size()==1);

}
TEST_CASE ("=")
{
    Sorted_List init{1,3,4,6, 8 ,9 ,9};
    Sorted_List final{2,5,7,11};
    init=final;
    CHECK(init.Size()==4);
    CHECK(init.At(3)==11);

}

TEST_CASE ("initialize")
{
    Sorted_List init{1,3,4,6};
    Sorted_List final{init};

    CHECK(final.Size()==4);
    CHECK(final.At(0)==1);
    CHECK(final.At(1)==3);
    CHECK(final.At(2)==4);
    CHECK(final.At(3)==6);

}
TEST_CASE ("stringstream")
{
    stringstream ss;
    Sorted_List init{1,3,4,6};
    ss << init;
    CHECK(ss.str() == "1 3 4 6 ");
}
TEST_CASE ("empty lists")
{
  stringstream ss;
  Sorted_List emptyt{};
  Sorted_List empty{emptyt};
  CHECK_THROWS(empty.At(2));
  CHECK_THROWS(empty.RemoveAt(3));
  empty.Clear();
  ss << empty;
  CHECK(ss.str() == "");
}
TEST_CASE ("swap")
{
  Sorted_List d1{1,4};
  Sorted_List d2{2,9};
  d1 = std::move(d2);
  CHECK(d1.At(0)==2);
  CHECK(d2.At(0)==1);
  CHECK(d1.At(1)==9);
  CHECK(d2.At(1)==4);

}

TEST_CASE("MOVE")
{
  Sorted_List movelist{1,5,93,64};
  Sorted_List list{std::move(movelist)};
  CHECK(list.At(3)==93);

}
// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases


#if 0

#endif
