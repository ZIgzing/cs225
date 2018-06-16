#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   // List<int> list1;
   List<int> list1;
   List<int> list2;


  list1.insertFront(8);
  list1.insertFront(7);
  list1.insertFront(6);
  list1.insertFront(5);
  list1.insertFront(4);
  list1.insertFront(3);
  list1.insertFront(2);
  cout << list1 << endl;
  list2.insertFront(11);
  list2.insertFront(10);
  list2.insertFront(8);
  list2.insertFront(7);
  list2.insertFront(3);
  cout << list2 << endl;

  list1.mergeWith(list2);


  cout << list1 << endl;


  return 0;
}
