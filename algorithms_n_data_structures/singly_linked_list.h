#pragma once
template<class T>
struct SNode {
	T value;
	SNode<T>* next;

	SNode(T val, SNode<T>* n) {
		value = val;
		next = n;
	}
};

template<class T>
struct SearchResult {
	T value;
	bool found;
};

template<class T>
class singly_linked_list
{
public:
	singly_linked_list();
	~singly_linked_list();
	SNode<T>* PushFront(T);
	SNode<T>* PushBack(T);
	T PopFront();
	T PopBack();
	T GetFront();
	T GetBack();
	SearchResult<SNode<T>*> Search(T);
	bool Remove(T);
	bool RemoveNode(SNode<T>*);
	void Clear();
	SNode<T>* InsertBefore(SNode<T>*, T);
	SNode<T>* InsertAfter(SNode<T>*, T);
	bool Empty();
private:
	SNode<T>* head;
	SNode<T>* tail;
};

template<class T>
singly_linked_list<T>::singly_linked_list()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
singly_linked_list<T>::~singly_linked_list()
{
}

template<class T>
SNode<T>* singly_linked_list<T>::PushFront(T key) {
	SNode<T>* node = new SNode<T>(key, head);
	head = node;
	if (tail == nullptr)
		tail = head;
	return node;
}

template<class T>
SNode<T>* singly_linked_list<T>::PushBack(T key) {
	SNode<T>* node = new SNode<T>(key, nullptr);
	tail = node;

	if (head == nullptr)
		head = tail;

	//the O(n) stuff
	SNode<T>* current = head;
	while (current->next != nullptr)
		current = current->next;
	current->next = node;

	return node;
}

template<class T>
SNode<T>* singly_linked_list<T>::InsertAfter(SNode<T>* node, T key) {
	SNode<T>* newNode = new SNode<T>(key, node->next);
	node->next = newNode;
	return newNode;
}

template<class T>
SNode<T>* singly_linked_list<T>::InsertBefore(SNode<T>* node, T key) {
	SNode<T>* newNode = new SNode<T>(key, node);

	//the O(n) stuff
	SNode<T>* current = head;
	while (current->next != node && current->next != nullptr)
		current = current->next;

	if (current->next == node)
		current->next = newNode;

	return newNode;
}

template<class T>
T singly_linked_list<T>::PopFront() {
	T key = head->value;
	SNode<T>* next = head->next;
	if (tail == head)
		tail = nullptr;
	delete head;
	head = next;
	return key;
}

template<class T>
T singly_linked_list<T>::PopBack() {
	T key = tail->value;
	SNode<T>* prev = head;
	// O(n)
	while (tail != head && prev->next != tail)
		prev = prev->next;
	delete tail;
	tail = prev;
	prev->next = nullptr;
	return key;
}

template<class T>
bool singly_linked_list<T>::RemoveNode(SNode<T>* node) {
	SNode<T>* next_node = node->next;
	SNode<T>* prev_node = head;
	// the O(n) stuff
	while (prev_node->next != node && prev_node->next != nullptr)
		prev_node = prev_node->next;
	
	if (prev_node->next == node) {
		prev_node->next = next_node;
		delete node;
		return true;
	}
	else {
		return false; // Node not from this List
	}
}

template<class T>
T singly_linked_list<T>::GetFront() {
	T key = head->value;
	return key;
}

template<class T>
T singly_linked_list<T>::GetBack() {
	T key = tail->value;
	return key;
}

template<class T>
void singly_linked_list<T>::Clear() {
	while (!Empty())
		PopFront();
}

template<class T>
SearchResult<SNode<T>*> singly_linked_list<T>::Search(T key) {
	SearchResult<SNode<T>*> result;
	result.found = false;

	if (!Empty()) {
		SNode<T>* current = head;
		while (current != nullptr) {
			if (current->value == key) {
				result.value = current;
				result.found = true;
				break;
			}
			current = current->next;
		}
	}
	return result;
}

template<class T>
bool singly_linked_list<T>::Remove(T key) {
	SearchResult<SNode<T>*> s = Search(key);
	if (s.found) {
		return RemoveNode(s.value);
	}
	else {
		return false;
	}

}

template<class T>
bool singly_linked_list<T>::Empty() {
	return tail == head && head == nullptr;
}