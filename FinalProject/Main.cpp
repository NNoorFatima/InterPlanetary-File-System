#include "Machine.h"
#include "RindDHT.h" 
#include "SHA-1.h"
#include <cmath>
#include "FileTree.h"
#include <iostream>

using namespace std; 



int main()
{


	/*SHA1 h;
	int log = log2(7);
	cout<<h.sha1("noot");
	string hash = "4F0F645DC7C990BDB6B2069096AA14634465F972";
	int a = hash.length();
	a--;
	string b;
	*/

	
	int bit = 0;
	char ch;
	int machine_no;
	string m_name;

	cout << "Enter the order of the BTree: \n";
	int m = 0;
	cin >> m;

	cout << "Enter the identifier bit space: ";
	cin >> bit;
	cout << endl;
	cout << "Enter the number of machine in your space: ";
	cin >> machine_no;
	cout << endl;

	RingDHT space (bit , m ) ;

	//taking input of number of machines in out system 
	if (machine_no <= pow(2, bit))
	{
		for (int i = 0; i < machine_no; i++)
		{
			cout << "Do you want to manually(m/M) [by giving a name] add machine or automatically [entering the hashes] (a/A): ";
			cin >> ch;
			if (ch != 'm' && ch != 'M' && ch != 'A' && ch != 'a')
				while (ch != 'm' && ch != 'M' && ch != 'A' && ch != 'a')
				{
					cout << "Do you want to manually(m/M) [by giving a name] add machine or automatically [entering the hashes] (a/A): ";
					cin >> ch;
				}

			cout << endl;
			if (ch == 'm' || ch == 'M')		//adding manually 
			{
				cout << "Enter the name of the machine: ";
				cin >> m_name;
				cout << endl;
				space.addMachine(m_name, bit);	//number of bits space + name of machine
			}
			else if (ch == 'a' || ch == 'A')	//adding automatically
			{
				space.addMachine(bit);	//only number of bits space is given
			}
		}
	}
	int c = 0 ; 

	space.print_machines(); 


	string OldPath; 
	while (c < machine_no) {

		cout << "Enter the Path of the File you want to add. \n";
	
		cin >> OldPath;
		space.AddFile(OldPath);
		c++; 
	}

	//printing all of the machines in the system
	//space.print_machines();

	/*
	space.AddFile(OldPath);

	cout << "Enter the Path of the File you want to add. \n";
	///cin >> OldPath;

	space.AddFile(OldPath);

	cout << "Enter the Path of the File you want to add. \n";
	cin >> OldPath;
	space.AddFile(OldPath);
	*/


	// B-tree of machines.  
	c = 0; 

	/*while (c < 1  ) {
		space.PrintBtree_of_a_machine();
		c++; 
	}*/

	/*cout << "Enter the hash of the file you want to search.\n"; 
	string Hash_of_File; cin >> Hash_of_File; 
	space.Search_a_hash(Hash_of_File) ; */

	/*string MachineToDelete; 
	

	for (int i = 0; i < machine_no; i++)
	{
		cout << "Enter the hash of machine to be deleted: ";
		cin >> MachineToDelete;
		space.delete_a_machine(MachineToDelete);
		space.print_machines();
	}*/

	/*string FileDelete;
	cout << "Enter the hash of File to be deleted: ";
	cin >> FileDelete;
*/

	space.PrintBtree_of_a_machine(); 

	//space.Delete_a_file(FileDelete); 
	space.addMachine(bit);
	space.addMachine(bit);
	space.print_machines();
	space.print_machine_RT();

	space.PrintBtree_of_a_machine();

}
