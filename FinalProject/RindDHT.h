#pragma once
#include "Machine.h"
#include <filesystem>

using namespace std::filesystem;
 
//void PrintBtree(Machine* node); 
//
//void PrintBtree( Machine* node ) {
//	if (node != nullptr )
//	node->PrintBtree(); 
//	return; 
//}


class RingDHT
{

	int BitsVar1 ; //( 0 -3 or more )
	int BitsVar2 ; // to take log with and other stuff.   
	int Order_m; 


public:
	Machine* head;
	Machine* tail;

	RingDHT(  int b  , int m )
	{
		tail = nullptr;
		head = NULL; 
		BitsVar1 = b -1 ; 
		BitsVar2 = b ; 
		Order_m = m; 
	}

	void addMachine(string name_machine,int bits)	//auto generated hash
	{
		Machine* cur = head;
		Machine* p = head;
		Machine *n_node=new Machine(name_machine  , Order_m );

		// create a function that if the hash of the new machine is already present then, Dont create the new machine. 
		//n_node->hash_bits( bits ); // ( 0-3 )

		n_node->hash = hashIT(BitsVar2, n_node->hash);


		if (head == nullptr)
		{
			head = n_node;
			n_node->next = head;
			tail = head;
		}
		else
		{
			bool found = 0;
			//a condition to check insertion at head
			if (n_node->hash < cur->hash)
			{
				n_node->next = head;
				head = n_node;
				tail->next = head;
				found = 1;
			}
			cur = head->next;
			while (cur != head && found != 1)
			{
				if (n_node->hash < cur->hash)
				{
					p->next = n_node;
					n_node->next = cur;
					found = 1;
					break;
				}
				p = cur;
				cur = cur->next;
			}
			if (found != 1)	//tail
			{
				p->next = n_node;
				n_node->next = head;
			}
		}
		tail = GetTail(head);
		createRT(bits);

		ReStructureBtree(n_node, n_node->next);

	}

	//void addMachine(int bits)	//hash taken as input from user 
	//{
	//	//machine created by asking for hashes 
	//	Machine *n_node=new Machine(Order_m , BitsVar2 );		//takes input of hash from user do it here insted of the constructor. 
	//	
	//	n_node->hash = hashIT(BitsVar2 , n_node->hash ) ;
	//	createDirectory(n_node->hash);
	//	if (head == nullptr)
	//	{
	//		head = n_node;
	//		n_node->next = head;
	//	}
	//	else
	//	{
	//		Machine* cur = head;
	//		bool f = 0; // bool to check if inserted or not 
	//		Machine* prev = head;
	//		bool aik_bar = true ; 
	//		while (cur->next != head  )
	//		{
	//			//int c1 = hexadecimalToDecimal(n_node->hash);
	//			//int c2 = hexadecimalToDecimal(cur->hash);
	//			if(n_node->hash<cur->hash)
	//			{
	//				prev->next = n_node;
	//				n_node->next = cur;
	//				f = 1;
	//			}
	//			prev = cur;
	//			cur = cur->next;
	//		
	//		}
	//		if (cur->next == head && f!=1 )
	//		{
	//		//	int c1 = hexadecimalToDecimal(n_node->hash);
	//		//	int c2 = hexadecimalToDecimal(head->hash);
	//			if (n_node->hash > head->hash)	//tail insertion
	//			{
	//				cur->next = n_node;
	//				n_node->next = head;
	//			}
	//			else if (n_node->hash <= head->hash)//insert at head
	//			{
	//				n_node->next = head;
	//				head->next = n_node;
	//				head = n_node;
	//			}
	//		}
	//	}
	//	
	//	tail = GetTail(head);
	//	createRT(bits);
	//}



	void ReStructureBtree (Machine * NewNode  , Machine * NextOfNewNode ) {
	  
		if (NewNode == NewNode ->next ) {
			// do nothing.  
			return; 
		}
		else if ( NextOfNewNode->BTree->GetRoot () == NULL ) {
		 // do nothing.  
			return; 
		}
		else if (NewNode == tail  ) {
			stack<string> obj1, obj2;
			store(NextOfNewNode->BTree->GetRoot(), obj1, obj2);

			while (!obj1.empty()) {

				if ( NextOfNewNode->hash < obj1.top() ) {
					AddFile_specificMachine(obj2.top(), NewNode);
					Deleting_a_file_on_a_specific_machine(obj1.top(), NextOfNewNode);
				}

				obj1.pop();
				obj2.pop();
			}
		
		
		}
		else {
			stack<string> obj1, obj2; 
			store(NextOfNewNode->BTree->GetRoot() , obj1 , obj2 );

			while ( ! obj1.empty () ) {
			
				if ( NewNode->hash >= obj1.top () )  {
					AddFile_specificMachine( obj2.top () , NewNode );
					Deleting_a_file_on_a_specific_machine( obj1.top () , NextOfNewNode ); 
				}


				obj1.pop(); 
				obj2.pop(); 
			}
		
		}


	
	}


