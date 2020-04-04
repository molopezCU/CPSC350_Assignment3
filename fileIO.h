/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 3

=== Header for Delimiter classes. The Delimiter classes will be working with the stack
to create a syntax checker for delimiters '(' '[' and '{'. === 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DelimiterChecker
{
  public:
    DelimiterChecker(); //constructor
    ~DelimiterChecker(); //destructor

    int checkDelimiters(string fileName);
};
