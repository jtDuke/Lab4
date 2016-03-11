// ----------------------------- BinTree.h ------------------------------------
//
// Author Name: Joshua Trygg CSS 343 
// Created: 01 / 10 / 2016
// Last Modified: 01 / 30 / 2016
//
// Purpose - This .H file contains the BinTree class definitions
// ----------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class BinTree
{
	//display tree
	friend ostream& operator<<(ostream& outStream, BinTree &tree);

private:

	struct Node {
		Account* data;						// pointer to data object
		Node* left = NULL;							// left subtree pointer
		Node* right = NULL;						// right subtree pointer
	};
	Node* root = NULL;								// root of the tree

	void Sideways(Node*, int) const;		// helper for displaySideways()	

											// finds a node depending on its data contents
	Node* FindNode(Node *root, Account &nd) const;

	// finds "working" size (NON-NULL values) of an array 
	int CalcArraySize(Account *a[]);
	Account*& FindMin(Node *current);  // Finds smallest Node
	bool TreeEquality(const Node *lhs, const Node *rhs) const; //check equality
	void CopyTree(Node *&rhs);		// helps creates a deep copy

	void DisplayInOrderHelper(Node *current) const;		           //helper
	void arrayToBSTreeHelper(Account *arr[], int start, int end);	   //helper
	void bstreeToArrayHelper(Account*a[], Node *current, int &index); //helper
	bool insertHelper(Node *&parent, Account *&nn);				   //helper
	void MakeEmptyHelper(Node *&current);							   //helper
	int getHeightHelper(Node *root, Account &nd);					   //helper
	bool RetrieveHelper(Node *curr, Account &nd, Account *&ndPtr) const; //""

public:

	BinTree();						// constructor
	BinTree(BinTree &source);		// copy constructor
	~BinTree();						// destructor, calls MakeEmpty	

	bool isEmpty() const;			// true if tree is empty, otherwise false
	void MakeEmpty();				// Empties and deletes entire tree

	BinTree& operator=(BinTree &);				// overloaded
	bool operator==(const BinTree &) const;		// overloaded
	bool operator!=(const BinTree &) const;		// overloaded

	bool insert(Account*);				// Insert node into tree
	void DisplayInOrder() const;		// display entire tree in order
	void bstreeToArray(Account*a[]);	// take tree and put the data in array
	void arrayToBSTree(Account*[]);	// take array an dput data in tree
	bool retrieve(Account &nd, Account *&ndPtr) const;  // find given data
	void displaySideways() const;		// displays the tree sideways
	int getHeight(Account &nd);		// determines height of a given node	
	void DisplayArray(Account *a[]) const;		// displays array values
};



