#pragma once

#include <iostream>
#include <windows.h>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include "Stack.h"
#include <filesystem>
#include <string>


//#define Max 4 
//#define Min 2 


using namespace std;
using namespace std::filesystem; 



void ChangePath_for_collisions ( string& Oldpath , int& idx_number  ) {

	int S1 = 0; 
	while ( Oldpath [S1] != '.') {
		S1++; 
	}
	char* Array = new char[S1 + 4 ]; 
	int i = 0;
	for (; i < S1 ; i++) {
		Array[i] = Oldpath[i]; 
	}
	Array[i] = '('; i++;
	idx_number = i; 
	Array[i] = '1'; i++; 
	Array[i] = ')'; i++; 
    Array[i] = '\0'; 


	Oldpath = Array; 
	Oldpath += ".txt"; 


}

void ChangePath_for_collisions2 (string& Oldpath, string str  ) {

	int S1 = 0;
	while (Oldpath[S1] != '(') {
		S1++;
	}
	char* Array = new char[S1 + str.length() + 4 ];
	int i = 0;
	for (; i < S1; i++) {
		Array[i] = Oldpath[i];
	}
	Array[i] = '('; i++;
	int j = 0; 
	while (str [j] != '\0') {
		Array[i] = str[j]; 
		i++; j++; 
	}


	Array[i] = ')'; i++;
	Array[i] = '\0';


	Oldpath = Array;
	Oldpath += ".txt";


}





struct BTNode {

	int count;
	string* Hash_value ;
	string* content  ; 

	BTNode** child  ;
	int FileCollision ; 



	BTNode( int m  ) {
		FileCollision = 0; 
		count = 1;
		child = new BTNode * [m ];
		Hash_value = new string [m ];
		content = new string[m];

		for (int i = 0; i< m; i++)
			content[i] = "H"; 
		
	}



};


// prototypes of the function. 
// Theek kr lia hai i think 
int setVal( string ,string&  , struct BTNode*, string* , string * , BTNode** , int , int );
struct BTNode* insert( string  ,string&  , BTNode* , int , int );
int searchnode(string, BTNode*, int*);


BTNode* search( string, BTNode*, int*);

void fillnode( string ,string  , BTNode*, BTNode*, int);
void split( string, string ,BTNode*, BTNode*, int, string*, string*  , BTNode** , int , int );


BTNode* del ( string , BTNode* , int ) ;
int delhelp ( string , BTNode* , int ) ;
void clear (BTNode*, int) ;
void restore (BTNode*, int , int ) ;


void rightshift (BTNode*, int);
void leftshift (BTNode*, int);
void merge (BTNode*, int);

void copysucc (BTNode* node, int i);

void display (BTNode*);



/* inserts a value in the B-tree */
struct BTNode* insert( string val, string& content  , BTNode* root , int Max , int Min ) {
	string i;
	string j; 

	BTNode* c, * n;
	int flag;
	flag = setVal(val, content , root, &i , &j, &c , Max, Min  );
	if (flag == true) {
		// n = (struct BTNode*)malloc(sizeof(struct BTNode));
	    n = new BTNode (Max+1); 

		n->count = 1;
		n->Hash_value[1] = i;
		
		n->content[1] = j; 

		n->child[0] = root;
		n->child[1] = c;
		return n;



	}

	return root;
}

/* sets the value in the node */

int setVal( string val, string& cont , BTNode* n, string* p, string * q , BTNode** c , int Max  , int Min ) {

	int k;
	if (n == NULL) {
		*p = val;
		*q = cont; 
		*c = NULL;
		return 1;
	}
	else
	{
		if (searchnode(val, n, &k)) {
			cout << "Key value already exists. \n";
			// change the file path. ( cont ) . 
			// i also now have to do file handling here.  
			int idx_number = 0; 
			ChangePath_for_collisions(cont , idx_number );

			while ( filesystem::exists (cont) ) {

				    /*char cc = cont[ idx_number ] ; 
					int ii = cc - '0';
					ii++; 
					cont[idx_number] = ii + '0'; */
				int num1 = cont.find('(') ;
				int num2 = cont.find(')');

				string NUM = cont.substr(num1 +1 , num2 -1 ) ;
			

				int Number = stoi(NUM) ;
				Number++; 
				NUM = to_string(Number);

				cout << "Cont : " << cont << endl;
				ChangePath_for_collisions2(cont , NUM ); // this ftn changes it to the new txt file   
			}



		}

		if ( setVal(val, cont , n->child[k], p, q ,  c , Max , Min  ) )
		{
			if (n->count < Max) {

				fillnode(*p,*q , *c, n, k);
				return 0;

			}
			else {

				split(*p, *q , *c, n, k, p, q ,  c, Max , Min  );
				return 1;
			}
		}


		

		return 0;
	}

}




