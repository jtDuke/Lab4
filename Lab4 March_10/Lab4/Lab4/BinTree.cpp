// ----------------------------- BinTree.cpp ----------------------------------
//
// Author Name: Joshua Trygg CSS 343 
// Created: 01 / 10 / 2016
// Last Modified: 01 / 30 / 2016
//
// Purpose - Contains implementation of all the BinTree functions
// ----------------------------------------------------------------------------


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
		Account *nd = new Account(root->data->getID());

		// insert the new Account
		this->insert(nd);
	}

	// after insertion, move left, then right to find more nodes to be copied
	CopyTree(root->left);
	CopyTree(root->right);
}

// -------------------- bstreeToArray -----------------------------------------
// Calls a recursive function to traverse a Tree and assign each node's;
// data to the appropriate array index
// Preconditions: NONE
// Postconditions: A Tree is de-populated, its data is now in an array
// ----------------------------------------------------------------------------
void BinTree::bstreeToArray(Account*a[])
{
	int index = 0;									// an index placeholder
	bstreeToArrayHelper(a, this->root, index);		// calling recursive func
	this->MakeEmpty();								// emptying Tree
}

// -------------------- bstreeToArrayHelper -----------------------------------
// Recursively calls itself until the Tree has been fully traversed
// Preconditions: NONE
// Postconditions: The array "a" has been populated with all data from the Tree
// ----------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(Account*a[], Node *current, int &index)
{
	if (current != NULL)
	{
		bstreeToArrayHelper(a, current->left, index);    // find smallest value

														 // dynamically create a new Account pointer w/ existing data
		Account  *nd = new Account(current->data->getID());

		a[index] = nd;				//add data pointer to array
		index++;					//increase index of array

		bstreeToArrayHelper(a, current->right, index);  // recursive call
	}
}

// -------------------- CalcArraySize -----------------------------------------
// Used to find the amount of non-NULL indices being used
// Preconditions: NONE
// Postconditions: Determined the amount of populated indices in an array
// ----------------------------------------------------------------------------
int BinTree::CalcArraySize(Account *a[])
{
	int index = 0;
	while (index < 100)
	{
		if (a[index] == NULL)
		{
			return index - 1;		// stop iterating and return # of indices
		}
		else
		{
			index++;				// continue iterating
		}
	}
	return index;					// return non-NULL indices counted
}

// -------------------- arrayToBSTree -----------------------------------------
// Calculates the "working" size of the passed in array;
// then calls a recursive helper to put all data in the array, into a Tree
// Preconditions: NONE
// Postconditions: A Tree has been formed from the data in the array
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTree(Account*a[])
{
	int length = CalcArraySize(a);		// finds "working" size of the array
	arrayToBSTreeHelper(a, 0, length);	// recursive helper call
}

// -------------------- arrayToBSTreeHelper -----------------------------------
// Take the data from each index of an array and insert it into a Tree
// Preconditions: NONE
// Postconditions: A Tree has been formed from the data in the array
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(Account *arr[], int start, int end)
{
	if (start > end)
	{
		return;			// base case
	}

	// same as (start+end)/2, avoids overflow.
	int mid = start + (end - start) / 2;
	Account *nd = new Account(*arr[mid]);		// dynamically allocate NData
	insert(nd);									// insert Account into Tree
	delete arr[mid];							// deletes the Account pointer
	arrayToBSTreeHelper(arr, start, mid - 1);
	arrayToBSTreeHelper(arr, mid + 1, end);
}

// -------------------- TreeEquality ------------------------------------------
// Compares two trees for equality of Account & Node location in tree
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

	if (lhs->data->getID() == rhs->data->getID())
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
bool BinTree::insert(Account *nd)
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
bool BinTree::insertHelper(Node *&root, Account *&nd)
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
		if (nd->getID() == root->data->getID())
		{
			return false;     // Account already exists in BinTree
		}
		if (nd->getID() < root->data->getID())
		{
			return insertHelper(root->left, nd);    // recursive call left
		}
		else if (nd->getID() > root->data->getID())
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

	delete current->data;		// delete Account* Data
	current->data = NULL;		// set Account* to NULL
	delete current;				// delete Node*
	current = NULL;				// set Node* to NULL
}

