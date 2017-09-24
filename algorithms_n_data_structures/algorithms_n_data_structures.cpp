// algorithms_n_data_structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	singly_linked_list<int> sll;
	
	SNode<int>* n3 = sll.PushFront(3);
	sll.PushFront(1);
	sll.PushBack(5);
	sll.PushBack(6);

	int val = sll.PopFront();
	cout << val << endl;
	
	while (!sll.Empty()) {
		int val = sll.PopFront();
		cout << val << endl;
	}

	return 0;
}

