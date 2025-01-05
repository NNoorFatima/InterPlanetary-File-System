#pragma once
#include "StringBTree.h"
#include <cmath>

class Files {

BTNode* root; 
int  m; 
double min;
double max;


public : 
	Files( int m = 5  ) {

		root = new BTNode (m);
		root = NULL;

		this->m = m; 

		max = m -1 ; 
		double temp = m / 2.0 ; 
	

		min = ceil ( temp ) - 1 ; 

		
	}

	BTNode*  GetRoot() {
		if (root != NULL)
			return root; 
	
		return NULL; 
	}

	void insert_a_file ( string hash , string& content   ) {
	
		root = insert( hash  , content , root, max ,  min ) ;

	}

	void PrintTree() {
	
		cout << "B-tree of order : "<< this->m <<"\n";
		display(root );
	
	}

	void Delete_a_file ( string hash ) {
	
		root = del( hash  , root, min );
		
	
	}


	BTNode* Find_n_return(string hash , int & idx  ) {
		int i = 0;
		BTNode* temp = search(hash, root, &i);
		idx = i; 
		return temp; 
	}

	void Searching  (string hash) {

		int i = 0 ; 
		BTNode* temp  =  search (hash , root , &i  ) ;
		
		

		/*if (temp != NULL) {
			cout << temp->Hash_value[i] << endl;
			cout << temp->content[i] << endl;

		}*/

		if ( temp != NULL ) {
			stack<string> obj1 , obj2 ; 
			store(root , obj1 , obj2 );
			//// obj1 has the hashes 

			while ( ! obj1.empty ()  ) {
			   
				if (obj1.top () == temp->Hash_value [i]) {
					cout << obj1.top() << endl; 
					cout << obj2.top() << endl; 

				}

				obj1.pop(); 
				obj2.pop();

			}


		}

		else {
			cerr << "Hash Value doesnot exist.\n" ; 
		}

	}




};

