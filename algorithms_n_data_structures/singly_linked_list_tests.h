#include <iostream>
#include <assert.h>
#include "singly_linked_list.h"

using namespace std;

class SinglyLinkedListTests {
public:
	static void Run() {
		cout << "Singly-Linked List Tests." << endl;
		ComplexTest();
	}

private:
	static void ComplexTest() {
		cout << "Complex Test... ";

		singly_linked_list<int> sll;

		SNode<int>* n3 = sll.PushFront(3);
		sll.PushFront(1);
		sll.PushBack(5);
		sll.PushBack(6);
		sll.InsertAfter(n3, 4);
		sll.InsertBefore(n3, 2);

		assert(sll.PopFront() == 1);
		assert(sll.PopFront() == 2);
		assert(sll.PopFront() == 3);
		assert(sll.PopFront() == 4);
		assert(sll.PopFront() == 5);
		assert(sll.PopFront() == 6);

		cout << "OK" << endl;
	}
};