	void addMachine (int bits) //hash taken as input from user 
	{
		Machine* cur = head;
		Machine* p = head;
		Machine* n_node = new Machine(Order_m, BitsVar2);

		    createDirectory(n_node->hash);


		if (head == nullptr)
		{
			head = n_node;
			n_node->next = head;
			tail = head;
		}
		else
		{
			bool found = 0;
			//a condition to check insertion at head
			if (n_node->hash < cur->hash)
			{
				n_node->next = head;
				head = n_node;
				tail->next = head;
				found = 1;
			}
			cur = head->next;
			while (cur != head && found != 1)
			{
				if (n_node->hash < cur->hash)
				{
					p->next = n_node;
					n_node->next = cur;
					found = 1;
					break;
				}
				p = cur;
				cur = cur->next;
			}
			if (found != 1)	//tail
			{
				p->next = n_node;
				n_node->next = head;
			}
		}
		tail = GetTail(head);
		createRT(bits);

		ReStructureBtree(n_node , n_node->next );

	}






	Machine* GetTail(Machine* head)		//munim ganda bacha hai
	{
		Machine* current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		return current;
	}
	string decToHexa(unsigned long long int n)
	{
		// ans string to store hexadecimal number 
		string ans = "";

		while (n != 0)
		{
			// remainder variable to store remainder 
			unsigned long long int rem = 0;
			// ch variable to store each character 
			char ch;
			// storing remainder in rem variable. 
			rem = n % 16;
			// check if temp < 10 
			if (rem < 10)
			{
				ch = rem + 48;
			}
			else
			{
				ch = rem + 55;
			}

			// updating the ans string with the character variable 
			ans += ch;
			n = n / 16;
		}

		// reversing the ans string to get the final result 
		int i = 0, j = ans.size() - 1;
		while (i <= j)
		{
			swap(ans[i], ans[j]);
			i++;
			j--;
		}
		return ans;
	}
	unsigned long long int hexadecimalToDecimal(string hash)	//works for 64 bits which is very good hehheheh
	{
		int len = hash.size();
		unsigned long long int base = 1;
		unsigned long long int dec_val = 0;

		for (int i = len - 1; i >= 0; i--)
		{
			if (hash[i] >= '0' && hash[i] <= '9') {
				dec_val += static_cast<unsigned long long int>(hash[i] - '0') * base;
				base = base * 16;
			}
			else if (hash[i] >= 'A' && hash[i] <= 'F') {
				dec_val += static_cast<unsigned long long int>(hash[i] - 'A' + 10) * base;
				base = base * 16;
			}
		}
		return dec_val;
	}

	void print_machines()	//jkust prints the machine name and hashes 
	{
		if (head == nullptr)
			return;
		else
		{
			Machine* cur = head;
			while (cur->next != head)
			{
				cout << cur->name << "  " << cur->hash << endl;
				//	cur->head_fingertable->printRT();//prints routing table
				cur = cur->next;
			}
			cout << cur->name << "  " << cur->hash << endl;
			///	cur->head_fingertable->printRT();
			cur = cur->next;

		}
	}
	void print_machine_RT() //print machine name + hash + routing table 
	{
		if (head == nullptr)
			return;
		else
		{
			Machine* cur = head;
			while (cur->next != head)
			{
				cout << "Machine: " << cur->name << "  Hash: " << cur->hash << endl;
				cur->head_fingertable->printRT();//prints routing table
				cur = cur->next;
			}
			cout << "Machine: " << cur->name << "  Hash:" << cur->hash << endl;
			cur->head_fingertable->printRT();
			cur = cur->next;

		}
	}
	void PrintBtree_of_a_machine() {

		if (head == nullptr ) {
			cerr << "No machines added yet.\n";
			return; 
		}
	
		cout << "Printing current machines:"; 
		print_machines();

		string Mac;
		cout << "Choose machine ID to whose Btree you want to see:";
		cin >> Mac; 

		Machine* curr = head; 
		bool f = 1;
		while (curr->hash != Mac ) {
			curr = curr->next; 
			if (curr == head) { f = 0;  break; }
		}
		

		if (f == 0 ) {
			cout << "Hash not found\n"; return; 
		}

		curr->PrintBtree(); 


	
	}
	//void transversal_route(int bits)	//this functions must be called during the insertion of the machines
	//{
	//	if (head != nullptr)
	//	{
	//		Machine* cur = head;
	//		while (cur != nullptr)
	//		{
	//			cur->createRoutingTable(cur,bits);
	//			cur = cur->next;
	//		}
	//	}
	//	
	//}
	void createRT(int bit_2)//used to create routing tbale for each machine
	{
		Machine* cur = head;
		if (head != nullptr)
		{
			while (cur->next != head)//acts as circular singly linked list
			{
				cur->head_fingertable = new RT(bit_2);
				cur->head_fingertable->updateFingerTable(cur,head,tail);  
				cur = cur->next;
			}
			if (cur->next == head)
			{
				cur->head_fingertable = new RT(bit_2);
				cur->head_fingertable->updateFingerTable(cur,head,tail);

			}

		}
		//in case sirf ek machine hai
		//if(cur->next==head)
		//{
		//	//cur->head_fingertable->cur_bit = 0;
		//	cur->head_fingertable = new RoutingTab(bit_2);
		//	cur->head_fingertable->updateFingerTable(cur);
		//}
	}


