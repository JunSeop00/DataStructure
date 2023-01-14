//--------------------------------------------------------------------
//
//  Laboratory 4                                           test4.cpp
//
//  Test program for the operations in the Ordered List ADT
//
//--------------------------------------------------------------------

// DataType must be defined before including "ordlist.cpp".


#include <iostream>
#include "ordlist.h"

using namespace std;

//--------------------------------------------------------------------

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H    : Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) element" << endl;
    cout << "  ?key : Retrieve the element with the specified key"
         << endl;
    cout << "  =key : Replace the element marked by the cursor"
         << endl;
    cout << "  -    : Remove the element marked by the cursor"
         << endl;
    cout << "  @    : Display the element marked by the cursor"
         << endl;
    cout << "  <    : Go to the beginning of the list" << endl;
    cout << "  >    : Go to the end of the list" << endl;
    cout << "  N    : Go to the next element" << endl;
    cout << "  P    : Go to the prior element" << endl;
    cout << "  C    : Clear the list" << endl;
    cout << "  E    : Empty list?" << endl;
    cout << "  F    : Full list?" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}

int main(void)
{
    OrdList testList(8);  // Test list
    DataType testElement;               // List element
    char inputKey;                      // User input key
    char cmd;                           // Input command

    print_help();

    do
    {
        testList.showStructure();                     // Output list

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '='  ||  cmd == '?' )
           cin >> inputKey;

        switch ( cmd )
        {
          case 'H' : case 'h':
               print_help();
               break;

          case '+' :                                  // insert
               testElement.setKey(inputKey);
               cout << "Insert : key = " << testElement.getKey()
                    << endl;
               testList.insert(testElement);
               break;

          case '?' :                                  // retrieve
               if ( testList.retrieve(inputKey,testElement) )
                  cout << "Retrieved : key = "
                       << testElement.getKey() << endl;
               else
                  cout << "Not found" << endl;
               break;

          case '=' :                                  // replace
               testElement.setKey(inputKey);
               cout << "Replace current element :"
                    << " key = " << testElement.getKey() << endl;
               testList.replace(testElement);
               break;

          case '-' :                                  // remove
               cout << "Remove current element" << endl;
               testList.remove();
               break;

          case '@' :                                  // getCursor
               cout << "Element marked by the cursor : key = "
                    << testList.getCursor().getKey() << endl;
               break;

          case '<' :                                  // gotoBeginning
               testList.gotoBeginning();
               cout << "Go to beginning of list" << endl;
               break;

          case '>' :                                  // gotoEnd
               testList.gotoEnd();
               cout << "Go to end of list" << endl;
               break;

          case 'N' : case 'n' :                       // gotoNext
               if ( testList.gotoNext() )
                  cout << "Go to next element" << endl;
               else
                  cout << "Failed -- either at end of list "
                       << "or list is empty" << endl;
               break;

          case 'P' : case 'p' :                       // gotoPrior
               if ( testList.gotoPrior() )
                  cout << "Go to the prior element" << endl;
               else
                  cout << "Failed -- either at beginning of list "
                       << "or list is empty" << endl;
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the list" << endl;
               testList.clear();
               break;

          case 'E' : case 'e' :                       // isEmpty
               if ( testList.isEmpty() )
                  cout << "List is empty" << endl;
               else
                  cout << "List is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // isFull
               if ( testList.isFull() )
                  cout << "List is full" << endl;
               else
                  cout << "List is NOT full" << endl;
               break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Invalid command" << endl;
        }
    }
    while ( ( cmd != 'Q' ) && ( cmd != 'q' ) );

    return 0;
}
