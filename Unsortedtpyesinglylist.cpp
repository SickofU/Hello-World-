#include<iostream>

//unsortedtype singly list를 깍아보자.

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
		//이게 어떻게 full이 있냐 싶지만 있다. 더 할당되지 않는다면 full이다. 메모리 램의 문제
		NodeType<ItemType>* location;
		try {
			location = new NodeType<ItemType>;
			//새로 할당이 되었다는 뜻이니까
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
		//MakeEmpty 함수가 무엇을 하냐 모든 아이템 비할당 돌면서 지워주기
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
		//모어투 서치랑 파운드이렇게 두개 설정해서 돌려야하는구나
	//이진탐색도 이렇게 보통 쓰니까 잘 알아두자 모어투써치랑 파인드
		while (moreToSearch && !found) {
			if (item == location->info) {
				found = true;
				item = location->info;
			}
			else {
				location = location->next; //담칸으로 넘어가기
				moreToSearch = (location != NULL); //로케이션이 널이 아니면 더 찾기
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
		//비어있다는 뜻이니까
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
		} // 첫번째 노드랑 중간의 노드와 삭제하는 방법이 다름.
		delete tempLocation;
		length--;
		return true;
	}

	void ResetList() {
		//현재 위치가 초기화됨. 
		currentPos = NULL;
	}
	void GetNextItem(ItemType& item) {
		//next 아이템의 값을 변동해주는거 &를 통해서
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

