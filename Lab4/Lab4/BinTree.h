// ----------------------------- BinTree.h ------------------------------------
//
// Author Name: Joshua Trygg CSS 343 
// Created: 01 / 10 / 2016
// Last Modified: 01 / 30 / 2016
//
// Purpose - This .H file contains the BinTree class definitions
// ----------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include "Movie.h"
#include "MovieFactory.h"
#include <iostream>
#include <string>
using namespace std;

class BinTree
{
	//display tree
	friend ostream& operator<<(ostream& outStream, BinTree &tree);

private:

	struct Node {
		Movie* data = NULL;				// pointer to data object
		Node* left = NULL;			// left subtree pointer
		Node* right = NULL;			// right subtree pointer
	};
	Node* root = NULL;				// root of the tree
	
	// finds a node depending on its data contents
	Node* FindNode(Node *root, Movie &nd) const;

	bool TreeEquality(const Node *lhs, const Node *rhs) const; //check equality
	void CopyTree(Node *&rhs);		// helps creates a deep copy

	void DisplayInOrderHelper(Node *current) const;		           //helper
	bool insertHelper(Node *&parent, Movie *&nn);				   //helper
	void MakeEmptyHelper(Node *&current);							   //helper
	bool RetrieveHelper(Node *curr, Movie &nd, Movie *&ndPtr) const; //""

public:

	BinTree();						// constructor
	BinTree(BinTree &source);		// copy constructor
	~BinTree();						// destructor, calls MakeEmpty	

	bool isEmpty() const;			// true if tree is empty, otherwise false
	void MakeEmpty();				// Empties and deletes entire tree

	bool insert(Movie*);				// Insert node into tree
	void DisplayInOrder() const;		// display entire tree in order
	bool retrieve(Movie &nd, Movie *&ndPtr) const;  // find given data

	BinTree& operator=(BinTree &);				// overloaded
	bool operator==(const BinTree &) const;		// overloaded
	bool operator!=(const BinTree &) const;		// overloaded
};
#endif

