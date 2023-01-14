//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	dataItems = new DataType[maxNumber];
	size = 0;
	cursor = -1;
	maxSize = maxNumber;
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	delete [] dataItems;

}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
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
	if (cursor == size - 1 && size > 0) {
		dataItems[cursor] = 0;
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
	if (!isEmpty()) {
		dataItems[cursor] = newDataItem;
	}
	else  cout << "Failed -- List is Empty" << endl;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	for (int i = 0; i < size; i++) {
		dataItems[i] = 0;
	}
	cursor = -1;
	size = 0;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	if (size == 0) {
		return true;
	}
	else return false;
	
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	if (size == maxSize) {
		return true;
	}
	else return false;

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
	if (!isEmpty()) {
		return dataItems[cursor];
	}
	else  cout << "Failed -- List is Empty" << endl; return 0;
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
    // pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n)
{
	char c;
	if (n < cursor && n >- 1) {
		c = dataItems[cursor];
		for (int i = cursor; i > n; i--) {
			dataItems[i] = dataItems[i - 1];
		}
		dataItems[n] = c;
		cursor = n;
	}
	else if (n > cursor && n < size) {
		c = dataItems[cursor];
		for (int i = cursor; i < n; i++) {
			dataItems[i] = dataItems[i + 1];
		}
		dataItems[n] = c;
		cursor = n;
	}
}

bool List::find(const DataType& searchDataItem)
{
	for (int i = cursor; i < size; i++) {
		if (dataItems[i] == searchDataItem) {
			cursor = i;
			return true;
		}
	}
	cursor = size - 1;
	return false;
}
