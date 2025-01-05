// pro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include "SHA-1.h"
#include "Machine.h"
#include "RindDHT.h"
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
	RingDHT space;
	int bit = 0;
	char ch;
	int machine_no;
	string m_name;
	cout << "Enter the identifier bit space: ";
	cin >> bit;
	cout << endl;
	cout << "Enter the number of machine in your space: ";
	cin >> machine_no;
	cout << endl;
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
	//printing all of the machines in the system
	space.print_machines();
}