// -------------------- FindMin -----------------------------------------------
// Recursively calls itself until the minimum valued Node is found
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
Account*& BinTree::FindMin(Node *current)
{
	if (current->left != NULL)
	{
		FindMin(current->left);   // Move left to find the smallest Account
	}
	else
	{
		return current->data;   // found minimum
	}
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
		cout << *current->data << " ";
		DisplayInOrderHelper(current->right);
	}
}

// -------------------- retrieve ----------------------------------------------
// Calls recursive helper function, trying to find supplied Account
// Returns a bool based on whether or not the Account exists
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
bool BinTree::retrieve(Account &nd, Account *&ndPtr) const
{
	if (root == NULL)
	{
		return false;
	}
	return RetrieveHelper(root, nd, ndPtr);
}

// -------------------- RetrieveHelper ----------------------------------------
// Recurisvely calls itself until the Account is found (or not) in the BinTree
// If not found, return false
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
bool BinTree::RetrieveHelper(Node *curr, Account &nd, Account *&ndPtr) const
{
	if (curr == NULL)
	{
		return false;  // return false if the Account passed in is not in tree
	}

	if (curr->data->getID() == nd.getID())
	{
		ndPtr = curr->data;		// Account is found
		return true;
	}

	// Account has not been found yet
	if (nd.getID() < curr->data->getID())
	{
		return RetrieveHelper(curr->left, nd, ndPtr);  // recursive call
	}
	else
	{
		return RetrieveHelper(curr->right, nd, ndPtr);  // recursive call
	}
}

// -------------------- FindNode ----------------------------------------------
// Recursively calls itself until it finds (or not) the Account sent passed in
// If not found, NULL is returned
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
BinTree::Node* BinTree::FindNode(Node *root, Account &nd) const
{
	if (root == NULL)
	{
		return NULL;   // Account was not found
	}
	else if (nd == *root->data)
	{
		return root;   // found Account
	}
	if (nd < *root->data)
	{
		FindNode(root->left, nd);   // recursive call
	}
	else
	{
		FindNode(root->right, nd);   // recursive call
	}
}

// -------------------- getHeight ---------------------------------------------
// Takes in Account and finds its location in the BinTree;
// then calls helper function to calculate it's height in the tree
// If unable to find the Account, a height of 0 is returned
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
int BinTree::getHeight(Account &nd)
{
	if (root == NULL)
	{
		return 0;
	}

	Node *temp;		   // created to hold a copy of a Node pointer
	temp = FindNode(root, nd);   // go find the node to copy

								 //sending in the copied node to calculate its height
	return getHeightHelper(temp, nd);
}

// -------------------- getHeightHelper ---------------------------------------
// Calculates and returns the height of a given Node
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
int BinTree::getHeightHelper(Node *root, Account &nd)
{
	if (root == NULL)
	{
		return 0;
	}

	// move down and left a level
	// leftSide counts each level of children in the left sub-tree
	int leftSide = getHeightHelper(root->left, nd);

	// rightSide counts each level of children in the right sub-tree
	int rightSide = getHeightHelper(root->right, nd);

	// Determine which side of the tree has the greater height and return it
	if (leftSide > rightSide)
	{
		return(leftSide + 1);
	}
	else
	{
		return(rightSide + 1);
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

//---------------------------- DisplayArray -----------------------------------
// Displays the data of an array of Account pointers
// Preconditions: NONE
// Postconditions: Array remains unchanged.
// ----------------------------------------------------------------------------
void BinTree::DisplayArray(Account *a[]) const
{
	for (int i = 0; i < 100; i++)
	{
		if (a[i] == NULL) {
			continue;
		}
		else {
			cout << a[i]->getID() << " ";
		}
	}
	cout << endl;
}

//------------------------- displaySideways -----------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
void BinTree::displaySideways() const
{
	Sideways(root, 0);
}

//---------------------------- Sideways ---------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------
void BinTree::Sideways(Node* current, int level) const
{
	if (current != NULL)
	{
		level++;
		Sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--)
		{
			cout << "    ";
		}

		cout << *current->data << endl;      // display information of object
		Sideways(current->left, level);
	}
}



