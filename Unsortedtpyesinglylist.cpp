#include<iostream>

//unsortedtype singly list�� ��ƺ���.

template<class ItemType>
struct NodeType;

template<class ItemType>
class UnsortedType {
public:
	UnsortedType() {
		length = 0;
		listData = NULL;
		currentPos = NULL;
	}
	~UnsortedType() {
		MakeEmpty();
	}

	bool isFull() const {
		//�̰� ��� full�� �ֳ� ������ �ִ�. �� �Ҵ���� �ʴ´ٸ� full�̴�. �޸� ���� ����
		NodeType<ItemType>* location;
		try {
			location = new NodeType<ItemType>;
			//���� �Ҵ��� �Ǿ��ٴ� ���̴ϱ�
			delete location;
			return false;
		}
		catch (std::bad_alloc exception) {
			return true;
		}
	}
	int LengthIs() const {
		return length;
	}
	void MakeEmpty() {
		//MakeEmpty �Լ��� ������ �ϳ� ��� ������ ���Ҵ� ���鼭 �����ֱ�
		NodeType<ItemType> temp; 
		while (listData != NULL) {
			temp = listData;
			listData = listData->next;
			delete temp;
		}
		length = 0;
	}

	void RetrieveItem(ItemType& item, bool& found) {
		bool moreToSearch;
		NodeType<ItemType>* location;
		location = listData;
		found = false;
		moreToSearch = (location != NULL); 
		//����� ��ġ�� �Ŀ���̷��� �ΰ� �����ؼ� �������ϴ±���
	//����Ž���� �̷��� ���� ���ϱ� �� �˾Ƶ��� �������ġ�� ���ε�
		while (moreToSearch && !found) {
			if (item == location->info) {
				found = true;
				item = location->info;
			}
			else {
				location = location->next; //��ĭ���� �Ѿ��
				moreToSearch = (location != NULL); //�����̼��� ���� �ƴϸ� �� ã��
			}
		}
	}

	bool InsertItem(ItemType item) {
		if (isFull()) {
			return false;
		}
			NodeType<ItemType>* location;
			location = new NodeType<ItemType>;
			location->info = item;
			location->next = listData;
			listData = location;
			length++;

			return true;
	}
	bool DeleteItem(ItemType item) {
		if (listData == NULL)
			return false;
		//����ִٴ� ���̴ϱ�
		NodeType<ItemType>* location = listData;
		NodeType<ItemType>* tempLocation;
	
		if (item == listData->info) {
			tempLocation = location;
			listData = listData->next;
		}
		else {
			while (!(item == (location->next)->info)) {
				if (location == NULL)
					return false;
				location = location->next;
			}
			tempLocation = location->next;
			location->next = (location->next)->next;
		} // ù��° ���� �߰��� ���� �����ϴ� ����� �ٸ�.
		delete tempLocation;
		length--;
		return true;
	}

	void ResetList() {
		//���� ��ġ�� �ʱ�ȭ��. 
		currentPos = NULL;
	}
	void GetNextItem(ItemType& item) {
		//next �������� ���� �������ִ°� &�� ���ؼ�
		if (currentPos == NULL)
			currentPos = listData;
		else
			currentPos = currentPos->next;
		item = currentPos->info; 
	}

private:
	NodeType<ItemType> listData;
	int length;
	NodeType<ItemType>* currentPos;


};