	void AddFile( string OldPath ) {
		string Content;

		Content = ReadTextFile(OldPath);

		SHA1 a;
		string hash_of_file = a.sha1(Content);

		//cout << hash_of_file << endl; 

		hash_of_file = hashIT( BitsVar2 , hash_of_file);

		//cout << hash_of_file << endl;

		cout << "Hash of file  "  << hash_of_file << endl;

		//cout << "Do you add the file to a specific machine or add it based on hash. \n";
		string choice;
	
		cout << "Do u want to insert automatically or manually? \n";
		cin >> choice;


		Machine* curr = head;
		string FilePath; 

		if (choice == "m" || choice == "M") {
			print_machines();


			cout << "Enter the ID of the Machine you want to enter the File to.\n";
			cin >> choice;
			if (head->hash == choice ) {
				curr = head; 
			}
			else {
				do {
					curr = curr->next;
				} while (curr->hash != choice && curr != head);
			}
			FilePath = curr->add_a_file(hash_of_file);
       

		}
		else {

			if (  hash_of_file <= curr->hash  ) {
				curr = head; 
			}
			else {

				

				Node* temp=curr->head_fingertable->head_table;
				int First = 1; 

				while ( (  First ||  curr != head  )  )
				{
					First = 0; 
					temp = curr->head_fingertable->head_table;
					while (temp->next != nullptr && hash_of_file > temp->mac->hash)
					{
						temp = temp->next;
					}
					if (hash_of_file <= temp->mac->hash)
					{
						//save the address of this machine and insert in this macihine
						curr = temp->mac; 
						break; 
					}
					else if (hash_of_file > temp->mac->hash)
					{
						curr = temp->mac;

					}
				}
				

		    }///////// else not head 
		
		   FilePath = curr->add_a_file(hash_of_file) ;
		}



			
	    	// file handling to store the file (copy). 

			cout << "File path " << FilePath << endl;
			createTextFile(FilePath);

			writeFile(FilePath, Content);
		

	}

	void AddFile_specificMachine (string OldPath , Machine * curr ) {
		string Content;

		Content = ReadTextFile(OldPath);
		//cout << "\nContent :  " << Content << endl;

		SHA1 a;
		string hash_of_file = a.sha1(Content);

		//cout << hash_of_file << endl; 

		hash_of_file = hashIT(BitsVar2, hash_of_file);

		//cout << hash_of_file << endl;

		cout << "Hash of file  " << hash_of_file << endl;
	
	
		string FilePath = curr->add_a_file(hash_of_file);

		// file handling to store the file (copy). 

		cout << "File path " << FilePath << endl;
		createTextFile(FilePath);

		writeFile(FilePath, Content);

	}


	void Search_a_hash( string hash_of_file) {
	
		Machine* curr = head; 

		if (hash_of_file <= curr->hash) {
			curr = head;
		}
		else {
		
			Node* temp = curr->head_fingertable->head_table;
			int First = 1;

			while ((First || curr != head))
			{
				First = 0;
				temp = curr->head_fingertable->head_table;
				while (temp->next != nullptr && hash_of_file > temp->mac->hash)
				{
					temp = temp->next;
				}
				if (hash_of_file <= temp->mac->hash)
				{
					//save the address of this machine and insert in this macihine
					curr = temp->mac;
					break;
				}
				else if (hash_of_file > temp->mac->hash)
				{
					curr = temp->mac;

				}
			}

		
		} // else not head 
	

		curr->BTree->Searching(hash_of_file);
	
	}


