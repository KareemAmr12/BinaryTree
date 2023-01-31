// File: binaryTree.cpp
// Implementation of template class binary search tree

#include <iostream>
#include <iomanip>
using namespace std;

#include "binaryTree.h"

// Member functions ...

// constructor - create an empty tree
template <class keyType, class dataType>
binaryTree<keyType, dataType>::binaryTree()
{
	root = NULL;
}

//____________ Public insert __________________
// Inserts element into a binary search tree.
// Pre : key k is defined.
// Post: Inserts element if k is not in the tree.
// Returns true if the insertion is performed.
// If there is a node with the same key value 
// as k, returns false.
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::insert(const keyType& k, const dataType& d)
{
	return insert2(root, k, d);
} // end of public insert

//____________ Private insert __________________
// Inserts element in the tree pointed to by 
// aRoot.Called by public insert.
// Pre : aRoot k and d are defined.
// Post: If a node with same key as k is found,
// returns false. If an empty tree is reached,
// inserts element as a leaf node and returns true.
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::insert2(NodePointer& aRoot, const keyType& k, const dataType& d)
{
	// Check for empty tree.
	if (aRoot == NULL) //base case
	{
		aRoot = new treeNode;
		aRoot->key = k;
		aRoot->data = d;
		aRoot->left = NULL;
		aRoot->right = NULL;
		
		return true;
	}
	else if (k == aRoot->key)
		return false;
	else if (k < aRoot->key)
		return insert2(aRoot->left, k, d);
		

	else
		return insert2(aRoot->right, k, d);
		

} // end of private insert

//____________ Public search __________________
// Searches for the item with same key as k
//  in a binary search tree.
// Pre : k is defined.
// Returns true if key is located,
//   otherwise, returns false.
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::search(const keyType& k) const
{
	return search2(root, k);
} // end of public search   

//____________ Private search __________________
// Searches for the item with same key as k 
// in the subtree pointed to by aRoot. Called
// by public search.
// Pre : k and aRoot are defined.
// Returns true if key is located,
// otherwise, returns false.
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::search2(NodePointer aRoot, const keyType& k)	const
{
	if (aRoot == NULL)
	{
		return false;
	}

	if (aRoot->key == k)
	{
		return true;
		
	}
	if (k > aRoot->key)
	{
		return search2(aRoot->right, k);
	}
	if (k < aRoot->key)
	{
		return search2(aRoot->left, k);
	}
	

} // end of private search
template <class keyType, class dataType>
int binaryTree<keyType, dataType>::occupency()
{
	return occupency1(root);
}

template <class keyType, class dataType>
int binaryTree<keyType, dataType>::occupency1(NodePointer aRoot)
{
	if (aRoot==NULL)
	{
		return 0;
	}
	 
	return (1 + occupency1(aRoot->left) + occupency1(aRoot->right));

}