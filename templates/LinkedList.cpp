#include "LinkedList.h"
using namespace std;

template <class DType> Node<DType>::Node(DType localData) {
	next = NULL;
	data = localData; 
}

template <class DType> Node<DType>::Node() {
	next = NULL;
}

template <class DType> LinkedList<DType>::LinkedList() {
	head = NULL;
	tail = NULL;
}

template <class DType> int LinkedList<DType>::addNode(DType data) {
	Node<DType> *temp = new Node<DType>(data);
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}

	return 0;
}

template <class DType> int LinkedList<DType>::travarse() {
	Node<DType> *temp = head;
	for(;temp != NULL; temp=temp->next){
		cout << temp->data << "=>";
	}
	
	cout << "\n";
}

int main(void) {
	LinkedList<int> *xx = new LinkedList<int>();
	for (int i = 0; i < 10; i++ ){
		xx->addNode(i);
	}

	xx->travarse();
	return 0;
}

 
	
