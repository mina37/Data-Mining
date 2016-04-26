#pragma once

#include "Node.cpp"
//#include "dsList.h"
#include <set>

using namespace std;

template<class T>
class Node
{
public:

	T data;
	Node <T> *next;



	Node<T>(const T & d) : data(d), next(){}
	Node<T>(const Node<T> & copyNode) : data(copyNode.data), next() {}
	T get_data();
	//template <class T>friend class dsList;
private:
	
	Node<T> & operator=(const Node<T>&);

};

template<class T>
inline T Node<T>::get_data()
{
	return data;
}

template<class T>
inline Node<T>& Node<T>::operator=(const Node<T>&)
{
	// TODO: insert return statement here
}
