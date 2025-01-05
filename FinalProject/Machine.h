#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include "SHA-1.h"
#include "FileTree.h"
#include "Filecreation.h"
#include "Filehandling.h"

//#include "RoutingTable.h"
using namespace std;

//class RoutingTable;
class RoutingTab;
class RT;

string hashIT(int n, string hash); 
string hexaToBinary(const string& hash, int char_no);
string binaryToHex(const string& binaryString);
void BitExtraction(string binary, int Bits, string& newHash); 


class Machine
{
public:
	std::string name; //supposed to be a hash 
	std::string hash;
	Machine* next;
	
	Files* BTree;
	RT* head_fingertable;
//	RoutingTab* head_fingertable;
	//Routingtab node;
	//RoutingTable* head_fingertable;	//routing Table
	Machine(std::string n , int m )
	{ 
		BTree = new Files (m) ; 
		next = nullptr;
		head_fingertable = nullptr;
		SHA1 a;
		name = n;
		hash=a.sha1(n);

		
	}


	void PrintBtree() {
	  
		cout << "Hash: " << hash << endl; 
		BTree->PrintTree(); 
		cout << endl; 
	}


	void BitExtraction(string binary, int Bits, string& newHash) {

		//cout<<binary<<endl;
		string Ans = "";

		int Size = binary.length();
		//cout<<Size<<endl;
		int tempSize = binary.length() - Bits;
		//cout <<"\nZeros to add " << tempSize << endl; 

		char* Array = new char[binary.length() + 1] {'0'};
		for (int i = 0; i < binary.length(); i++) 
		{
			Array[i] = '0';
		}
		int idx = tempSize;
		for (int i = idx; i < binary.length(); i++)
		{
			Array[i] = binary[i];
		}// cout << endl; 
		Ans = Array;
		newHash = Ans;
		//	cout <<  "OG:  " << binary << endl;
		//	cout  << "New: " << Ans << endl;

	}
	// Function to convert a hexadecimal character to a 4-bit binary string
	/*string hexCharToBinary(char hexChar) {
		switch (hexChar) {
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";

		default: return "Invalid";
		}
	}*/

	// Function to convert the hash string to binary
	string hexaToBinary(const string& hash, int char_no) {
		int count = hash.length();
		int i = 0;
		string ans;
		while (i < count)
		{
			switch (hash[i])
			{
			case '0':
				ans += "0000";
				i++;
				break;
			case '1':
				ans += "0001";
				i++;
				break;
			case '2':
				ans += "0010";
				i++;
				break;
			case '3':
				ans += "0011";
				i++;
				break;
			case '4':
				ans += "0100";
				i++;
				break;
			case '5':
				ans += "0101";
				i++;
				break;
			case '6':
				ans += "0110";
				i++;
				break;
			case '7':
				ans += "0111";
				i++;
				break;
			case '8':
				ans += "1000";
				i++;
				break;
			case '9':
				ans += "1001";
				i++;
				break;
			case 'A':
			case 'a':
				ans += "1010";
				i++;
				break;
			case 'B':
			case 'b':
				ans += "1011";
				i++;
				break;
			case 'C':
			case 'c':
				ans += "1100";
				i++;
				break;
			case 'D':
			case 'd':
				ans += "1101";
				i++;
				break;
			case 'E':
			case 'e':
				ans += "1110";
				i++;
				break;
			case 'F':
			case 'f':
				ans += "1111";
				i++;
				break;
			default:
				cout << "Invalid" << endl;;
			}
		}
	//	cout << ans << endl;
		return ans;
	}

	// Function to convert a binary string to a hexadecimal string
	string binaryToHex(const string& binaryString) {
		string finalans;

		int len = binaryString.length();

		string extract;
		for (int i = len - 1; i >= 0; i = i - 4)
		{
			for (int j = i, count = 0; count < 4 && j >= 0; j--, count++)
			{
				extract = binaryString[j] + extract;
			}

			if (extract == "0000")
				finalans = "0" + finalans;
			else if (extract == "0001")
				finalans = "1" + finalans;
			else if (extract == "0010")
				finalans = "2" + finalans;
			else if (extract == "0011")
				finalans = "3" + finalans;
			else if (extract == "0100")
				finalans = "4" + finalans;
			else if (extract == "0101")
				finalans = "5" + finalans;
			else if (extract == "0110")
				finalans = "6" + finalans;
			else if (extract == "0111")
				finalans = "7" + finalans;
			else if (extract == "1000")
				finalans = "8" + finalans;
			else if (extract == "1001")
				finalans = "9" + finalans;
			else if (extract == "1010")
				finalans = "A" + finalans;
			else if (extract == "1011")
				finalans = "B" + finalans;
			else if (extract == "1100")
				finalans = "C" + finalans;
			else if (extract == "1101")
				finalans = "D" + finalans;
			else if (extract == "1110")
				finalans = "E" + finalans;
			else if (extract == "1111")
				finalans = "F" + finalans;
			else
				cout << "Invalid" << endl;

			extract = "";
		}
	//	cout << finalans << endl;
		return finalans;
	}
	


	string hash_bits(int n)	//bits
	{
		 int a = hash.length();
		a--;
		string b;
		string newHash;
		//0 - 8 bts then last 2 chars
		//0-16 bits then last 4 chars
		//0-24 bits then last 6
		//0-32 birs then ;ast 8
		int char_no = 0;
		{
			if (n > 0 && n <= 4)
			{
				char_no = 1;
			}
			else if (n <= 8)
			{
				char_no = 2;
			}
			else if (n <= 12)
			{
				char_no = 3;
			}
			else if (n <= 16)
			{
				char_no = 4;
			}
			else if (n <= 20)
			{
				char_no = 5;
			}
			else if (n <= 24)
			{
				char_no = 6;
			}
			else if (n <= 28)
			{
				char_no = 7;
			}
			else if (n <= 32)
			{
				char_no = 8;
			}
			else if (n <= 36)
			{
				char_no = 9;
			}
			else if (n <= 40)
			{
				char_no = 10;
			}
			else if (n <= 44)
			{
				char_no = 11;
			}
			else if (n <= 48)
			{
				char_no = 12;
			}
			else if (n <= 52)
			{
				char_no = 13;
			}
			else if (n <= 56)
			{
				char_no = 14;
			}
			else if (n <= 60)
			{
				char_no = 15;
			}
			else if (n <= 64)
			{
				char_no = 16;
			}
			else if (n <= 68)
			{
				char_no = 17;
			}
			else if (n <= 72)
			{
				char_no = 18;
			}
			else if (n <= 76)
			{
				char_no = 19;
			}
			else if (n <= 80)
			{
				char_no = 20;
			}
			else if (n <= 84)
			{
				char_no = 21;
			}
			else if (n <= 88)
			{
				char_no = 22;
			}
			else if (n <= 92)
			{
				char_no = 23;
			}
			else if (n <= 96)
			{
				char_no = 24;
			}
			else if (n <= 100)
			{
				char_no = 25;
			}
			else if (n <= 104)
			{
				char_no = 26;
			}
			else if (n <= 108)
			{
				char_no = 27;
			}
			else if (n <= 112)
			{
				char_no = 28;
			}
			else if (n <= 116)
			{
				char_no = 29;
			}
			else if (n <= 120)
			{
				char_no = 30;
			}
			else if (n <= 124)
			{
				char_no = 31;
			}
			else if (n <= 128)
			{
				char_no = 32;
			}
			else if (n <= 132)
			{
				char_no = 33;
			}
			else if (n <= 136)
			{
				char_no = 34;
			}
			else if (n <= 140)
			{
				char_no = 35;
			}
			else if (n <= 144)
			{
				char_no = 36;
			}
			else if (n <= 148)
			{
				char_no = 37;
			}
			else if (n <= 152)
			{
				char_no = 38;
			}
			else if (n <= 156)
			{
				char_no = 39;
			}
			else if (n <= 160)
			{
				char_no = 40;
			}
		}
		while (char_no > 0)
		{
			b = hash[a] + b;
			a--;
			char_no--;;
		}
		hash = b;

		string hexa_to_binary = hexaToBinary(hash, char_no);
		BitExtraction(hexa_to_binary, n, newHash);
		//cout << newHash << endl;
		newHash = binaryToHex(newHash);
		hash = newHash;



		return b;

	}

