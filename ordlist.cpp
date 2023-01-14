#include "ordlist.h"

OrdList::OrdList(int maxNumber)
{
	size = 0;
	cursor = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
}

void OrdList::insert(const DataType& newDataItem)
{
	int copyCursor = cursor;
	if (isFull()) {
		cout << "Failed -- List is Full" << endl;
	}
	else
	{
		if (!binarySearch(newDataItem.getKey(), cursor)) {
			for (int i = size - 1; i > cursor; i--) {
				dataItems[i + 1] = dataItems[i];
			}
			dataItems[++cursor] = newDataItem;
			size++;
		}
		else cursor = copyCursor;
	}
}

void OrdList::replace(const DataType& newDataItem)
{
	if (size == 0) {
		cout << "Failed -- List is Empty" << endl;
	}
	if (dataItems[cursor].getKey() == newDataItem.getKey()) {
		dataItems[cursor] = newDataItem;
	}
	else {
		remove();
		insert(newDataItem);
	}
	
}

bool OrdList::retrieve(char searchKey, DataType& searchDataItem)
{
	int copyCursor;
	copyCursor = cursor;
	
	if (binarySearch(searchKey, cursor)) {
		searchDataItem.setKey(searchKey);
		return true;
	}
	else {
		cursor = copyCursor;  return false;
	}
}

bool OrdList::binarySearch(char searchKey, int& index)
{
	int low = 0;
	int high = size - 1;
	while (low <= high) {
		index = (low + high) / 2;
		if (searchKey < dataItems[index].getKey()) {
			high = index - 1;
		}
		else if (searchKey > dataItems[index].getKey()) {
			low = index + 1;
		}
		else break;
	}
	if (low <= high) {
		return true;
	}
	else {
		index = high;
		return false;
	}
}

//--------------------------------------------------------------------


void OrdList::merge(const OrdList& fromL)
{
	for (int i = 0; i < fromL.size; i++) {
		this->insert(fromL.dataItems[i]);
	}
}

bool OrdList::isSubset(const OrdList& subL)
{
	int num = 0;
	for (int i = 0; i < subL.size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (subL.dataItems[i].getKey() == this->dataItems[j].getKey()) {
				num = 0;
				break;
			}
			else num = 1;
		}
		if (num == 1) {
			return false;
		}
	}
	return true;
}
