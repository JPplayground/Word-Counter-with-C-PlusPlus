#include "UserInterface.h"
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

UserInterface::UserInterface() {
    vector<string> wordList;    // vector to read file and store as strings
    string tmpString;           // tmp string, multiple uses

    ifstream inFS;              // input from file object
    ofstream outFS;             // output to file object

    inFS.open(fileName);                // open file (fileName defined in member variables, change if needed)
    while (!inFS.eof()) {               // loops until end of file
        getline(inFS, tmpString);       // captures string, stores in tmpString
        wordList.push_back(tmpString);  // insert into vector
    }
    inFS.close();                       // close the file

    for (int i = 0; i < wordList.size(); ++i) {                             // <- MAP CREATION
        tmpString = wordList.at(i);                                         // stores word in tmp variable
        if (wordFrequencies.find(tmpString) == wordFrequencies.end()) {     // true = key does not exist yet
            wordFrequencies.emplace(tmpString, 1);                              // create key with value of 1
        }
        else {                                                            // false = key was found
            wordFrequencies.at(tmpString) += 1;                             // increment value at key by 1
        }
    }

    outFS.open("frequency.dat");                      // <- FILE CREATION
    for (auto const& [key, value] : wordFrequencies) {                      // iterate through map
        outFS << key << " " << value << endl;                               // write {key, value}
    }
    outFS.close();                                                          // close file

}

void UserInterface::PrintMenu() {
    // menu options
    cout << "1: Enter a word and determine it's frequency." << endl;
    cout << "2: Display a list with numbers that represent the frequency of all items purchased." << endl;
    cout << "3: Display a histogram of words and associated frequency." << endl;
    cout << "4: Exit the program." << endl << endl;
}

unsigned int UserInterface::RunMenuOptionOne(string item) {
    // This function accepts a string parameter, determines it's frequency and outputs that frequency

    unsigned int frequency = 0;     // store frequency of input word

    if (wordFrequencies.find(item) == wordFrequencies.end()) {  // key does not exist
        cout << "No occurrences found!" << endl;
    }
    else {                                                    // key exists
        frequency = wordFrequencies.at(item);                   // get value
        cout << item << " occurred " << frequency << " times."; // print
    }
    cout << endl << endl;

    return frequency;
}

void UserInterface::RunMenuOptionTwo() {
    // This function prints all words and the number of times they occurred

    for (auto const& [key, value] : wordFrequencies) {               // iterate through (key, value) pairs
        cout << key << " occurred " << value << " times." << endl;  // print
    }
    cout << endl;
}

void UserInterface::RunMenuOptionThree() {
    // This function prints a histogram style chart to represent the frequency of words

    for (auto const& [key, value] : wordFrequencies) {               // iterate through (key, value) pairs
        cout << setw(15) << left << key << " ";                     // print key
        for (int i = 0; i < value; ++i) {                           // loop x times printing '*'
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

unsigned int UserInterface::GetMenuChoiceInput() {
    unsigned int userChoice = -1;   // initialize to -1 to start while loop
    cout << "Please choose a menu option (enter a number)" << endl;
    cin >> userChoice;

    while (!((userChoice > 0) && (userChoice < 5))) {                      // input validation (must be 1 - 4)
        cout << "Please choose a valid option (enter a number)" << endl;
        cin >> userChoice;
    }
    cout << endl;

    return userChoice;
}

string UserInterface::GetWordSearchInput() {
    // function that handles getting input for a string

    string word;
    cout << "Please enter the word you would like to search for:";
    cin >> word;
    cout << endl;
    return word;
}

void UserInterface::RunInterface() {
    // function that represents the actual user interface
    // uses helper functions to execute the user's choice
    // while loop repeats until input is "4"

    unsigned int menuChoice = 0;
    string searchWord;

    while (menuChoice != 4) {
        PrintMenu();
        menuChoice = GetMenuChoiceInput();

        if (menuChoice == 1) {
            searchWord = GetWordSearchInput();
            RunMenuOptionOne(searchWord);
        }
        else if (menuChoice == 2) {
            RunMenuOptionTwo();
        }
        else if (menuChoice == 3) {
            RunMenuOptionThree();
        }
        else if (menuChoice == 4) {
            break;
        }
    }
}
