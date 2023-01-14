//--------------------------------------------------------------------
//
//  Laboratory 4, In-lab Exercises 2 and 3              test4two.cpp
//
//  Test program for the operations in the Ordered List ADT that
//  manipulate two lists.
//
//--------------------------------------------------------------------
#include <iostream>
#include "ordlist.h"

//--------------------------------------------------------------------

int main(void)
{
    OrdList testList1(8),                 // Test lists
            testList2(8);
    DataType testElement;                 // List element
    char ch;                              // Input character

    cout << endl << "Enter first list of characters (no spaces) : ";
    cin.get(ch);
    while ( ch != '\n' )
    {
        testElement.setKey(ch);
        testList1.insert(testElement);
        cin.get(ch);
    }

    cout << endl << "Enter second list of characters (no spaces) : ";
    cin.get(ch);
    while ( ch != '\n' )
    {
        testElement.setKey(ch);
        testList2.insert(testElement);
        cin.get(ch);
    }

    cout << endl << "List 1 : " << endl;
    testList1.showStructure();
    cout << endl << "List 2 : " << endl;
    testList2.showStructure();

  // Merge list 2 into list 1.
  testList1.merge(testList2);
  cout << endl << "After merge -- List 1 : " << endl;
  testList1.showStructure();

//S  // Check whether list 2 is a subset of list 1.
//S cout << endl;
//Sif ( testList1.isSubset(testList2) )
//S   cout << "List 2 is a subset of list 1" << endl;
//Selse
//S    cout << "List 2 is NOT a subset of list 1" << endl;

  system("PAUSE");
  return 0;
}
