// Header file for Unsorted List ADT.  

#define NULL 0

template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
	SortedType();     // Class constructor	
	~SortedType();    // Class destructor

	bool isFull() const;
	// Determines whether list is full.
	// Post: Function value = (list is full)

	int  LengthIs() const;
	// Determines the number of elements in list.
	// Post: Function value = number of elements in list.

	void MakeEmpty();
	// Initializes list to empty state.
	// Post:  List is empty.

	void RetrieveItem(ItemType& item, bool& found);
	// Retrieves list element whose key matches item's key 
	// (if present).
	// Pre:  Key member of item is initialized.
	// Post: If there is an element someItem whose key matches 
	//       item's key, then found = true and item is a copy 
	//       of someItem; otherwise found = false and item is 
	//       unchanged. 
	//       List is unchanged.

	bool InsertItem(ItemType item);
	// Adds item to list.
	// Pre:  List is not full.
	//       item is not in list. 
	// Post: item is in list.

	bool DeleteItem(ItemType item);
	// Deletes the element whose key matches item's key.
	// Pre:  Key member of item is initialized.
	//       One and only one element in list has a key matching
	//       item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Initializes current position for an iteration through the
	// list.
	// Post: Current position is prior to list.

	void GetNextItem(ItemType&);
	// Gets the next element in list.
	// Pre:  Current position is defined.
	//       Element at current position is not last in list.
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.

private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}

template<class ItemType>
bool SortedType<ItemType>::isFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	NodeType<ItemType>* location;
	try
	{
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType<ItemType>* tempPtr;
	int length = LengthIs();
	for (int i = 0; i < length; i++)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item,
	bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (location->info < item)
		{//����Ʈ�� �����ʹϱ� 
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
			moreToSearch = false;
	}
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
	currentPos = NULL;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
	if (currentPos == NULL)
		currentPos = listData;
	item = currentPos->info;
	currentPos = currentPos->next;

}

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
	MakeEmpty();
}

// This file contains the code for the routines in the text.
// It is not complete and will not compile.

template<class ItemType>
void FindItem(NodeType<ItemType>* listData,
	ItemType item,
	NodeType<ItemType>*& location,
	NodeType<ItemType>*& predLoc,
	bool& found)
	// Assumption: ItemType is a type for which the operators ''<'' and
	//      "==" are defined as either an appropriate built-in type or a
	//      class that overloads these operations.
	// Pre: List is not empty.
	// Post:If there is an element someItem whose key matches item's
	//      key, then found = true; otherwise, found = false.
	//      If found, location contains the address of someItem and
	//      predLoc contains the address of someItem's predecessor;
	//      otherwise, location contains the address of item's logical
	//      successor and predLoc contains the address of item's
	//      logical predecessor.
{
	bool moreToSearch = (location != NULL);

	location = listData;
	predLoc = NULL;
	found = false;

	while (moreToSearch && !found)
	{
		if (item < location->info)
			moreToSearch = false;
		else if (item == location->info)
			found = true;
		else
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
}

template<class ItemType>
bool SortedType<ItemType>::InsertItem(ItemType item)
{
	if (isFull())
		return false;
	//���� ���� ������� �׸��� �߰��� ����� 
	NodeType<ItemType>* newNode;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* location;
	bool found;

	newNode = new NodeType<ItemType>;
	newNode->info = item;
	if (listData != NULL)
	{
		if (listData->info > item) // item is smallest
		{
			newNode->next = listData;
			listData = newNode;
		}
		else
		{
			FindItem(listData, item, location, predLoc, found);
			newNode->next = predLoc->next;
			predLoc->next = newNode;
		}
	}
	else // Inserting into an empty list.
	{
		listData = newNode;
		newNode->next = NULL;
	}
	length++;

	return true;
}

template<class ItemType>
bool SortedType<ItemType>::DeleteItem(ItemType item)
{
	if (listData == NULL)
		return false;

	NodeType<ItemType>* location;
	NodeType<ItemType>* predLoc;
	bool found;

	FindItem(listData, item, location, predLoc, found);
	if (predLoc == location) // Only node in list?
		listData = NULL;
	else
	{
		predLoc->next = location->next;
		if (location == listData) // Deleting last node in list?
			listData = predLoc;
	}
	delete location;
	length--;

	return true;
}