	void fixlen(string& hash, int bit)
	{
		int len = hash.length();
		//cout << len << endl;
		//cout << bit << endl;
		while (len < bit)
		{
			hash = "0" + hash;
			len = hash.length();
		}
	}

	Machine( int m , int Bits_n  )
	{
		BTree = new Files (m); 
		head_fingertable = nullptr;
		next = nullptr;
		//r = nullptr;
		int n = Bits_n; 
		/*cout << "Enter your bit space number: \n";
		cin >> n;*/

		int n2 = log2(n);
		cout << "Enter the hash: \n";
		cin >> hash;
		if (hash.length() > n2)
		{
			while (hash.length() <= n2)
			{
				cout << "Enter the hash: \n";
				cin >> hash;
			}
		}
		cout << "Name the machine: \n";
		cin >> name;
		if (hash.length() < n2)
		{
			//fixlen(hash, n2);
			hash = hashIT(n , hash  ); 
		}
		
	}

	string add_a_file( string& hash_of_file ) {
	 
		string Path_of_file = hash + "\\" + hash_of_file + ".txt" ;

		BTree->insert_a_file( hash_of_file , Path_of_file ) ;


		return Path_of_file; 
	}
	
};

//class RoutingTable
//{
//	Machine* start;	//doubly linked list 
//	Machine* next;
//	Machine* prev;
//	int id_bits;
//	//string hashes;	//string form of hashes
//	//int hash_int;	//converted to integer
//public:
//	RoutingTable()
//	{
//		start = NULL;
//	}
//	RoutingTable(int bits)
//	{
//		next = prev = nullptr;
//		start = new Machine[bits];
//		id_bits = bits;
//		for (int i = 0; i < id_bits; i++)
//		{
//			start[i].hash = "";
//		}
//	}
//	void updateFingerTable(Machine* head)
//	{
//
//		Machine* cur = head;
//		int i = 1;
//		while (cur->next != head)
//		{
//			unsigned long long hash_convert_int = hexadecimalToDecimal(cur->hash);
//			hash_convert_int  += pow(2, i - 1);
//			string hash_convert_hex = decToHexa(hash_convert_int);
//			Machine* find_node = new Machine();
//			find_node=findwithhash(hash_convert_hex, head);
//			start[i].hash = find_node->hash;
//			start[i].name = find_node->name;
//			i++;
//			cur = cur->next;
//		}
//		makeDoubly();
//	}
//	Machine* findwithhash(string hash,Machine* head)
//	{
//		
//		Machine* cur = head;
//		int bit_no = head->hash.length();	//this identifies the number of bits used in identifier space
//		hash = hashIT(bit_no, hash);
//		while (cur->next != head)	//searches in singly linked list
//		{
//			if (cur->hash == hash)
//			{
//				return cur;
//			}
//			cur = cur->next;
//		}
//		return nullptr;
//	}
//	string decToHexa(unsigned long long int n)
//	{
//		// ans string to store hexadecimal number 
//		string ans = "";
//
//		while (n != 0) 
//		{
//			// remainder variable to store remainder 
//			unsigned long long int rem = 0;
//			// ch variable to store each character 
//			char ch;
//			// storing remainder in rem variable. 
//			rem = n % 16;
//			// check if temp < 10 
//			if (rem < 10) 
//			{
//				ch = rem + 48;
//			}
//			else 
//			{
//				ch = rem + 55;
//			}
//
//			// updating the ans string with the character variable 
//			ans += ch;
//			n = n / 16;
//		}
//
//		// reversing the ans string to get the final result 
//		int i = 0, j = ans.size() - 1;
//		while (i <= j)
//		{
//			swap(ans[i], ans[j]);
//			i++;
//			j--;
//		}
//		return ans;
//	}
//	unsigned long long int hexadecimalToDecimal(string hash)	//works for 64 bits which is very good hehheheh
//	{
//		int len = hash.size();
//		unsigned long long int base = 1;
//		unsigned long long int dec_val = 0;
//
//		for (int i = len - 1; i >= 0; i--)
//		{
//			if (hash[i] >= '0' && hash[i] <= '9') {
//				dec_val += static_cast<unsigned long long int>(hash[i] - '0') * base;
//				base = base * 16;
//			}
//			else if (hash[i] >= 'A' && hash[i] <= 'F') {
//				dec_val += static_cast<unsigned long long int>(hash[i] - 'A' + 10) * base;
//				base = base * 16;
//			}
//		}
//		return dec_val;
//	}
//	string hashIT(int n,string hash)	//bits
//	{
//		int a = hash.length();
//		a--;
//		string b;
//		//0 - 8 bts then last 2 chars
//		//0-16 bits then last 4 chars
//		//0-24 bits then last 6
//		//0-32 birs then ;ast 8
//		int char_no = 0;
//		{
//			if (n >= 0 && n < 4)
//			{
//				char_no = 1;
//			}
//			else if (n < 8)
//			{
//				char_no = 2;
//			}
//			else if (n < 12)
//			{
//				char_no = 3;
//			}
//			else if (n < 16)
//			{
//				char_no = 4;
//			}
//			else if (n < 20)
//			{
//				char_no = 5;
//			}
//			else if (n < 24)
//			{
//				char_no = 6;
//			}
//			else if (n < 28)
//			{
//				char_no = 7;
//			}
//			else if (n < 32)
//			{
//				char_no = 8;
//			}
//			else if (n < 36)
//			{
//				char_no = 9;
//			}
//			else if (n < 40)
//			{
//				char_no = 10;
//			}
//			else if (n < 44)
//			{
//				char_no = 11;
//			}
//			else if (n < 48)
//			{
//				char_no = 12;
//			}
//			else if (n < 52)
//			{
//				char_no = 13;
//			}
//			else if (n < 56)
//			{
//				char_no = 14;
//			}
//			else if (n < 60)
//			{
//				char_no = 15;
//			}
//			else if (n < 64)
//			{
//				char_no = 16;
//			}
//			else if (n < 68)
//			{
//				char_no = 17;
//			}
//			else if (n < 72)
//			{
//				char_no = 18;
//			}
//			else if (n < 76)
//			{
//				char_no = 19;
//			}
//			else if (n < 80)
//			{
//				char_no = 20;
//			}
//			else if (n < 84)
//			{
//				char_no = 21;
//			}
//			else if (n < 88)
//			{
//				char_no = 22;
//			}
//			else if (n < 92)
//			{
//				char_no = 23;
//			}
//			else if (n < 96)
//			{
//				char_no = 24;
//			}
//			else if (n < 100)
//			{
//				char_no = 25;
//			}
//			else if (n < 104)
//			{
//				char_no = 26;
//			}
//			else if (n < 108)
//			{
//				char_no = 27;
//			}
//			else if (n < 112)
//			{
//				char_no = 28;
//			}
//			else if (n < 116)
//			{
//				char_no = 29;
//			}
//			else if (n < 120)
//			{
//				char_no = 30;
//			}
//			else if (n < 124)
//			{
//				char_no = 31;
//			}
//			else if (n < 128)
//			{
//				char_no = 32;
//			}
//			else if (n < 132)
//			{
//				char_no = 33;
//			}
//			else if (n < 136)
//			{
//				char_no = 34;
//			}
//			else if (n < 140)
//			{
//				char_no = 35;
//			}
//			else if (n < 144)
//			{
//				char_no = 36;
//			}
//			else if (n < 148)
//			{
//				char_no = 37;
//			}
//			else if (n < 152)
//			{
//				char_no = 38;
//			}
//			else if (n < 156)
//			{
//				char_no = 39;
//			}
//			else if (n < 160)
//			{
//				char_no = 40;
//			}
//		}
//		while (char_no > 0)
//		{
//			b = hash[a] + b;
//			a--;
//			char_no--;;
//		}
//		hash = b;
//		return b;
//
//	}
//	void makeDoubly()
//	{
//	
//	}
//
//};    

