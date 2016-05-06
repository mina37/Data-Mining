#pragma once

#include "Node.h"
#include <set>

using namespace std;

template<class T>
class dsList
{
public:

	Node<T> * head;
	Node<T> * tail;
	int size;

	dsList(const dsList & LL);

	dsList& operator=(dsList byValList);
	dsList(Node<T> * newNode) : head(newNode), tail(newNode) { size++; }

	void insertoTail(T val);
	void insertoHead(T Val);
	Node<T> deleteHead();
	Node<T> deleteTail();
	void printList();
	int get_size();
	Node<T>* get_Head();
	Node<T>* get_Tail();

	T get(int i);
	void set(int i,T d);

	dsList();
	~dsList();

};

template<class T>
inline dsList<T>::~dsList()
{
	Node<T> * curr = head;
	while (head)
	{
		head = head -> next;
		delete curr;
		curr = head;
	}
}


template<class T>
inline dsList<T>::dsList(const dsList<T> & LL)
{
	head = NULL;
	tail = NULL;
	size = LL.size;

	const Node<T> * curr = LL.head;

	if (!head && curr)
	{
		head = new Node<T>(curr->data);
		tail = head;
		curr = curr->next;
	}

	while (curr)
	{
		Node<T> * newNode = new Node<T>(curr->data);
		tail->next = newNode;
		tail = newNode;
		curr = curr->next;

	}
}

template<class T>
inline dsList<T> & dsList<T>::operator=(dsList byValList)
{
	swap(head, byValList.head);
	return *this;
}

//template<class T>
//dsList<T>::dsList(Node<T>* newNode)
//{
//	head = newNode;
//	tail = newNode;
//}

template<class T>
inline void dsList<T>::insertoTail(T val)
{
	Node<T> * newNode = new Node<T>(val);
	if (tail == NULL)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		return;
	}

	tail->next = newNode;
	tail = tail->next;
	size++;
}

template<class T>
inline void dsList<T>::insertoHead(T val)
{
	Node<T> * newNode = new Node<T>(val);

	newNode->next = head;
	head = newNode;
	if (head->next == NULL)
	{
		tail = newNode;
	}
	size++;
}

template<class T>
inline Node<T> dsList<T>::deleteHead()
{
	if (head != NULL)
	{
		Node<T> *tmp = head;
		head = head->next;
		size--;
		return *tmp;
	}
	else
		return NULL;
	
}

template<class T>
inline Node<T> dsList<T>::deleteTail()
{
	if (tail != head && head != NULL)
	{
		Node<T> *tmp = head;
		Node <T> *tmp2 = head->next;
		while (tmp2->next)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		Node<T> * tmp3 = tail;
		tail = tmp;
		tail->next = NULL;
		delete tmp3;
		size--;
		return *tmp2;
	}
	else
		return NULL;
	
}

template<class T>
inline void dsList<T>::printList()
{
	Node<T> *curr = head;
	while (curr)
	{
		cout << curr->data << "-->";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

template<class T>
inline int dsList<T>::get_size()
{
	return size;
}

template<class T>
inline Node<T>* dsList<T>::get_Head()
{
	return head;
}

template<class T>
inline Node<T>* dsList<T>::get_Tail()
{
	return tail;
}

template<class T>
inline T dsList<T>::get(int i)
{
	int j = 0;
	Node<T> * tmp = head;
	while (j < i && i< size-1)
	{
		tmp = tmp->next;
		j++;
	}
	//delete[] tmp;
	return tmp->data;
	

}

template<class T>
inline void dsList<T>::set(int i,T d)
{
	int j = 0;
	Node<T>* tmp = head;
	while (j < i&&i < size - 1)
	{
		tmp = tmp->next;
		j++;
	}
	tmp->data = d;
}




template<class T>
inline dsList<T>::dsList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}


//template<class T>
//dsList<T>::~dsList()
//{
//	Node<T> * curr = head;
//	while (head)
//	{
//		head = head - > next;
//		delete curr;
//		curr = head;
//	}
//}
