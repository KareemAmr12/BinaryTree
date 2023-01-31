// File: BSTappl.cpp
// Test class template binaryTree
#include <iostream>
#include <string>
using namespace std;
#include "binaryTree.h"
#include "binaryTree.cpp"

int main()
{
	const int N = 7;
	string A[N] = { "Eve", "Ann", "Alice", "John", "Mary", "Jack", "Bob" };
	string B[N] = { "123", "111", "231", "555", "444", "222", "333" };

	string k;
	binaryTree<string, string> BST;
	cout << "Constructing empty BST" << endl;
	for (int i = 0; i < N; i++)
		if (BST.insert(A[i], B[i]))
			cout << A[i] << " is inserted\n";

	cout << "\nCurrent size: " << BST.occupency() << endl;

	cout << "==================================" << endl;
	cout << "Key to search for: ";
	cin >> k;
	
	if (BST.search(k))
		cout << "Found" << endl;
	else
		cout << "Not found" << endl;

	system("pause");
	return 0;
}