class DNode
{
public:
	Machine* mac;
	DNode* next;
	DNode* prev;
	DNode()
	{
		mac = nullptr;
		next = prev = nullptr;
	}
	DNode(Machine *a)
	{
		mac = a;
		next = prev = nullptr;
	}
};

//
////class RoutingTab
//{
//public:
//	DNode* head_ta;
//	int bits;
//	int cur_bit;
//	RoutingTab()
//	{
//		head_ta = nullptr;
//		bits = 0;
//		cur_bit = 0;
//	}
//	RoutingTab(int bit)
//	{
//		head_ta = nullptr;
//		bits =log2(bit);
//		cur_bit = 0;
//
//	}
//	void updateFingerTable(Machine* node,Machine* head)
//	{
//
//		Machine* cur = node;
//		int i = 1;
//		
//		DNode* p = nullptr;
//			while (cur_bit < bits)
//			{
//				cur_bit++;
//				unsigned long long hash_convert_int = hexadecimalToDecimal(cur->hash);
//				hash_convert_int += pow(2, i - 1);	//hash converted to integer
//				string hash_convert_hex = decToHexa(hash_convert_int);
//				Machine* find_node;
//				find_node = findwithhash(hash_convert_hex, cur,head);
//				DNode* c = head_ta;
//				DNode* n_node = new DNode(find_node);
//				if (c != nullptr)
//				{
//					while (c->next != nullptr)
//					{
//						p = c;
//						c = c->next;	//dnode
//					}
//					c->prev = p;
//					c->next = n_node;
//				}
//				else if (head_ta == nullptr)
//				{
//					//head_ta->prev = nullptr;
//					head_ta = n_node;
//				}
//				i++;
//			}
//		
//	}
//	Machine* findwithhash(string hash, Machine* head_2, Machine* head)//head_2 is currently the current pointer
//	{
//
//		Machine* cur = head_2;
//		int bit_no = head->hash.length();	//this identifies the number of bits used in identifier space
//		bit_no--;
//		bit_no *= 4;
//		this->hashIT(bit_no, hash);
//	//	hash = hashIT(bit_no, hash);
//		
//		if (cur->next == head)//sirf ek val
//			return head;
//
//		if (cur->next != head_2)
//		{
//			cur = cur->next;
//			while (cur != head_2)
//			{
//				//int c1 = hexadecimalToDecimal(cur->hash);
//				//int c2 = hexadecimalToDecimal(hash);
//				if (cur->hash >= hash)
//				//if(c1>=c2)
//				{
//					return cur;
//				}
//				cur = cur->next;
//			}
//		}
//		if (cur->hash>hash || cur->hash<hash)
//		{
//			return head;
//		}
//	}
//	
//	string decToHexa(unsigned long long int n)
//	{
//		// ans string to store hexadecimal number 
//		string ans = "";
//
//		while (n != 0)
//		{
//			// remainder variable to store remainder 
//			unsigned long long int rem = 0;
//			// ch variable to store each character 
//			char ch;
//			// storing remainder in rem variable. 
//			rem = n % 16;
//			// check if temp < 10 
//			if (rem < 10)
//			{
//				ch = rem + 48;
//			}
//			else
//			{
//				ch = rem + 55;
//			}
//
//			// updating the ans string with the character variable 
//			ans += ch;
//			n = n / 16;
//		}
//
//		// reversing the ans string to get the final result 
//		int i = 0, j = ans.size() - 1;
//		while (i <= j)
//		{
//			swap(ans[i], ans[j]);
//			i++;
//			j--;
//		}
//		return ans;
//	}
//	unsigned long long int hexadecimalToDecimal(string hash)	//works for bits which is very good hehheheh
//	{
//		int len = hash.size();
//		unsigned long long int base = 1;
//		unsigned long long int dec_val = 0;
//
//		for (int i = len - 1; i >= 0; i--)
//		{
//			if (hash[i] >= '0' && hash[i] <= '9') {
//				dec_val += static_cast<unsigned long long int>(hash[i] - '0') * base;
//				base = base * 16;
//			}
//			else if (hash[i] >= 'A' && hash[i] <= 'F') {
//				dec_val += static_cast<unsigned long long int>(hash[i] - 'A' + 10) * base;
//				base = base * 16;
//			}
//		}
//		return dec_val;
//	}
//
//
//
//
//void BitExtraction(string binary, int Bits, string& newHash) {
//
//	//cout<<binary<<endl;
//	string Ans = "";
//
//	int Size = binary.length();
//	//cout<<Size<<endl;
//	int tempSize = binary.length() - Bits;
//	//cout <<"\nZeros to add " << tempSize << endl; 
//
//	char* Array = new char[binary.length() + 1] {'0'};
//	for (int i = 0; i < binary.length(); i++)
//	{
//		Array[i] = '0';
//	}
//	int idx = tempSize;
//	for (int i = idx; i < binary.length(); i++)
//	{
//		Array[i] = binary[i];
//	}// cout << endl; 
//	Ans = Array;
//	newHash = Ans;
//	//	cout <<  "OG:  " << binary << endl;
//	//	cout  << "New: " << Ans << endl;
//
//}
//// Function to convert a hexadecimal character to a 4-bit binary string
///*string hexCharToBinary(char hexChar) {
//	switch (hexChar) {
//	case '0': return "0000";
//	case '1': return "0001";
//	case '2': return "0010";
//
//	default: return "Invalid";
//	}
//}*/
//
//// Function to convert the hash string to binary
//string hexaToBinary(const string& hash, int char_no) {
//	int count = hash.length();
//	int i = 0;
//	string ans;
//	while (i < count)
//	{
//		switch (hash[i])
//		{
//		case '0':
//			ans += "0000";
//			i++;
//			break;
//		case '1':
//			ans += "0001";
//			i++;
//			break;
//		case '2':
//			ans += "0010";
//			i++;
//			break;
//		case '3':
//			ans += "0011";
//			i++;
//			break;
//		case '4':
//			ans += "0100";
//			i++;
//			break;
//		case '5':
//			ans += "0101";
//			i++;
//			break;
//		case '6':
//			ans += "0110";
//			i++;
//			break;
//		case '7':
//			ans += "0111";
//			i++;
//			break;
//		case '8':
//			ans += "1000";
//			i++;
//			break;
//		case '9':
//			ans += "1001";
//			i++;
//			break;
//		case 'A':
//		case 'a':
//			ans += "1010";
//			i++;
//			break;
//		case 'B':
//		case 'b':
//			ans += "1011";
//			i++;
//			break;
//		case 'C':
//		case 'c':
//			ans += "1100";
//			i++;
//			break;
//		case 'D':
//		case 'd':
//			ans += "1101";
//			i++;
//			break;
//		case 'E':
//		case 'e':
//			ans += "1110";
//			i++;
//			break;
//		case 'F':
//		case 'f':
//			ans += "1111";
//			i++;
//			break;
//		default:
//			cout << "Invalid" << endl;;
//		}
//	}
//	//	cout << ans << endl;
//	return ans;
//}
//
//// Function to convert a binary string to a hexadecimal string
//string binaryToHex(const string& binaryString) {
//	string finalans;
//
//	int len = binaryString.length();
//
//	string extract;
//	for (int i = len - 1; i >= 0; i = i - 4)
//	{
//		for (int j = i, count = 0; count < 4 && j >= 0; j--, count++)
//		{
//			extract = binaryString[j] + extract;
//		}
//
//		if (extract == "0000")
//			finalans = "0" + finalans;
//		else if (extract == "0001")
//			finalans = "1" + finalans;
//		else if (extract == "0010")
//			finalans = "2" + finalans;
//		else if (extract == "0011")
//			finalans = "3" + finalans;
//		else if (extract == "0100")
//			finalans = "4" + finalans;
//		else if (extract == "0101")
//			finalans = "5" + finalans;
//		else if (extract == "0110")
//			finalans = "6" + finalans;
//		else if (extract == "0111")
//			finalans = "7" + finalans;
//		else if (extract == "1000")
//			finalans = "8" + finalans;
//		else if (extract == "1001")
//			finalans = "9" + finalans;
//		else if (extract == "1010")
//			finalans = "A" + finalans;
//		else if (extract == "1011")
//			finalans = "B" + finalans;
//		else if (extract == "1100")
//			finalans = "C" + finalans;
//		else if (extract == "1101")
//			finalans = "D" + finalans;
//		else if (extract == "1110")
//			finalans = "E" + finalans;
//		else if (extract == "1111")
//			finalans = "F" + finalans;
//		else
//			cout << "Invalid" << endl;
//
//		extract = "";
//	}
//	//	cout << finalans << endl;
//	return finalans;
//}
//
//string hashIT(int n,string hash)	//bits
//{
//	int a = hash.length();
//	a--;
//	string b;
//	string newHash;
//	//0 - 8 bts then last 2 chars
//	//0-16 bits then last 4 chars
//	//0-24 bits then last 6
//	//0-32 birs then ;ast 8
//	int char_no = 0;
//	
//		if (n >= 0 && n < 4)
//		{
//			char_no = 1;
//		}
//		else if (n < 8)
//		{
//			char_no = 2;
//		}
//		else if (n < 12)
//		{
//			char_no = 3;
//		}
//		else if (n < 16)
//		{
//			char_no = 4;
//		}
//		else if (n < 20)
//		{
//			char_no = 5;
//		}
//		else if (n < 24)
//		{
//			char_no = 6;
//		}
//		else if (n < 28)
//		{
//			char_no = 7;
//		}
//		else if (n < 32)
//		{
//			char_no = 8;
//		}
//		else if (n < 36)
//		{
//			char_no = 9;
//		}
//		else if (n < 40)
//		{
//			char_no = 10;
//		}
//		else if (n < 44)
//		{
//			char_no = 11;
//		}
//		else if (n < 48)
//		{
//			char_no = 12;
//		}
//		else if (n < 52)
//		{
//			char_no = 13;
//		}
//		else if (n < 56)
//		{
//			char_no = 14;
//		}
//		else if (n < 60)
//		{
//			char_no = 15;
//		}
//		else if (n < 64)
//		{
//			char_no = 16;
//		}
//		else if (n < 68)
//		{
//			char_no = 17;
//		}
//		else if (n < 72)
//		{
//			char_no = 18;
//		}
//		else if (n < 76)
//		{
//			char_no = 19;
//		}
//		else if (n < 80)
//		{
//			char_no = 20;
//		}
//		else if (n < 84)
//		{
//			char_no = 21;
//		}
//		else if (n < 88)
//		{
//			char_no = 22;
//		}
//		else if (n < 92)
//		{
//			char_no = 23;
//		}
//		else if (n < 96)
//		{
//			char_no = 24;
//		}
//		else if (n < 100)
//		{
//			char_no = 25;
//		}
//		else if (n < 104)
//		{
//			char_no = 26;
//		}
//		else if (n < 108)
//		{
//			char_no = 27;
//		}
//		else if (n < 112)
//		{
//			char_no = 28;
//		}
//		else if (n < 116)
//		{
//			char_no = 29;
//		}
//		else if (n < 120)
//		{
//			char_no = 30;
//		}
//		else if (n < 124)
//		{
//			char_no = 31;
//		}
//		else if (n < 128)
//		{
//			char_no = 32;
//		}
//		else if (n < 132)
//		{
//			char_no = 33;
//		}
//		else if (n < 136)
//		{
//			char_no = 34;
//		}
//		else if (n < 140)
//		{
//			char_no = 35;
//		}
//		else if (n < 144)
//		{
//			char_no = 36;
//		}
//		else if (n < 148)
//		{
//			char_no = 37;
//		}
//		else if (n < 152)
//		{
//			char_no = 38;
//		}
//		else if (n < 156)
//		{
//			char_no = 39;
//		}
//		else if (n < 160)
//		{
//			char_no = 40;
//		}
//	
//	while (char_no > 0)
//	{
//		if (a<0 && char_no != 0)
//		{
//			b = '0' + b;
//			char_no--;;
//			continue;
//		}
//		b = hash[a] + b;
//		a--;
//		char_no--;;
//	}
//	hash = b;
//	//cout << hash << endl;
//	string hexa_to_binary = hexaToBinary(hash, char_no);
//	BitExtraction(hexa_to_binary, n, newHash);
//	//cout << newHash << endl;
//	newHash = binaryToHex(newHash);
//	hash = newHash;
//	return newHash;
//
//}
//
//
//
//
//	void printRT()
//	{
//		if (head_ta != nullptr)
//		{
//			DNode* cur = head_ta;
//			for(int i=0 ;i<cur_bit;i++)
//			{
//				cout << cur->mac->hash << endl;
//				cur = cur->next;
//			}
//		}
//	}
//};