	/////////////////////////////////////////////////////////

	void deleteMachine_helper(string hash_machine)
	{
		if (head != nullptr)
		{
			bool found = 0;
			Machine* cur = head;
			Machine* prev = head;

			while (cur->next != head)
			{
				if (cur->hash == hash_machine)
				{
					found = 1;
					break;
				}
				prev = cur;
				cur = cur->next;
			}

			if (found == 1)
			{
				if (cur == head && cur->next!=head)
				{
					Machine* temp = head;
					head = head->next;
					tail->next = head;
					delete temp;
					createRT(BitsVar2);
				}
				else {
					//delete functionality
					Machine* temp = cur;
					prev->next = cur->next;
					//btree shifting fucntionality 
					delete temp;
					createRT(BitsVar2);
				}
			}
			else if (found == 0)	//incase the machine is the last node in the list 
			{
				if (cur == head && cur->next==head)
				{
					Machine* temp = head;
					//head = head->next;
					//tail->next = head;
					delete temp;
					tail = nullptr;
					head = nullptr;
					//createRT(BitsVar2);
				}
				else if (cur->hash == hash_machine)
				{
					//delete functionality
					Machine* temp = cur;
					prev->next = cur->next;
					tail = GetTail(head);
					//btree shifting fucntionality 
					delete temp;
					createRT(BitsVar2);
				}
			}
		}
	}

	/////////////////////////////////////////////////////////

	// when deleting a machine u have to do two things 
	// one is the file handling. 
	// other is the btree restructure. 
	void delete_a_machine(string ID_machine ) {
	   ////ID_machine is hash. 
		if (head == NULL ) {
			cerr << "No Machines added yet.\n";
			return;
		}

		Machine* Temp = head; 
		bool found = true; 
		while (Temp->hash != ID_machine  ) {
			Temp = Temp->next; 
			if (Temp == head) { found = 0;  break; }
		}

		if (found == 0 ) {
			cerr << "Hash Not found \n"; 
			return; 
		}
		Files* t =  Temp->BTree; 
		t->PrintTree(); 

		stack<string> obj1, obj2 , obj3 , obj4 ;

		BTNode* root = t->GetRoot(); 
		if (root != NULL) {

			stack<string> obj1, obj2;
			store(root, obj1, obj2);

			while (! obj2.empty () ) {
				AddFile_specificMachine(obj2.top () , Temp->next ); 

				obj2.pop(); 
			}

		}

		deleteFolder(Temp->hash ) ; 

		/// AddFile_specificMachine (string OldPath , Machine * curr )

		deleteMachine_helper(Temp->hash); 

	
	}



	void Delete_a_file(string hash_of_file) {
		Machine* curr = head;

		if (head == NULL ) {
			cerr << "No Machines added yet.\n";
			return; 
		}

		if (hash_of_file <= curr->hash) {
			curr = head;
		} 
		else {

			Node* temp = curr->head_fingertable->head_table;
			int First = 1;

			while ((First || curr != head))
			{
				First = 0;
				temp = curr->head_fingertable->head_table;
				while (temp->next != nullptr && hash_of_file > temp->mac->hash)
				{
					temp = temp->next;
				}
				if (hash_of_file <= temp->mac->hash)
				{
					//save the address of this machine and insert in this macihine
					curr = temp->mac;
					break;
				}
				else if (hash_of_file > temp->mac->hash)
				{
					curr = temp->mac;

				}
			}


		} // else not head 
	

		//curr->BTree->Delete_a_file (hash_of_file);
		int idx = 0; 
		BTNode* t = curr->BTree->Find_n_return(hash_of_file , idx );

		if (t != NULL )  {
			string path = t->content[idx];
			filesystem::remove(path);

			curr->BTree->Delete_a_file(hash_of_file);

		}
		else {
			cout << "No file \n"; 
		}
	
	}



	void Deleting_a_file_on_a_specific_machine (string hash_of_file , Machine* curr ) {
	
		if (head == NULL) {
			cerr << "No Machines added yet.\n";
			return;
		}


		//curr->BTree->Delete_a_file (hash_of_file);
		int idx = 0;
		BTNode* t = curr->BTree->Find_n_return(hash_of_file, idx);

		if (t != NULL) {
			string path = t->content[idx];
			filesystem::remove(path);

			curr->BTree->Delete_a_file(hash_of_file);

		}
		else {
			cout << "This file not present.\n";
		}

	}


};