BTNode* search(string val, BTNode* root, int* pos) {

	if (root == NULL)
		return NULL;
	else {

		if (searchnode(val, root, pos))
			return root;
		else
			return search(val, root->child[*pos], pos);
	}

}



/* searches values in the node */
int searchnode( string val, BTNode* n, int* pos) {

	if (val < n->Hash_value[1]) {
		*pos = 0;
		return 0;
	}
	else {

		*pos = n->count;
		while (val < n->Hash_value[*pos] && *pos > 1)
			(*pos)--;

		if (val == n->Hash_value[*pos])
			return 1;
		else
			return 0;

	}

}


/* adjust the value of the node */
void fillnode( string val, string cont , BTNode* c, BTNode* n, int k) {

	int i;

	for (i = n->count; i > k; i--) {

		n->Hash_value[i + 1] = n->Hash_value[i];

		// 
		n->content[i + 1] = n->content[i]; 
		//
		n->child[i + 1] = n->child[i];

	}

	n->Hash_value[k + 1] = val;
	//
	n->content[k + 1] = cont ; 
	//
	n->child[k + 1] = c;
	n->count++;

}


/* splits the node */
void split( string val, string cont ,  BTNode* c, BTNode* n, int k, string* y, string *x , struct BTNode** newnode , int Max , int Min ) {

	int i, mid;

	if (k <= Min)
		mid = Min;
	else
		mid = Min + 1;


	// *newnode = (struct BTNode*)malloc(sizeof(struct BTNode));
	*newnode = new BTNode (Max+1) ; 

	for (i = mid + 1; i <= Max; i++) {  

		(*newnode)->Hash_value[i - mid] = n->Hash_value[i];
		//
		(*newnode)->content  [i - mid] = n->content [i];
		//
		(*newnode)->child[i - mid] = n->child[i];

	}

	(*newnode)->count = Max - mid;
	n->count = mid;

	if (k <= Min)
		fillnode(val,cont  , c, n, k);
	else
		fillnode(val, cont , c, *newnode, k - mid);


	*y = n->Hash_value[n->count];
	*x = n->content[n->count]; 

	// yaha pr aik aur pointer ay ga for content 

	(*newnode)->child[0] = n->child[n->count];
	n->count--;


}


/////////////////////////////////////////////////

/* deletes value from the node */
BTNode* del(string val, BTNode* root , int Min ) {

	BTNode* temp;
	if (!delhelp(val, root , Min )) {

		cout << "\n";
		cout << "Value not found: " << val << "\n";

	}
	else {

		if (root->count == 0) {
			temp = root;
			root = root->child[0];
			free(temp);
		}

	}

	return root;
}


/*  helper functions for del()  */

int delhelp(string val, BTNode* root , int Min  ) {
	int i;
	int flag;

	if (root == NULL)
		return 0;

	else {

		flag = searchnode(val, root, &i);
		if (flag)
		{

			if (root->child[i - 1])
			{
				copysucc(root, i);

				flag = delhelp(root->Hash_value[i], root->child[i] , Min );
				if (!flag)
				{
					cout << "\n";
					cout << "Value not found " << val << "\n";
				}


			}
			else {
				clear(root, i);
			}
		}
		else {
			flag = delhelp(val, root->child[i] , Min );
		}


		if (root->child[i] != NULL)
		{
			if (root->child[i]->count < Min)
				restore(root, i , Min );
		}

		return flag;
	}


}


/* removes the value from the node and adjusts the values  */
void clear(BTNode* node, int k) {
	int i;
	for (i = k + 1; i <= node->count; i++) {
		node->Hash_value[i - 1] = node->Hash_value[i];
		//
		node->content[i - 1] = node->content[i]; 
		// 
		node->child[i - 1] = node->child[i];

	}

	node->count--;
}


