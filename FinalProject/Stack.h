#pragma once
#include <iostream>

using namespace std; 


template <class T >
struct node {

	T value;
	node* next; 

	node( T v ) {
		value = v; 
		next = NULL; 
	
	}

};


template <class T >
class stack {
	node <T> *head; 


public : 
	stack() {
		head = NULL; 
	}

	void push(T val ) {
		node <T> *temp = new node<T>(val);

		if ( head == NULL ) {
			head = temp; 
		}
		else {
			temp->next = head; 
			head = temp; 
		
		}

	
	}

	T pop() {
		node <T>* temp = head;
		T v = temp->value; 
		if (head != NULL ) {
		    head = head->next;
			return temp->value; 
	    }
	   
	}


	bool empty() {
		if (head == NULL ) {
			return true; 
		}
		return false; 
	}



	T top() {
		return head->value; 
	}

	void clear() {

		while (head != nullptr)
		{
			pop();
			if (head != nullptr)
				head = head->next;
		}
		head = nullptr;

	}

	~stack() {

		clear();
	}

};