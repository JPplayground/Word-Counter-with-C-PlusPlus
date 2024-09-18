#pragma once

#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class UserInterface {
private:
    // member variables
    map<string, int> wordFrequencies;  // map that is filled during call to constructor
    string fileName = "../data/example.txt";   // filename that is in directory (change if needed)

    // member functions
    void PrintMenu();

    unsigned int RunMenuOptionOne(string item);
    void RunMenuOptionTwo();
    void RunMenuOptionThree();

    // input functions
    unsigned int GetMenuChoiceInput();
    string GetWordSearchInput();

public:
    UserInterface();        // constructor
    void RunInterface();    // program initiate
};