void BitExtraction(string binary, int Bits, string& newHash) {

	//cout<<binary<<endl;
	string Ans = "";

	int Size = binary.length();
	//cout<<Size<<endl;
	int tempSize = binary.length() - Bits;
	//cout <<"\nZeros to add " << tempSize << endl; 

	char* Array = new char[binary.length() + 1] {'0'};
	for (int i = 0; i < binary.length(); i++)
	{
		Array[i] = '0';
	}
	int idx = tempSize;
	for (int i = idx; i < binary.length(); i++)
	{
		Array[i] = binary[i];
	}// cout << endl; 
	Ans = Array;
	newHash = Ans;
	//	cout <<  "OG:  " << binary << endl;
	//	cout  << "New: " << Ans << endl;

}



// Function to convert the hash string to binary
string hexaToBinary(const string& hash, int char_no) {
	int count = hash.length();
	int i = 0;
	string ans;
	while (i < count)
	{
		switch (hash[i])
		{
		case '0':
			ans += "0000";
			i++;
			break;
		case '1':
			ans += "0001";
			i++;
			break;
		case '2':
			ans += "0010";
			i++;
			break;
		case '3':
			ans += "0011";
			i++;
			break;
		case '4':
			ans += "0100";
			i++;
			break;
		case '5':
			ans += "0101";
			i++;
			break;
		case '6':
			ans += "0110";
			i++;
			break;
		case '7':
			ans += "0111";
			i++;
			break;
		case '8':
			ans += "1000";
			i++;
			break;
		case '9':
			ans += "1001";
			i++;
			break;
		case 'A':
		case 'a':
			ans += "1010";
			i++;
			break;
		case 'B':
		case 'b':
			ans += "1011";
			i++;
			break;
		case 'C':
		case 'c':
			ans += "1100";
			i++;
			break;
		case 'D':
		case 'd':
			ans += "1101";
			i++;
			break;
		case 'E':
		case 'e':
			ans += "1110";
			i++;
			break;
		case 'F':
		case 'f':
			ans += "1111";
			i++;
			break;
		default:
			cout << "Invalid" << endl;;
		}
	}
	//	cout << ans << endl;
	return ans;
}

