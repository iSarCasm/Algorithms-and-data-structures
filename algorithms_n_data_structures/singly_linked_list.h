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
class singly_linked_list
{
public:
	singly_linked_list();
	~singly_linked_list();
	SNode<T> PushFront(T);
	SNode<T> PushBack(T);
	T PopFront();
	T PopBack();
	//T GetFront();
	//T GetBack();
	//SNode<T> Search(T);
	//bool Remove(T);
	//SNode<T> InsertBefore(SNode<T> node, T value);
	//SNode<T> InsertAfter(SNode<T> node, T value);
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
SNode<T> singly_linked_list<T>::PushFront(T key) {
	SNode<T> node = SNode<T>(key, head);
	head = &node;
	if (tail == nullptr)
		tail = head;
	return node;
}

template<class T>
SNode<T> singly_linked_list<T>::PushBack(T key) {
	SNode<T> node = SNode<T>(key, nullptr);
	tail = &node;
	if (head == nullptr)
		head = tail;
	return node;
}

template<class T>
T singly_linked_list<T>::PopFront() {
	T key = head->value;
	head = head->next;
	return key;
}

template<class T>
T singly_linked_list<T>::PopBack() {
	T key = tail->value;
	tail = head;
	while (tail->next != nullptr)
		tail = tail->next;
	return key;
}

template<class T>
bool singly_linked_list<T>::Empty() {
	return tail == head;
}