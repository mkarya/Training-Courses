#include <iostream>

template <class DType> class Node{
	public:
		DType data;
		Node<DType> *next;
		Node();
		Node(DType);
		~Node();
};


template <class DType> class LinkedList {
	public:
		Node<DType> *head;
		Node<DType> *tail;
		LinkedList();
		~LinkedList();
		int addNode(DType);
		int travarse();
};
