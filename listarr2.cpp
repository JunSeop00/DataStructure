//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr2.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	// pre-lab
	size = 0;
	cursor = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
	
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (size < maxSize) {
		for (int i = size - 1; i > cursor; i--) {
			dataItems[i + 1] = dataItems[i];
		}
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else cout << "Failed -- List is Full" << endl;
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (cursor == size - 1 && size > 0) {
		dataItems[cursor].setKey(0);
		size--;
		if (size == 0) {
			cursor = -1;
		}
		else cursor = 0;

	}
	else if (cursor >= 0 && size > 0) {
		for (int i = cursor; i < size - 1; i++) {
			dataItems[i] = dataItems[i + 1];
		}
		size--;
	}
	else  cout << "Failed -- List is Empty" << endl;
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (!isEmpty()) {
		dataItems[cursor] = newDataItem;
	}
	else  cout << "Failed -- List is Empty" << endl;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	for (int i = 0; i < size; i++) {
		dataItems[i].setKey(0);
	}
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	// pre-lab
	if (size == 0) {
		return true;
	}
	return false;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	// pre-lab
	if (size == maxSize) {
		return true;
	}
	return false;
}

//--------------------------------------------------------------------

void List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	if (!isEmpty()) {
		cursor = 0;
	}
	else cout << "Failed -- List is Empty" << endl;

}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (!isEmpty()) {
		cursor = size - 1;
	}
	else cout << "Failed -- List is Empty" << endl;
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (cursor < size - 1) {
		cursor++;
		return true;
	}
	else return false;
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (cursor > 0) {
		cursor--;
		return true;
	}
	else return false;
}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor.

{
	// pre-lab
	if (!isEmpty()) {
		return dataItems[cursor];
	}
	

}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	int j;   // Loop counter

	if (size == 0)
		cout << "Empty list" << endl;
	else
	{
		cout << "size = " << size
			<< "   cursor = " << cursor << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << dataItems[j].getKey() << "\t";
		cout << endl;
	}
}