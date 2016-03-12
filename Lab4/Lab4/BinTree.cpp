// ----------------------------- BinTree.cpp ----------------------------------
//
// Author Name: Joshua Trygg CSS 343 
// Created: 01 / 10 / 2016
// Last Modified: 01 / 30 / 2016
//
// Purpose - Contains implementation of all the BinTree functions
// ----------------------------------------------------------------------------

// FIX - NEED TO IMPLEMMENT WAY TO INSERT IN COPYTREE


#include "BinTree.h"

// -------------------- Default Constructor -----------------------------------
// Creates a new Binary Search Tree & sets the root to NULL
// Preconditions: NONE
// Postconditions: A new BST is available for use
// ----------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

// -------------------- ~BinTree ----------------------------------------------
// Calls a "clean-up" function named MakeEmpty to rid the Tree from pointers;
// by deallocating dynamic memory
// Preconditions: NONE
// Postconditions: Tree is empty & not available for use any longer
// ----------------------------------------------------------------------------
BinTree::~BinTree()
{
	MakeEmpty();
}

// -------------------- Copy Constructor --------------------------------------
// Calls the assignment operator to establish a deep copy
// Preconditions: NONE
// Postconditions: A copy (deep) of a Tree is ready for use
// ----------------------------------------------------------------------------
BinTree::BinTree(BinTree &source)
{
	*this = source;
}

// -------------------- operator = --------------------------------------------
// Determines the state of the existing tree (rhs);
// starts the copying process if necessary
// Preconditions: NONE
// Postconditions: A tree of equal value to rhs is returned
// ----------------------------------------------------------------------------
BinTree& BinTree::operator=(BinTree &rhs)
{
	if (*this == rhs)			// if true, the two trees are already equal
	{
		return *this;
	}

	if (rhs.isEmpty())			// if true, the tree to be copied is empty
	{
		this->MakeEmpty();		// must empty the existing tree
		return *this;			// return a now empty tree
	}

	// the tree to be copied is not empty
	this->MakeEmpty();			// must empty the existing tree
	this->CopyTree(rhs.root);	// start the copying process

	return *this;
}

// -------------------- operator ==, != ---------------------------------------
// Determines if two trees are equal or not, returns a boolean value
// Preconditions: NONE
// Postconditions: NONE
// ----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &rhs) const
{
	if (this->root == NULL && rhs.root == NULL)  // check for two empty trees
	{
		return true;
	}
	else
	{	  // send the roots of both trees as parameters to determine equality
		return TreeEquality(this->root, rhs.root);
	}
}
bool BinTree::operator!=(const BinTree &rhs) const
{
	if (*this == rhs)		// utilize the overloaded == operator
	{
		return false;		// not equal trees
	}
	else
	{
		return true;		// equal trees
	}
}

// -------------------- CopyTree ----------------------------------------------
// Recursively calls itself to dynamically populate a new tree
// Preconditions: NONE
// Postconditions: A deep copy of all Nodes has been accomplished
// ----------------------------------------------------------------------------
void BinTree::CopyTree(Node *&root)
{
	if (root == NULL)
	{
		return;				// base case
	}
	else
	{
		// dynamically allocate a new pointer with equivalent data
		//Movie *nd = MovieFactory::createMovie();//= new Movie(root->data->getID(), root->data->getFirstName(), root->data->getLastName());

		// insert the new Movie
		//this->insert(nd);
	}

	// after insertion, move left, then right to find more nodes to be copied
	CopyTree(root->left);
	CopyTree(root->right);
}

// -------------------- TreeEquality ------------------------------------------
// Compares two trees for equality of Movie & Node location in tree
// Preconditions: NONE
// Postconditions: Binary Tree's remain unchanged
// ----------------------------------------------------------------------------
bool BinTree::TreeEquality(const Node *lhs, const Node *rhs) const
{
	if (lhs == NULL && rhs == NULL)
	{
		return true;				// both Tree's nodes are NULL
	}
	else if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL))
	{
		return false;		// unequal NULLality or Nullness (are those words?)
	}

	if (lhs->data == rhs->data)
	{
		if (TreeEquality(lhs->left, rhs->left))		// data is equal, move left
		{
			return TreeEquality(lhs->right, rhs->right);    // now right
		}
	}
	return false;		// data is not equal between two Tree's nodes
}

// -------------------- isEmpty -----------------------------------------------
// Checks the tree to see if it is empty or not
// Preconditions: NONE
// Postconditions: Binary Tree is unchanged
// ----------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;		// it's empty
	}
	else
	{
		return false;		// it's not empty
	}
}

