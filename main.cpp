/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 3

===Allows for user input and executes GenStack.cpp===

*/

#include <iostream>
#include <fstream>
#include <string>
#include "fileIO.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char** argv)
{
  //checks for correct number of arguments in command line
  if (argc == 1)
  {
    cout << "Please enter the following: file name or file path." << endl;
    return -1;
  }

  if (argc >= 3)
  {
    cout << "Too many arguments have been entered. Please only enter one file name \n[EXAMPLE] --> main.cpp userFile.cpp." << endl;
    return -1;
  }

  DelimiterChecker delim;
  string fileName = argv[1];
  delim.checkDelimiters(fileName);

  return 0;
}
