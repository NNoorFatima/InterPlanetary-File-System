#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


using namespace std;


void createTextFile(const string & str  ) {

	ofstream newFile( str ) ;

	newFile.close() ;

}


string ReadTextFile (const string& str  ) {


	string toReturn = "";
	// Open the file for writing (out keyword ) /  reading ( in key word)
	ifstream tempFile;
	tempFile.open(str, ios:: in  );

    string s; bool flag = false;

    while (!tempFile.eof()) {

        getline(tempFile, s, '\n');
        toReturn += s; 
        

        if (tempFile.eof()) { break; }
        

    }// loop end 


    tempFile.close();

    //cout << toReturn; 

    return toReturn; 

}


// this will delete the previous constent of the file.  
// we can use ios:: app , if we want to add. 
void writeFile( const string & str ) {

    ofstream replace;
    replace.open( str , ios::out );
    string toStore = "";
    cout << "Enter the content u want to write: \n";
    
    getline(std::cin, toStore );

    replace << toStore; 

    replace.close(); 

}

void writeFile(const string& str , const string & content ) {

    ofstream replace;
    replace.open(str, ios::out);
    
    replace << content ;

    replace.close();


}

