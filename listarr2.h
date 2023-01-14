//--------------------------------------------------------------------
//
//  Laboratory 4                                          listarr2.h
//
//  Class declaration for the array implementation of the List ADT
//  (Laboratory 3) with modifications to support inheritance by the
//  array implementation of the Ordered List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARR2_H
#define LISTARR2_H

#include <iostream>

using namespace std;

struct DataType
{
    char key;

    void setKey(char newKey) { key = newKey; }
    char getKey() const { return key; }
};

const int defMaxListSize = 10;   // Default maximum list size

class List
{
  public:

    // Constructor
    List ( int maxNumber = defMaxListSize );

    // Destructor
    ~List ();

    // List manipulation operations
    virtual void insert(const DataType& newDataItem);  // Insert
    void remove();                                       // Remove
    virtual void replace(const DataType& newDataItem); // Replace
    void clear();                                       // Clear list

    // List status operations
    bool isEmpty() const;                    // List is empty
    bool isFull() const;                     // List is full

    // List iteration operations
    void gotoBeginning();                    // Go to beginning
    void gotoEnd();                          // Go to end
    bool gotoNext();                         // Go to next element
    bool gotoPrior();                        // Go to prior element
    DataType getCursor() const;              // Return element

    // Output the list structure -- used in testing/debugging
    void showStructure() const;

  protected:

    // Data members
    int maxSize,    // Maximum number of elements in the list
        size,       // Actual number of elements in the list
        cursor;     // Cursor array index
    DataType *dataItems;  // Array containing the list elements
};

#endif // #ifndef LISTARR2_H

