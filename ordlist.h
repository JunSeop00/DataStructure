//--------------------------------------------------------------------
//
//  Laboratory 4                                           ordlist.h
//
//  Class declaration for the array implementation of the Ordered
//  List ADT -- inherits the array implementation of the List ADT
//  (Laboratory 3)
//
//--------------------------------------------------------------------

#ifndef ORDLIST_H
#define ORDLIST_H

#include <iostream>
#include "listarr2.h"

class OrdList : public List
{
  public:

    // Constructor
    OrdList ( int maxNumber = defMaxListSize );

    // Modified (or new) list manipulation operations
    virtual void insert(const DataType& newDataItem);
    virtual void replace(const DataType& newDataItem);
    bool retrieve ( char searchKey, DataType &searchDataItem );

    // In-lab operations
    void merge(const OrdList& fromL);        //in-lab 2
    bool isSubset (const OrdList &subL);     //in-lab 3

  private:

      // Locates an element (or where it should be) based on its key
      bool binarySearch (char searchKey, int &index);
};

#endif // #ifndef ORDLIST_H

