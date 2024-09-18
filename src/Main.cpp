/*
* Josh Patterson 04/16/2023
*
* A program that reads a txt files, and determines the frequency of words in that file.
* A new .dat file is created containing the data gathered from reading the text file.
* Users can select between 3 options to analyze the data.
* Note: Requires c++17 Standard at minimum
*/


#include <iostream>
#include <string>
#include "UserInterface.h"

using namespace std;

int main() {


    UserInterface userInterface;
    userInterface.RunInterface();

    return 0;
}
