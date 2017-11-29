/*
 * LinkedStack.h
 *
 *  Created on: Oct 30, 2017
 *      Author: beverlyackah
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* next;
};

template <class T>
class LinkedStack{
	node<T> *top;

public: //function prototype for a stack

	LinkedStack();
	void push(T&);
	T pop();
	bool isEmpty();
	T peek();
	void destroy();
	friend ostream& operator<<(ostream& os, LinkedStack<T>& ls);
	~LinkedStack();
};

//function implementation

template <class T>
//LinkedStack Implementation: Constructor
LinkedStack<T>::LinkedStack(){
	top = NULL;
}

//PUSH IMPLEMENTATION: adds value to a stack
template <class T>
void LinkedStack<T>::push(T& item){
	node<T>* ptr = new node<T>();
	ptr -> data = item;
	ptr -> next = NULL;
	if(top!=NULL){
		ptr->next=top;
		top=ptr;
	}
	else {
		top = ptr;
	}
}

//POP IMPLEMENTATION: removes a value to a stack
template <class T>
T LinkedStack<T>::pop(){
	node <T> *p;
	p = top;
	if(top!=NULL){

		top = top ->next;
	}

	return p->data;
}
//isEmpty: returns if the LinkedStack is empty or not
template <class T>
bool LinkedStack<T>:: isEmpty(){
	return top == NULL; //-1?
}

//STOP implementation
template <class T>
T LinkedStack<T>:: peek(){
	if(!isEmpty()){
		return (top->data);
	}
}

//Destroy: detroy the whole XXX to avoid memory leaks
template <class T>
void LinkedStack<T>::destroy(){
	while(top!=NULL){
		node <T> *p;
		p = top;
		top = top ->next;
		delete p;
	}
}
//Friend method to print the LinkedStack
template <class T>
ostream& operator<<(ostream& os, LinkedStack<T>& ls){
	node<T> *p = ls.top;
	while(p!= NULL){
		os<<p->data<<" "<<endl;
		p = p->next;
	}
	return os;
}

template <class T>
LinkedStack<T>::~LinkedStack(){

}
#endif /* LINKEDSTACK_H_ */
