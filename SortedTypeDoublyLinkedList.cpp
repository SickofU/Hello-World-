#include<iostream>
using namespace std;

template<class ItemType>
struct NodeType {
	ItemType info;
	NodeType<ItemType>* next;
	NodeType<ItemType>* back;
};
template<class ItemType>
class Doublylist {
public:
	Doublylist() {
		length = 0;
		listData = NULL;
	}
	void InsertItem(ItemType item) {
		NodeType<ItemType>* newNode;
		NodeType<ItemType>* location;
		bool found;
		newNode = new NodeType<ItemType>;
		newNode->info = item;
		if (listData != NULL) {
			FindItem(listData, item, location, found);
			if (location->info > item) {
				newNode->back = location->back;
				newNode->next = location;
				if (location != listData)
					location->back->next = newNode;
				else
					listData = newNode;
				location->back = newNode;
			}
			else {
				//insert at the end
				newNode->back = location;
				location->next = newNode;
				newNode->next = NULL;
			}


		}
		else {
			//insert into an empty list
			listData = newNode;
			newNode->next = NULL;
			newNode->back = NULL;
		}
		length++;
	}
private:
	NodeType<ItemType>* listData;
	int length;
};

template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, bool& found) {
	bool moreToSearch = true;
	location = listData;
	found = false;
	while (moreToSearch && !found) {
		if (item < location->info)
			moreToSearch = false;
		else if (item == location->info)
			found = true;
		else {
			location = location->next;
			moreToSearch = (location != NULL);
		}



	}

}

int main() {

}