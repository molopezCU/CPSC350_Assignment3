/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 3

=== Program reads line by line user code and checks to make sure delimiters are being used properly through a Stack.
If the program were to encounter a delimiter, it is to be pushed and later compared with a closing delimiter
(represented by userCode[i]). If the two match, the delimiters are popped from the stack and the program continues
onto the next pair of delimiters. If they dont, the programs outputs to console what delimiter was expected and what
was found instead. If the file is proofread to completion and no errors were found, users are asked if there is another file
they would like to be checked through a y/n question. ===
*/

#include <iostream>
#include <fstream>
#include <string>
#include "fileIO.h"
#include "GenStack.h"

using namespace std;

//constructor
DelimiterChecker::DelimiterChecker()
{
}

//destructor
DelimiterChecker::~DelimiterChecker()
{
  cout << "Arrays destroyed." << endl;
}

//code for checking delimiters given an input file
int DelimiterChecker::checkDelimiters(string fileName)
{
  bool checkDelims = true;
  GenStack<char> stack(12);

  while(checkDelims){
    string userCode;
    int lineNum = 1;
    ifstream inputFile;
    inputFile.open(fileName.c_str());

    while (getline(inputFile, userCode))
    {
      for (int i = 0; i < userCode.size(); ++i)
      {
          if ((userCode[i] == '(') || (userCode[i] == '[') || (userCode[i] == '{'))
            stack.push(userCode[i]);
          else if ((stack.peek() == '(') && (userCode[i] == ')') || (stack.peek() == '[') && (userCode[i] == ']') || (stack.peek() == '{') && (userCode[i] == '}'))
            stack.pop();
          else if ((stack.peek() == '(') && (userCode[i] == ']' || (stack.peek() == '(') && userCode[i] == '}' || (stack.peek() == '(') && userCode[i] == ' '))
          {
            cout << "Error at line " << lineNum << ": ')' expected. '" << userCode[i] << "' was found instead." << endl;
            return 0;
          }
          else if ((stack.peek() == '[') && (userCode[i] == ')' || (stack.peek() == '[') && userCode[i] == '}' || (stack.peek() == '[') && userCode[i] == ' '))
          {
            cout << "Error at line " << lineNum << ": ']' expected. '" << userCode[i] << "' was found instead." << endl;
            return 0;
          }
          else if ((stack.peek() == '{') && (userCode[i] == ']' || (stack.peek() == '{') && userCode[i] == ')' || (stack.peek() == '{') && userCode[i] == ' '))
          {
            cout << "Error at line " << lineNum << ": '}' expected. '" << userCode[i] << "' was found instead." << endl;
            return 0;
          }
      }
      ++lineNum;
    }
    if (stack.isEmpty() == false)
    {
      cout << "Reached EOF. Missing '" << stack.peek() << "'." << endl;
      return 0;
    }
    else if (stack.isEmpty() == true)
    {
      char anotherFile;
      cout << "No errors found in this file. " << endl;
      cout << "Would you like to check another file? [y/n]:" << endl;
      cin >> anotherFile;

      char toupper(char anotherFile);
      if (anotherFile == 'Y')
      {
        cout << "Enter the name of the next file that will be checked: " << endl;
        cin >> fileName;
        continue;
      }
      else
      {
        checkDelims = false;
      }
    }
  }
  return 0;
}
