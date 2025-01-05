#pragma once 
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Function to create a folder on runtime.
// Returns true if the folder is successfully created or if it already exists.
// Otherwise, returns false.
bool createDirectory(const std::string& folderName) {
    if (CreateDirectoryA(folderName.c_str(), nullptr) || GetLastError() == ERROR_ALREADY_EXISTS) {
        return true;
    }
    return false;

}


// Function to delete a folder and its contents
bool deleteFolder(const std::string& folderName) {

    // Construct the command to remove the folder using system command  
    string command = "rmdir /s /q \"" + folderName + "\"";
    int result = std::system(command.c_str());
    return result == 0;

}