#ifndef HISTORYLIST_H
#define HISTORYLIST_H
//#include "History.h"
//
//using namespace std;
//
//
//class HistoryList
//{
//	friend ostream& operator<<(ostream& os, const HistoryList &list)
//	{
//		Node *currPtr = list.headPtr;
//		while (currPtr != nullptr)
//		{
//			os << *currPtr->data;
//			currPtr = currPtr->next;
//		}
//		return os;
//	}
//
//private:
//	struct Node
//	{
//		History *data = nullptr;
//		Node *next = nullptr;
//	};
//	Node *headPtr = nullptr;
//
//public:
//	HistoryList();
//	HistoryList(const HistoryList &list);
//	~HistoryList();
//	bool BuildList(string fileName);
//	bool Insert(History *obj);
//	bool Remove(History target, History &result);
//	bool Peek(History target, History &result);
//	bool isEmpty();
//	void DeleteList();
//	bool Merge(HistoryList &list1);
//	HistoryList& operator=(const HistoryList&);
//	HistoryList& operator+=(const HistoryList&);
//	HistoryList operator+(const HistoryList&) const;
//	bool operator==(const HistoryList&) const;
//	bool operator!=(const HistoryList&) const;
//};
//
////default constructor
//HistoryList::HistoryList()
//{
//	headPtr = nullptr;
//}
//
//// copy constructor
//HistoryList::HistoryList(const HistoryList &source)
//{
//	*this = source;
//}
//// destructor
//HistoryList::~HistoryList()
//{
//	delete headPtr;
//}
//
//bool HistoryList::BuildList(string FileName)
//{
//	ifstream inFile(FileName);
//	if (!inFile)
//	{
//		return false;
//	}
//
//	while (!inFile.eof())
//	{
//		History* itemObject = new History;
//		inFile >> *itemObject;
//		Insert(itemObject);
//		delete itemObject;
//		itemObject = nullptr;
//	}
//
//	inFile.close();
//	return true;
//}
//
//bool HistoryList::Insert(History *obj)
//{
//	Node* nnPtr = new Node;
//	nnPtr->data = obj;
//	if (headPtr == nullptr)
//	{
//		headPtr = nnPtr;
//		return true;
//	}
//	else if (*headPtr->data == *obj)
//	{
//		return false;
//	}
//	else if (*headPtr->data > *obj)
//	{
//		nnPtr->next = headPtr;
//		headPtr = nnPtr;
//		return true;
//	}
//
//	Node* currPtr = headPtr;
//	while (currPtr->next != nullptr)
//	{
//		if (*currPtr->data == *obj)
//		{
//			return false;
//		}
//		else if (*currPtr->next->data > *obj)
//		{
//			nnPtr->next = currPtr->next;
//			currPtr->next = nnPtr;
//			return true;
//		}
//		currPtr = currPtr->next;
//	}
//
//	currPtr->next = nnPtr;
//	return true;
//}
//
//bool HistoryList::Remove(History target, History &result)
//{
//	if (headPtr == nullptr)
//	{
//		return false;
//	}
//	else if (*headPtr->data == target)
//	{
//		result = target;
//		headPtr = headPtr->next;
//		return true;
//	}
//
//	Node* currPtr = headPtr;
//	while (currPtr->next != nullptr)
//	{
//		if (*currPtr->next->data == target)
//		{
//			result = target;
//			currPtr->next = currPtr->next->next;
//			return true;
//		}
//		currPtr = currPtr->next;
//	}
//	return false;
//}
//
//bool HistoryList::Peek(History target, History &result)
//{
//	if (headPtr == nullptr)
//	{
//		return false;
//	}
//
//	Node* currPtr = headPtr;
//	if (*headPtr->data == target)
//	{
//		result = target;
//		return true;
//	}
//	while (currPtr != nullptr)
//	{
//		if (*currPtr->data == target)
//		{
//			result = target;
//			return true;
//		}
//		currPtr = currPtr->next;
//	}
//	return false;
//}
//
//bool HistoryList::isEmpty()
//{
//	if (headPtr == nullptr)
//	{
//		return true;
//	}
//	return false;
//}
//
//
//void HistoryList::DeleteList()
//{
//	if (headPtr == nullptr)
//	{
//		return;
//	}
//	while (headPtr != nullptr)
//	{
//		Node* temp = headPtr;
//		headPtr = headPtr->next;
//		delete temp;
//		temp = nullptr;
//	}
//	delete headPtr;
//	headPtr = nullptr;
//}
//
//
//bool HistoryList::Merge(HistoryList &list1)
//{
//	if (this->headPtr == list1.headPtr)
//	{
//		return true;
//	}
//	if (this->isEmpty())
//	{
//		if (list1.isEmpty())
//		{
//			return true;
//		}
//	}
//	if (!list1.isEmpty())
//	{
//		Node* currPtr = list1.headPtr;
//		while (currPtr != nullptr)
//		{
//			History *itemObject = currPtr->data;
//			Insert(itemObject);
//			currPtr = currPtr->next;
//		}
//	}
//	list1.DeleteList();
//	return true;
//}
//
//bool HistoryList::operator==(const HistoryList &list2) const
//{
//	Node *curr1, *curr2;
//	curr1 = this->headPtr;
//	curr2 = list2.headPtr;
//
//	while (curr1 != nullptr && curr2 != nullptr)
//	{
//		if (curr1->data != curr2->data)
//		{
//			return false;
//		}
//		curr1 = curr1->next;
//		curr2 = curr2->next;
//	}
//	if (curr1 == nullptr && curr2 == nullptr)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool HistoryList::operator!=(const HistoryList &list2) const
//{
//	Node *curr1, *curr2;
//	curr1 = this->headPtr;
//	curr2 = list2.headPtr;
//
//	while (curr1 != nullptr && curr2 != nullptr)
//	{
//		if (curr1->data != curr2->data)
//		{
//			return true;
//		}
//		curr1 = curr1->next;
//		curr2 = curr2->next;
//	}
//	if (curr1 == nullptr && curr2 == nullptr)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//
//HistoryList& HistoryList::operator=(const HistoryList &source)
//{
//	if (this == &source)
//	{
//		return *this;
//	}
//	this->DeleteList();
//	if (source.headPtr == nullptr)
//	{
//		return *this;
//	}
//	Node *dNode, *sNode, *insNode;
//	dNode = new Node;
//	dNode->data = source.headPtr->data;
//	dNode->next = nullptr;
//	this->headPtr = dNode;
//	sNode = source.headPtr->next;
//	while (sNode != nullptr)
//	{
//		insNode = new Node;
//		insNode->data = sNode->data;
//		insNode->next = nullptr;
//		dNode->next = insNode;
//		dNode = dNode->next;
//		sNode = sNode->next;
//	}
//	return *this;
//}
//
//HistoryList& HistoryList::operator+=(const HistoryList &list2)
//{
//	if (list2.headPtr == nullptr)
//	{
//		return *this;
//	}
//	else
//	{
//		Node* nnPtr = list2.headPtr;
//		while (nnPtr != nullptr)
//		{
//			this->Insert(nnPtr->data);
//			nnPtr = nnPtr->next;
//		}
//	}
//	return *this;
//}
//
//HistoryList HistoryList::operator+(const HistoryList& list2) const
//{
//	HistoryList temp;
//	if (this->headPtr == nullptr)
//	{
//		if (list2.headPtr == nullptr)
//		{
//			return temp;
//		}
//		else
//		{
//			temp.headPtr = list2.headPtr;
//			Node *nnPtr = temp.headPtr;
//			while (nnPtr != nullptr)
//			{
//				temp.Insert(nnPtr->data);
//				nnPtr = nnPtr->next;
//			}
//			return temp;
//		}
//	}
//
//	temp.headPtr = this->headPtr;
//	Node *nnPtr = list2.headPtr;
//	while (nnPtr != nullptr)
//	{
//		temp.Insert(nnPtr->data);
//		nnPtr = nnPtr->next;
//	}
//
//	return temp;
//}
#endif 