// -------------------- insert ------------------------------------------------
// Attempts to insert a new Node to the BinTree
// Checks first if the Tree is empty, if so simply insert the Node;
// calls recursive helper function otherwise
// Preconditions: NONE
// Postconditions: BinTree has either added a new Node OR returns false for dup 
// ----------------------------------------------------------------------------
bool BinTree::insert(Movie *nd)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = nd;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	return insertHelper(root, nd);
}

// -------------------- insertHelper ------------------------------------------
// Recursively calls itself until duplicate data is found OR a NULL location
// Preconditions: NONE
// Postconditions: BinTree has either added a new Node OR returns false for dup
// ----------------------------------------------------------------------------
bool BinTree::insertHelper(Node *&root, Movie *&nd)
{
	if (root == NULL)
	{
		root = new Node;			// dynamically allocate a new Node
		root->data = nd;			// set the new Node's data pointer
		root->left = NULL;			// set left child to NULL
		root->right = NULL;			// set right child to NULL
		return true;
	}
	else
	{
		if (nd == root->data)
		{
			return false;     // Movie already exists in BinTree
		}
		else if (*nd < *root->data)
		{
			return insertHelper(root->left, nd);    // recursive call left
		}
		else if (*nd > *root->data)
		{
			return insertHelper(root->right, nd);	// recursive call right
		}
	}
	return true;
}

// --------------------  MakeEmpty --------------------------------------------
// Calls helper function, passing in the root of a BinTree
// Preconditions: NONE
// Postconditions: Binary Tree is empty
// ----------------------------------------------------------------------------
void BinTree::MakeEmpty()
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		MakeEmptyHelper(root);   // calling helper function
	}
}

// --------------------  MakeEmptyHelper --------------------------------------
// Traverses the Binary Tree and deletes all pointers associated with each Node
// Recursively calls itself
// Preconditions: NONE
// Postconditions: Binary Tree is empty
// ----------------------------------------------------------------------------
void BinTree::MakeEmptyHelper(Node *&current)
{
	if (current == NULL)
	{
		return;				// found a NULL node
	}

	MakeEmptyHelper(current->left);		// move down to left child
	MakeEmptyHelper(current->right);	// move down to right child

	delete current->data;		// delete Movie* Data
	current->data = NULL;		// set Movie* to NULL
	delete current;				// delete Node*
	current = NULL;				// set Node* to NULL
}

// -------------------- DisplayInOrder ----------------------------------------
// Calls recursive helper function to do the work, passing in a BinTree root
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
void BinTree::DisplayInOrder() const
{
	DisplayInOrderHelper(root);
	cout << endl;
}

// -------------------- DisplayInOrderHelper ----------------------------------
// Traverses the BinTree recursively, displays the BinTree data in order
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
void BinTree::DisplayInOrderHelper(Node *current) const
{
	if (current != NULL)
	{
		DisplayInOrderHelper(current->left);
		current->data->display();
		DisplayInOrderHelper(current->right);
	}
}

// -------------------- retrieve ----------------------------------------------
// Calls recursive helper function, trying to find supplied Movie
// Returns a bool based on whether or not the Movie exists
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
bool BinTree::retrieve(Movie &nd, Movie *&ndPtr) const
{
	if (root == NULL)
	{
		return false;
	}
	return RetrieveHelper(root, nd, ndPtr);
}

// -------------------- RetrieveHelper ----------------------------------------
// Recurisvely calls itself until the Movie is found (or not) in the BinTree
// If not found, return false
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
bool BinTree::RetrieveHelper(Node *curr, Movie &nd, Movie *&ndPtr) const
{
	if (curr == NULL)
	{
		return false;  // return false if the Movie passed in is not in tree
	}

	if (*curr->data == nd)
	{
		ndPtr = curr->data;		// Movie is found
		return true;
	}

	// Movie has not been found yet
	if (nd < *curr->data)
	{
		return RetrieveHelper(curr->left, nd, ndPtr);  // recursive call
	}
	else
	{
		return RetrieveHelper(curr->right, nd, ndPtr);  // recursive call
	}
}

// -------------------- FindNode ----------------------------------------------
// Recursively calls itself until it finds (or not) the Movie sent passed in
// If not found, NULL is returned
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
BinTree::Node* BinTree::FindNode(Node *root, Movie &nd) const
{
	if (root == NULL)
	{
		return NULL;   // Movie was not found
	}
	else if (nd == *root->data)
	{
		return root;   // found Movie
	}
	if (nd < *root->data)
	{
		return FindNode(root->left, nd);   // recursive call
	}
	else
	{
		return FindNode(root->right, nd);   // recursive call
	}
}

// -------------------- operator << -------------------------------------------
// Displays (in order) the data of a BinTree made up of Node pointers
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& outStream, BinTree &tree)
{
	tree.DisplayInOrder();
	return outStream;
}