// Function to convert a binary string to a hexadecimal string
string binaryToHex(const string& binaryString) {
	string finalans;

	int len = binaryString.length();

	string extract;
	for (int i = len - 1; i >= 0; i = i - 4)
	{
		for (int j = i, count = 0; count < 4 && j >= 0; j--, count++)
		{
			extract = binaryString[j] + extract;
		}

		if (extract == "0000")
			finalans = "0" + finalans;
		else if (extract == "0001")
			finalans = "1" + finalans;
		else if (extract == "0010")
			finalans = "2" + finalans;
		else if (extract == "0011")
			finalans = "3" + finalans;
		else if (extract == "0100")
			finalans = "4" + finalans;
		else if (extract == "0101")
			finalans = "5" + finalans;
		else if (extract == "0110")
			finalans = "6" + finalans;
		else if (extract == "0111")
			finalans = "7" + finalans;
		else if (extract == "1000")
			finalans = "8" + finalans;
		else if (extract == "1001")
			finalans = "9" + finalans;
		else if (extract == "1010")
			finalans = "A" + finalans;
		else if (extract == "1011")
			finalans = "B" + finalans;
		else if (extract == "1100")
			finalans = "C" + finalans;
		else if (extract == "1101")
			finalans = "D" + finalans;
		else if (extract == "1110")
			finalans = "E" + finalans;
		else if (extract == "1111")
			finalans = "F" + finalans;
		else
			cout << "Invalid" << endl;

		extract = "";
	}
	//	cout << finalans << endl;
	return finalans;
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




string hashIT(int n, string hash)	//bits
{
	int a = hash.length();
	a--;
	string b;
	string newHash;

	int char_no = 0;

	
		if ( n <= 4)
		{
			char_no = 1;
		}
		else if (n <= 8)
		{
			char_no = 2;
		}
		else if (n <= 12)
		{
			char_no = 3;
		}
		else if (n <= 16)
		{
			char_no = 4;
		}
		else if (n <= 20)
		{
			char_no = 5;
		}
		else if (n <= 24)
		{
			char_no = 6;
		}
		else if (n <= 28)
		{
			char_no = 7;
		}
		else if (n <= 32)
		{
			char_no = 8;
		}
		else if (n <= 36)
		{
			char_no = 9;
		}
		else if (n <= 40)
		{
			char_no = 10;
		}
		else if (n <= 44)
		{
			char_no = 11;
		}
		else if (n <= 48)
		{
			char_no = 12;
		}
		else if (n <= 52)
		{
			char_no = 13;
		}
		else if (n <= 56)
		{
			char_no = 14;
		}
		else if (n <= 60)
		{
			char_no = 15;
		}
		else if (n <= 64)
		{
			char_no = 16;
		}
		else if (n <= 68)
		{
			char_no = 17;
		}
		else if (n <= 72)
		{
			char_no = 18;
		}
		else if (n <= 76)
		{
			char_no = 19;
		}
		else if (n <= 80)
		{
			char_no = 20;
		}
		else if (n <= 84)
		{
			char_no = 21;
		}
		else if (n <= 88)
		{
			char_no = 22;
		}
		else if (n <= 92)
		{
			char_no = 23;
		}
		else if (n <= 96)
		{
			char_no = 24;
		}
		else if (n <= 100)
		{
			char_no = 25;
		}
		else if (n <= 104)
		{
			char_no = 26;
		}
		else if (n <= 108)
		{
			char_no = 27;
		}
		else if (n <= 112)
		{
			char_no = 28;
		}
		else if (n <= 116)
		{
			char_no = 29;
		}
		else if (n <= 120)
		{
			char_no = 30;
		}
		else if (n <= 124)
		{
			char_no = 31;
		}
		else if (n <= 128)
		{
			char_no = 32;
		}
		else if (n <= 132)
		{
			char_no = 33;
		}
		else if (n <= 136)
		{
			char_no = 34;
		}
		else if (n <= 140)
		{
			char_no = 35;
		}
		else if (n <= 144)
		{
			char_no = 36;
		}
		else if (n <= 148)
		{
			char_no = 37;
		}
		else if (n <= 152)
		{
			char_no = 38;
		}
		else if (n <= 156)
		{
			char_no = 39;
		}
		else if (n <= 160)
		{
			char_no = 40;
		}
	

	while (char_no >0)
	{
		if (a < 0 && char_no != 0  && char_no > 0 )
		{
			b = '0' + b;
			char_no--;;
			continue;
		}
		b = hash[a] + b;
		a--;
		char_no--;;
	}
	hash = b;
	//cout << hash << endl;
	string hexa_to_binary = hexaToBinary(hash, char_no);
	BitExtraction(hexa_to_binary, n , newHash );
	//cout << newHash << endl;
	newHash = binaryToHex(newHash);
	hash = newHash;

	return newHash;

}




class Node		//substitution of DNode
{
public:
	Machine* mac;
	Node* next;
	Node* prev;
	Node()
	{
		mac = nullptr;
		next = prev = nullptr;
	}
	Node(Machine* a)
	{
		mac = a;
		next = prev = nullptr;
	}

};

//
//class RT
//{
//public:
//	Node* head_table;
//	int bit;
//	int cur_bit;
//	RT()
//	{
//		head_table = nullptr;
//		bit = 0;
//		cur_bit = 0;
//	}
//	RT(int bit_con)
//	{
//		bit = log2(bit_con);
//		cur_bit = 0;
//		head_table = nullptr;
//	}
//	void updateFingerTable(Machine* node, Machine* head)
//	{
//		Machine* cur = node;
//		int i = 1;
//		Node* p = nullptr;
//		while (cur_bit < bit)
//		{
//			cur_bit++;
//			int add_value = pow(2, i - 1);
//			string add_val_str = to_string(add_value);
//			string hash_converted = addHexStrings(cur->hash, add_val_str);	//adding hash+power formula
//			//now find node with this value 
//			Machine* find_node = findwithhash(hash_converted, cur, head);
//			Node* c = head_table;
//			Node* n_node = new Node(find_node);
//			if (c != nullptr)
//			{
//				while (c->next != nullptr)
//				{
//					p = c;
//					c = c->next;	//dnode
//				}
//				c->prev = p;
//				c->next = n_node;
//				n_node->prev = c; 
//
//			}
//			else if (head_table == nullptr)
//			{
//				//head_ta->prev = nullptr;
//				head_table = n_node;
//			}
//			i++;
//
//
//
//		}
//	}
//	Machine* findwithhash(string hash, Machine* head_2, Machine* head)//head_2 is currently the current pointer
//	{
//
//		Machine* cur = head_2;
//		int bit_no = head->hash.length();	//this identifies the number of bits used in identifier space
//		bit_no--;
//		bit_no *= 4;
//		this->hashIT(bit_no, hash);
//		//	hash = hashIT(bit_no, hash);
//
//		if (cur->next == head)//sirf ek val
//			return head;
//
//		if (cur->next != head_2)
//		{
//			cur = cur->next;
//			while (cur != head_2)
//			{
//				//int c1 = hexadecimalToDecimal(cur->hash);
//				//int c2 = hexadecimalToDecimal(hash);
//				if (cur->hash >= hash)
//					//if(c1>=c2)
//				{
//					return cur;
//				}
//				cur = cur->next;
//			}
//		}
//		if (cur->hash > hash || cur->hash < hash)
//		{
//			return head;
//		}
//	}
//
//	//adds two hexadecimal string 
//	std::string addHexStrings(const std::string& hex1, const std::string& hex2)
//	{
//		// Make sure the strings have the same length by padding with zeros if necessary
//		int length = max(hex1.length(), hex2.length());
//		std::string paddedHex1 = std::string(length - hex1.length(), '0') + hex1;
//		std::string paddedHex2 = std::string(length - hex2.length(), '0') + hex2;
//
//		std::string result = "";
//		int carry = 0;
//
//		// Hexadecimal addition without converting to integers
//		for (int i = length - 1; i >= 0; --i)
//		{
//			char digit1 = paddedHex1[i];
//			char digit2 = paddedHex2[i];
//			int d1 = hex_to_dec(digit1);
//			int d2 = hex_to_dec(digit2);
//			int currentSum = d1 + d2 + carry;
//
//			// Determine the new carry and the current digit in hexadecimal
//			carry = currentSum / 16;
//			char currentDigit = "0123456789ABCDEF"[currentSum % 16];
//
//			// Append the current digit to the result
//			result = currentDigit + result;
//		}
//		// If there's a final carry, prepend it to the result
//		if (carry > 0)
//		{
//			result = "1" + result;
//		}
//
//		return result;
//	}
//	//helper
//	int hex_to_dec(char ch)
//	{
//		if (ch == '0')
//			return 0;
//		else if (ch == '1')
//			return 1;
//		else if (ch == '2')
//			return 2;
//		else if (ch == '3')
//			return 3;
//		else if (ch == '4')
//			return 4;
//		else if (ch == '5')
//			return 5;
//		else if (ch == '6')
//			return 6;
//		else if (ch == '7')
//			return 7;
//		else if (ch == '8')
//			return 8;
//		else if (ch == '9')
//			return 9;
//		else if (ch == 'A')
//			return 10;
//		else if (ch == 'B')
//			return 11;
//		else if (ch == 'C')
//			return 12;
//		else if (ch == 'D')
//			return 13;
//		else if (ch == 'E')
//			return 14;
//		else if (ch == 'F')
//			return 15;
//	}
//
//	string hashIT(int n, string hash)	//bits
//	{
//		int a = hash.length();
//		a--;
//		string b;
//		string newHash;
//		//0 - 8 bts then last 2 chars
//		//0-16 bits then last 4 chars
//		//0-24 bits then last 6
//		//0-32 birs then last 8
//		int char_no = 0;
//
//		if (n >= 0 && n < 4)
//		{
//			char_no = 1;
//		}
//		else if (n < 8)
//		{
//			char_no = 2;
//		}
//		else if (n < 12)
//		{
//			char_no = 3;
//		}
//		else if (n < 16)
//		{
//			char_no = 4;
//		}
//		else if (n < 20)
//		{
//			char_no = 5;
//		}
//		else if (n < 24)
//		{
//			char_no = 6;
//		}
//		else if (n < 28)
//		{
//			char_no = 7;
//		}
//		else if (n < 32)
//		{
//			char_no = 8;
//		}
//		else if (n < 36)
//		{
//			char_no = 9;
//		}
//		else if (n < 40)
//		{
//			char_no = 10;
//		}
//		else if (n < 44)
//		{
//			char_no = 11;
//		}
//		else if (n < 48)
//		{
//			char_no = 12;
//		}
//		else if (n < 52)
//		{
//			char_no = 13;
//		}
//		else if (n < 56)
//		{
//			char_no = 14;
//		}
//		else if (n < 60)
//		{
//			char_no = 15;
//		}
//		else if (n < 64)
//		{
//			char_no = 16;
//		}
//		else if (n < 68)
//		{
//			char_no = 17;
//		}
//		else if (n < 72)
//		{
//			char_no = 18;
//		}
//		else if (n < 76)
//		{
//			char_no = 19;
//		}
//		else if (n < 80)
//		{
//			char_no = 20;
//		}
//		else if (n < 84)
//		{
//			char_no = 21;
//		}
//		else if (n < 88)
//		{
//			char_no = 22;
//		}
//		else if (n < 92)
//		{
//			char_no = 23;
//		}
//		else if (n < 96)
//		{
//			char_no = 24;
//		}
//		else if (n < 100)
//		{
//			char_no = 25;
//		}
//		else if (n < 104)
//		{
//			char_no = 26;
//		}
//		else if (n < 108)
//		{
//			char_no = 27;
//		}
//		else if (n < 112)
//		{
//			char_no = 28;
//		}
//		else if (n < 116)
//		{
//			char_no = 29;
//		}
//		else if (n < 120)
//		{
//			char_no = 30;
//		}
//		else if (n < 124)
//		{
//			char_no = 31;
//		}
//		else if (n < 128)
//		{
//			char_no = 32;
//		}
//		else if (n < 132)
//		{
//			char_no = 33;
//		}
//		else if (n < 136)
//		{
//			char_no = 34;
//		}
//		else if (n < 140)
//		{
//			char_no = 35;
//		}
//		else if (n < 144)
//		{
//			char_no = 36;
//		}
//		else if (n < 148)
//		{
//			char_no = 37;
//		}
//		else if (n < 152)
//		{
//			char_no = 38;
//		}
//		else if (n < 156)
//		{
//			char_no = 39;
//		}
//		else if (n < 160)
//		{
//			char_no = 40;
//		}
//
//		while (char_no > 0)
//		{
//			if (a < 0 && char_no != 0)
//			{
//				b = '0' + b;
//				char_no--;;
//				continue;
//			}
//			b = hash[a] + b;
//			a--;
//			char_no--;;
//		}
//		hash = b;
//		//cout << hash << endl;
//		string hexa_to_binary = hexaToBinary(hash, char_no);
//		BitExtraction(hexa_to_binary, n, newHash);
//		//cout << newHash << endl;
//		newHash = binaryToHex(newHash);
//		hash = newHash;
//		return newHash;
//	}
//
//	void BitExtraction(string binary, int Bits, string& newHash) {
//
//		//cout<<binary<<endl;
//		string Ans = "";
//
//		int Size = binary.length();
//		//cout<<Size<<endl;
//		int tempSize = binary.length() - Bits;
//		//cout <<"\nZeros to add " << tempSize << endl; 
//
//		char* Array = new char[binary.length() + 1] {'0'};
//		for (int i = 0; i < binary.length(); i++)
//		{
//			Array[i] = '0';
//		}
//		int idx = tempSize;
//		for (int i = idx; i < binary.length(); i++)
//		{
//			Array[i] = binary[i];
//		}// cout << endl; 
//		Ans = Array;
//		newHash = Ans;
//		//	cout <<  "OG:  " << binary << endl;
//		//	cout  << "New: " << Ans << endl;
//
//	}
//
//	string hexaToBinary(const string& hash, int char_no) {
//		int count = hash.length();
//		int i = 0;
//		string ans;
//		while (i < count)
//		{
//			switch (hash[i])
//			{
//			case '0':
//				ans += "0000";
//				i++;
//				break;
//			case '1':
//				ans += "0001";
//				i++;
//				break;
//			case '2':
//				ans += "0010";
//				i++;
//				break;
//			case '3':
//				ans += "0011";
//				i++;
//				break;
//			case '4':
//				ans += "0100";
//				i++;
//				break;
//			case '5':
//				ans += "0101";
//				i++;
//				break;
//			case '6':
//				ans += "0110";
//				i++;
//				break;
//			case '7':
//				ans += "0111";
//				i++;
//				break;
//			case '8':
//				ans += "1000";
//				i++;
//				break;
//			case '9':
//				ans += "1001";
//				i++;
//				break;
//			case 'A':
//			case 'a':
//				ans += "1010";
//				i++;
//				break;
//			case 'B':
//			case 'b':
//				ans += "1011";
//				i++;
//				break;
//			case 'C':
//			case 'c':
//				ans += "1100";
//				i++;
//				break;
//			case 'D':
//			case 'd':
//				ans += "1101";
//				i++;
//				break;
//			case 'E':
//			case 'e':
//				ans += "1110";
//				i++;
//				break;
//			case 'F':
//			case 'f':
//				ans += "1111";
//				i++;
//				break;
//			default:
//				cout << "Invalid" << endl;;
//			}
//		}
//		//	cout << ans << endl;
//		return ans;
//	}
//
//	string binaryToHex(const string& binaryString) {
//		string finalans;
//
//		int len = binaryString.length();
//
//		string extract;
//		for (int i = len - 1; i >= 0; i = i - 4)
//		{
//			for (int j = i, count = 0; count < 4 && j >= 0; j--, count++)
//			{
//				extract = binaryString[j] + extract;
//			}
//
//			if (extract == "0000")
//				finalans = "0" + finalans;
//			else if (extract == "0001")
//				finalans = "1" + finalans;
//			else if (extract == "0010")
//				finalans = "2" + finalans;
//			else if (extract == "0011")
//				finalans = "3" + finalans;
//			else if (extract == "0100")
//				finalans = "4" + finalans;
//			else if (extract == "0101")
//				finalans = "5" + finalans;
//			else if (extract == "0110")
//				finalans = "6" + finalans;
//			else if (extract == "0111")
//				finalans = "7" + finalans;
//			else if (extract == "1000")
//				finalans = "8" + finalans;
//			else if (extract == "1001")
//				finalans = "9" + finalans;
//			else if (extract == "1010")
//				finalans = "A" + finalans;
//			else if (extract == "1011")
//				finalans = "B" + finalans;
//			else if (extract == "1100")
//				finalans = "C" + finalans;
//			else if (extract == "1101")
//				finalans = "D" + finalans;
//			else if (extract == "1110")
//				finalans = "E" + finalans;
//			else if (extract == "1111")
//				finalans = "F" + finalans;
//			else
//				cout << "Invalid" << endl;
//
//			extract = "";
//		}
//		//	cout << finalans << endl;
//		return finalans;
//	}
//
//	void printRT()
//	{
//		if (head_table != nullptr)
//		{
//			Node* cur = head_table;
//			for (int i = 0; i < cur_bit; i++)
//			{
//				cout << cur->mac->hash << endl;
//				cur = cur->next;
//			}
//		}
//	}
//};





class RT
{
public:
	Node* head_table;
	int bit;
	int cur_bit;
	RT()
	{
		head_table = nullptr;
		bit = 0;
		cur_bit = 0;
	}
	RT(int bit_con)
	{
		bit = log2(bit_con);
		cur_bit = 0;
		head_table = nullptr;
	}
	void updateFingerTable(Machine* node, Machine* head, Machine* tail)
	{
		Machine* cur = node;
		int i = 1;
		Node* p = nullptr;
		while (cur_bit < bit)
		{
			cur_bit++;
			unsigned long long int add_value = pow(2, i - 1);
			//string add_val_str = to_string(add_value);
			string add_val_str = decToHexa(add_value);
			string hash_converted = addHexStrings(cur->hash, add_val_str);	//adding hash+power formula
			//do if hain
			//length cmp
			//tail cmmp
			///mod
			if (hash_converted.length() > cur->hash.length())
			{
				hash_converted = mod(hash_converted, bit);
			}
			else if (hash_converted.length() == cur->hash.length() && hash_converted > tail->hash && head->next!=head)
			{
				hash_converted = mod(hash_converted, bit);
			}

			//now find node with this value 
			Machine* find_node = findwithhash(hash_converted, cur, head);
			Node* c = head_table;
			Node* n_node = new Node(find_node);
			if (c != nullptr)
			{
				while (c->next != nullptr)
				{
					p = c;
					c = c->next;	//dnode
				}
				c->prev = p;
				c->next = n_node;
			}
			else if (head_table == nullptr)
			{
				//head_ta->prev = nullptr;
				head_table = n_node;
			}
			i++;



		}
	}
	Machine* findwithhash(string hash, Machine* head_2, Machine* head)//head_2 is currently the current pointer
	{

		Machine* cur = head_2;
		int bit_no = head->hash.length();	//this identifies the number of bits used in identifier space
		bit_no--;
		bit_no *= 4;
		this->hashIT(bit_no, hash);
		//	hash = hashIT(bit_no, hash);

		if (cur->next == head)//sirf ek val
			return head;

		if (cur->next != head_2)
		{
			cur = cur->next;
			while (cur != head_2)
			{
				//int c1 = hexadecimalToDecimal(cur->hash);
				//int c2 = hexadecimalToDecimal(hash);
				if (cur->hash >= hash)
					//if(c1>=c2)
				{
					return cur;
				}
				cur = cur->next;
			}
		}
		if (cur->hash > hash || cur->hash < hash)
		{
			return head;
		}
	}

	//adds two hexadecimal string 
	std::string addHexStrings(const std::string& hex1, const std::string& hex2)
	{
		// Make sure the strings have the same length by padding with zeros if necessary
		int length = max(hex1.length(), hex2.length());
		std::string paddedHex1 = std::string(length - hex1.length(), '0') + hex1;
		std::string paddedHex2 = std::string(length - hex2.length(), '0') + hex2;

		std::string result = "";
		int carry = 0;

		// Hexadecimal addition without converting to integers
		for (int i = length - 1; i >= 0; --i)
		{
			char digit1 = paddedHex1[i];
			char digit2 = paddedHex2[i];
			int d1 = hex_to_dec(digit1);
			int d2 = hex_to_dec(digit2);
			int currentSum = d1 + d2 + carry;

			// Determine the new carry and the current digit in hexadecimal
			carry = currentSum / 16;
			char currentDigit = "0123456789ABCDEF"[currentSum % 16];

			// Append the current digit to the result
			result = currentDigit + result;
		}
		// If there's a final carry, prepend it to the result
		if (carry > 0)
		{
			result = "1" + result;
		}

		return result;
	}
	//helper
	int hex_to_dec(char ch)
	{
		if (ch == '0')
			return 0;
		else if (ch == '1')
			return 1;
		else if (ch == '2')
			return 2;
		else if (ch == '3')
			return 3;
		else if (ch == '4')
			return 4;
		else if (ch == '5')
			return 5;
		else if (ch == '6')
			return 6;
		else if (ch == '7')
			return 7;
		else if (ch == '8')
			return 8;
		else if (ch == '9')
			return 9;
		else if (ch == 'A')
			return 10;
		else if (ch == 'B')
			return 11;
		else if (ch == 'C')
			return 12;
		else if (ch == 'D')
			return 13;
		else if (ch == 'E')
			return 14;
		else if (ch == 'F')
			return 15;
	}

	string hashIT(int n, string hash)	//bits
	{
		int a = hash.length();
		a--;
		string b;
		string newHash;
		//0 - 8 bts then last 2 chars
		//0-16 bits then last 4 chars
		//0-24 bits then last 6
		//0-32 birs then last 8
		int char_no = 0;

		if (n > 0 && n <= 4)
		{
			char_no = 1;
		}
		else if (n <= 8)
		{
			char_no = 2;
		}
		else if (n <= 12)
		{
			char_no = 3;
		}
		else if (n <= 16)
		{
			char_no = 4;
		}
		else if (n <= 20)
		{
			char_no = 5;
		}
		else if (n <= 24)
		{
			char_no = 6;
		}
		else if (n <= 28)
		{
			char_no = 7;
		}
		else if (n <= 32)
		{
			char_no = 8;
		}
		else if (n <= 36)
		{
			char_no = 9;
		}
		else if (n <= 40)
		{
			char_no = 10;
		}
		else if (n <= 44)
		{
			char_no = 11;
		}
		else if (n <= 48)
		{
			char_no = 12;
		}
		else if (n <= 52)
		{
			char_no = 13;
		}
		else if (n <= 56)
		{
			char_no = 14;
		}
		else if (n <= 60)
		{
			char_no = 15;
		}
		else if (n <= 64)
		{
			char_no = 16;
		}
		else if (n <= 68)
		{
			char_no = 17;
		}
		else if (n <= 72)
		{
			char_no = 18;
		}
		else if (n <= 76)
		{
			char_no = 19;
		}
		else if (n <= 80)
		{
			char_no = 20;
		}
		else if (n <= 84)
		{
			char_no = 21;
		}
		else if (n <= 88)
		{
			char_no = 22;
		}
		else if (n <= 92)
		{
			char_no = 23;
		}
		else if (n <= 96)
		{
			char_no = 24;
		}
		else if (n <= 100)
		{
			char_no = 25;
		}
		else if (n <= 104)
		{
			char_no = 26;
		}
		else if (n <= 108)
		{
			char_no = 27;
		}
		else if (n <= 112)
		{
			char_no = 28;
		}
		else if (n <= 116)
		{
			char_no = 29;
		}
		else if (n <= 120)
		{
			char_no = 30;
		}
		else if (n <= 124)
		{
			char_no = 31;
		}
		else if (n <= 128)
		{
			char_no = 32;
		}
		else if (n <= 132)
		{
			char_no = 33;
		}
		else if (n <= 136)
		{
			char_no = 34;
		}
		else if (n <= 140)
		{
			char_no = 35;
		}
		else if (n <= 144)
		{
			char_no = 36;
		}
		else if (n <= 148)
		{
			char_no = 37;
		}
		else if (n <= 152)
		{
			char_no = 38;
		}
		else if (n <= 156)
		{
			char_no = 39;
		}
		else if (n <= 160)
		{
			char_no = 40;
		}

		while (char_no > 0)
		{
			if (a < 0 && char_no != 0)
			{
				b = '0' + b;
				char_no--;;
				continue;
			}
			b = hash[a] + b;
			a--;
			char_no--;;
		}
		hash = b;
		//cout << hash << endl;
		string hexa_to_binary = hexaToBinary(hash, char_no);
		BitExtraction(hexa_to_binary, n, newHash);
		//cout << newHash << endl;
		newHash = binaryToHex(newHash);
		hash = newHash;
		return newHash;
	}

	void BitExtraction(string binary, int Bits, string& newHash) {

		//cout<<binary<<endl;
		string Ans = "";

		int Size = binary.length();
		//cout<<Size<<endl;
		int tempSize = binary.length() - Bits;
		//cout <<"\nZeros to add " << tempSize << endl; 

		char* Array = new char[binary.length() + 1] {'0'};
		for (int i = 0; i < binary.length(); i++)
		{
			Array[i] = '0';
		}
		int idx = tempSize;
		for (int i = idx; i < binary.length(); i++)
		{
			Array[i] = binary[i];
		}// cout << endl; 
		Ans = Array;
		newHash = Ans;
		//	cout <<  "OG:  " << binary << endl;
		//	cout  << "New: " << Ans << endl;

	}

	string hexaToBinary(const string& hash, int char_no) {
		int count = hash.length();
		int i = 0;
		string ans;
		while (i < count)
		{
			switch (hash[i])
			{
			case '0':
				ans += "0000";
				i++;
				break;
			case '1':
				ans += "0001";
				i++;
				break;
			case '2':
				ans += "0010";
				i++;
				break;
			case '3':
				ans += "0011";
				i++;
				break;
			case '4':
				ans += "0100";
				i++;
				break;
			case '5':
				ans += "0101";
				i++;
				break;
			case '6':
				ans += "0110";
				i++;
				break;
			case '7':
				ans += "0111";
				i++;
				break;
			case '8':
				ans += "1000";
				i++;
				break;
			case '9':
				ans += "1001";
				i++;
				break;
			case 'A':
			case 'a':
				ans += "1010";
				i++;
				break;
			case 'B':
			case 'b':
				ans += "1011";
				i++;
				break;
			case 'C':
			case 'c':
				ans += "1100";
				i++;
				break;
			case 'D':
			case 'd':
				ans += "1101";
				i++;
				break;
			case 'E':
			case 'e':
				ans += "1110";
				i++;
				break;
			case 'F':
			case 'f':
				ans += "1111";
				i++;
				break;
			default:
				cout << "Invalid" << endl;;
			}
		}
		//	cout << ans << endl;
		return ans;
	}

	string binaryToHex(const string& binaryString) {
		string finalans;

		int len = binaryString.length();

		string extract;
		for (int i = len - 1; i >= 0; i = i - 4)
		{
			for (int j = i, count = 0; count < 4 && j >= 0; j--, count++)
			{
				extract = binaryString[j] + extract;
			}

			//cout << "Extracted " << extract << endl; 

			if (extract == "0000")
				finalans = "0" + finalans;
			else if (extract == "0001")
				finalans = "1" + finalans;
			else if (extract == "0010")
				finalans = "2" + finalans;
			else if (extract == "0011")
				finalans = "3" + finalans;
			else if (extract == "0100")
				finalans = "4" + finalans;
			else if (extract == "0101")
				finalans = "5" + finalans;
			else if (extract == "0110")
				finalans = "6" + finalans;
			else if (extract == "0111")
				finalans = "7" + finalans;
			else if (extract == "1000")
				finalans = "8" + finalans;
			else if (extract == "1001")
				finalans = "9" + finalans;
			else if (extract == "1010")
				finalans = "A" + finalans;
			else if (extract == "1011")
				finalans = "B" + finalans;
			else if (extract == "1100")
				finalans = "C" + finalans;
			else if (extract == "1101")
				finalans = "D" + finalans;
			else if (extract == "1110")
				finalans = "E" + finalans;
			else if (extract == "1111")
				finalans = "F" + finalans;
			else
				cout << "Invalid" << endl;

			extract = "";
		}
		//	cout << finalans << endl;
		return finalans;
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
	unsigned long long int hexadecimalToDecimal(string hash)	//works for bits which is very good hehheheh
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
	void printRT()
	{
		if (head_table != nullptr)
		{
			Node* cur = head_table;
			for (int i = 0; i < cur_bit; i++)
			{
				cout << cur->mac->hash << endl;
				cur = cur->next;
			}
		}
	}

	string mod(string hash, int bits)
	{
		int bit_2 = exp2(bits);
		unsigned long  long int add_val = pow(2, bit_2)-1;
		string sub_val_str = decToHexa(add_val);
		sub_val_str = hashIT(bit_2, sub_val_str);
		while (hash >= sub_val_str)
		{
			string a = subHexStrings(hash, sub_val_str);
			hash = a;
		}
		return hash;

	}

	std::string subHexStrings(const std::string& hex1, const std::string& hex2)
	{
		// Make sure the strings have the same length by padding with zeros if necessary
		size_t length = max(hex1.length(), hex2.length());
		std::string paddedHex1 = std::string(length - hex1.length(), '0') + hex1;
		std::string paddedHex2 = std::string(length - hex2.length(), '0') + hex2;

		std::string result = "";
		int carry = 0;

		// Hexadecimal addition without converting to integers
		for (int i = length - 1; i >= 0; --i)
		{
			char digit1 = paddedHex1[i];
			char digit2 = paddedHex2[i];
			int d1 = hex_to_dec(digit1);
			int d2 = hex_to_dec(digit2);
			int currentdigit = d1 - d2 - carry;

			if (currentdigit < 0)
			{
				currentdigit += 16;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			char ch = dec_to_hex(currentdigit);
			result = ch + result;
		}


		return result;
	}
	char dec_to_hex(int ch)
	{
		if (ch == 0)
			return '0';
		else if (ch == 1)
			return '1';
		else if (ch == 2)
			return '2';
		else if (ch == 3)
			return '3';
		else if (ch == 4)
			return '4';
		else if (ch == 5)
			return '5';
		else if (ch == 6)
			return '6';
		else if (ch == 7)
			return '7';
		else if (ch == 8)
			return '8';
		else if (ch == 9)
			return '9';
		else if (ch == 10)
			return 'A';
		else if (ch == 11)
			return 'B';
		else if (ch == 12)
			return 'C';
		else if (ch == 13)
			return 'D';
		else if (ch == 14)
			return 'E';
		else if (ch == 15)
			return 'F';

	}




};
