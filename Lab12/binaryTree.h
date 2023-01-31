// FILE: binaryTree.h
#ifndef BIN_TREE_H
#define BIN_TREE_H

// Specification of the class

template <class keyType, class dataType>

class binaryTree
{

public:

	// Public Member functions ...
	// CREATE AN EMPTY TREE
	binaryTree();

	// INSERT AN ELEMENT INTO THE TREE
	bool insert(const keyType&, const dataType&);

	// SEARCH FOR A KEY IN THE TREE
	bool search(const keyType&) const;

	int occupency();

private:
	// Node Class
	class treeNode
	{
	public:
		keyType key; 		// key 
		dataType data;		// Data
		treeNode* left;		// left subtree	       
		treeNode* right;	// right subtree
	}; // end of class treeNode declaration

	typedef treeNode* NodePointer;
	// Data member ....
	NodePointer root;

	// Private Member functions ...

	bool insert2(NodePointer&, const keyType&, const dataType&);

	bool search2(NodePointer, const keyType&) const;
	int occupency1(NodePointer);
};

#endif // BIN_TREE_H
//#include "binaryTree.cpp"