/* copies the successor of the value that is t be deleted */
void copysucc(BTNode* node, int i)
{
	BTNode* temp;
	temp = node->child[i];

	while (temp->child[0])
		temp = temp->child[0];


	node->Hash_value[i] = temp->Hash_value[1];
	node->content[i] = temp->content[1]; 

}

/* adjust the node */
void restore(BTNode* node, int i , int Min ) {

	if (i == 0) {

		if (node->child[1]->count > Min)
			leftshift(node, 1);
		else
			merge(node, 1);

	}
	else {

		if (i == node->count)
		{
			if (node->child[i - 1]->count > Min)
				rightshift(node, i);
			else
				merge(node, i);

		}
		else {

			if (node->child[i - 1]->count > Min)
				rightshift(node, i);

			else {

				if (node->child[i + 1]->count > Min)
					leftshift(node, i + 1);
				else
					merge(node, i);

			}
		}
	}

}


/* adjusts the value and children while shifting the value from parent to right child */
void rightshift(BTNode* node, int k) {

	int i;
	BTNode* temp;
	temp = node->child[k];

	for (i = temp->count; i > 0; i--)
	{
		temp->Hash_value[i + 1] = temp->Hash_value[i];
		temp->content[i + 1] = temp->content [i];


		temp->child[i + 1] = temp->child[i];
	}

	temp->child[1] = temp->child[0];
	temp->count++;
	temp->Hash_value[1] = temp->Hash_value[k];
	temp->content[ 1] = temp->content[k];

	temp = node->child[k - 1];
	node->Hash_value[k] = temp->Hash_value[temp->count];
	node->content [k] = temp->content [temp->count];


	node->child[k]->child[0] = temp->child[temp->count];
	temp->count--;


}

/* adjusts the value and children while shifting the value from parent to left child */
void leftshift(BTNode* node, int k) {

	int i;
	BTNode* temp;

	temp = node->child[k - 1];
	temp->count++;
	temp->Hash_value[temp->count] = node->Hash_value[k];
	temp->content [temp->count] = node->content [k];


	temp->child[temp->count] = node->child[k]->child[0];

	temp = node->child[k];
	node->Hash_value[k] = temp->Hash_value[1];
	node->content [k] = temp->content [1];


	node->child[0] = temp->child[1];
	temp->count--;

	for (i = 1; i <= temp->count; i++)
	{
		temp->Hash_value[i] = temp->Hash_value[i + 1];
		temp->content [i] = temp->content [i + 1];


		temp->child[i] = temp->child[i + 1];
	}

}

/* merges two nodes */

void merge(BTNode* node, int k) {

	int i;
	BTNode* temp1, * temp2;

	temp1 = node->child[k];
	temp2 = node->child[k - 1];
	temp2->count++;
	temp2->Hash_value[temp2->count] = node->Hash_value[k];

	temp2->content  [temp2->count] = node->content [k];

	if (temp2->child[0] != NULL )
	temp2->child[temp2->count] = temp1->child[0];

	for (i = 1; i <= temp1->count; i++)
	{
		temp2->count++;
		temp2->Hash_value[temp2->count] = node->Hash_value[i];
		temp2->content [temp2->count] = node->content [i];

		temp2->child[temp2->count] = node->child[i];
	}

	for (i = k; i < node->count; i++)
	{
		node->Hash_value[i] = node->Hash_value[i + 1];
		node->content [i] = node->content [i + 1];


		node->child[i] = node->child[i + 1];
	}
	node->count--;
	free(temp1);

}



////////////// Display the tree inorder  //////////////
void display(BTNode* root) {
	int i;

	if (root != NULL)
	{
		for (i = 0; i < root->count; i++)
		{
			display(root->child[i]);
			cout << "  ";
			cout << root->Hash_value[i + 1];
			cout << "-";
			cout << root->content[i + 1]; 
		}
		display(root->child[i]);
	}


}


void store  (BTNode* root , stack<string> & obj1 , stack <string> & obj2  ) {
	int i;

	if (root != NULL)
	{
		for (i = 0; i < root->count; i++)
		{
			store  (root->child[i] , obj1  , obj2 );

			/* 
			cout << "  ";
			cout << root->Hash_value[i + 1];
			cout << "-";
			cout << root->content[i + 1]; */

			obj1.push(root->Hash_value[i + 1]) ;
			obj2.push(root->content[i + 1] ) ;

		}
		store  ( root->child[i] , obj1 , obj2 );
	}


}


