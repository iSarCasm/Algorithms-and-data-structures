#include <iostream>
#include <assert.h>
#include <ctime>
#include "singly_linked_list.h"

using namespace std;

class SinglyLinkedListTests {
public:
	static void Run(bool with_time) {
		cout << "Singly-Linked List Tests." << endl;
		Complex();
		Clear();
		SearchAndRemove();
		RemoveFromDifferentList();

		if (with_time) {
			// Time tests
			SearchTime1Million();
			SearchTime5Million();
			SearchTime25Million();
		}
	}

private:
	static void Complex() {
		cout << "\t" << "Complex Test... ";

		singly_linked_list<int> sll;

		SNode<int>* n3 = sll.PushFront(3);
		sll.PushFront(1);
		sll.PushBack(5);
		sll.PushBack(6);
		sll.InsertAfter(n3, 4);
		sll.InsertBefore(n3, 2);


		assert(sll.GetFront() == 1);
		assert(sll.GetBack() == 6);

		assert(sll.PopFront() == 1);
		assert(sll.PopFront() == 2);
		assert(sll.PopFront() == 3);
		assert(sll.PopFront() == 4);
		assert(sll.PopBack() == 6);
		assert(sll.PopBack() == 5);

		cout << "\t" << "OK" << endl;
	}

	static void Clear() {
		cout << "\t" << "Clear Test... ";

		singly_linked_list<int> sll;
		sll.PushFront(1);
		assert(sll.Empty() == false);

		sll.Clear();
		assert(sll.Empty() == true);

		cout << "\t" << "OK" << endl;
	}

	static void SearchAndRemove() {
		cout << "\t" << "SearchAndRemove Test... ";

		singly_linked_list<int> sll;

		sll.PushFront(3);
		sll.PushFront(1);
		SNode<int>* n5 = sll.PushBack(5);
		sll.PushBack(6);

		assert(sll.Search(5).value == n5);
		assert(sll.Remove(5) == true);
		assert(sll.Search(5).found == false);

		cout << "\t" << "OK" << endl;
	}

	static void RemoveFromDifferentList() {
		cout << "\t" << "RemoveFromDifferentList Test... ";

		singly_linked_list<int> sll;
		singly_linked_list<int> sll2;

		sll.PushFront(3);
		sll.PushFront(1);
		SNode<int>* n5 = sll.PushBack(5);
		sll.PushBack(6);

		sll2.PushFront(3);
		sll2.PushFront(1);
		sll2.PushBack(5);
		sll2.PushBack(6);

		assert(sll2.RemoveNode(n5) == false);
		assert(sll2.Search(5).found == true);

		cout << "\t" << "OK" << endl;
	}

	static void SearchTime1Million() {
		cout << "\t" << "Time Test 1,000,000" << endl;

		clock_t begin = clock();
		singly_linked_list<int> sll;
		for (int i = 0; i < 1 * 1000 * 1000; i++)
			sll.PushFront(i);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tInit time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		assert(sll.Search(500 * 1000).found == true);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tSearch time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		for (int i = 0; i < 100; i++)
			sll.PopBack();
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tPopBack time 100: " << elapsed_secs << "secs." << endl;
	}

	static void SearchTime5Million() {
		cout << "\t" << "Time Test 5,000,000" << endl;

		clock_t begin = clock();
		singly_linked_list<int> sll;
		for (int i = 0; i < 5 * 1000 * 1000; i++)
			sll.PushFront(i);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tInit time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		assert(sll.Search(2 * 1000 * 1000 + 500 * 1000).found == true);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tSearch time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		for (int i = 0; i < 5 * 1000 * 1000; i++)
			sll.PopFront();
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tPopFront time: " << elapsed_secs << "secs." << endl;
	}

	static void SearchTime25Million() {
		cout << "\t" << "Time Test 25,000,000" << endl;

		clock_t begin = clock();
		singly_linked_list<int> sll;
		for (int i = 0; i < 25 * 1000 * 1000; i++)
			sll.PushFront(i);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tInit time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		assert(sll.Search(12 * 1000 * 1000 + 500 * 1000).found == true);
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tSearch time: " << elapsed_secs << "secs." << endl;

		begin = clock();
		for (int i = 0; i < 25 * 1000 * 1000; i++)
			sll.PopFront();
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\t" << "\tPopFront time: " << elapsed_secs << "secs." << endl;
	}
};