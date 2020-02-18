//Hammad Qureshi
//CPSC 323
//Assignment 1

#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum FSMTransitions {
	Ignore = 0,
	Integer,
	Operator,
	String,
	Space
};

/*enum FSM_TRANSITIONS
{
    REJECT = 0,
    INTEGER,
    REAL,
    OPERATOR,
    STRING,
    UNKNOWN,
    SPACE
};*/

/*int stateTable[][7] = {{0, INTEGER,  REAL,  OPERATOR,  STRING, UNKNOWN,  SPACE},
/* STATE 1  {INTEGER, INTEGER, REAL, REJECT, REJECT, REJECT, REJECT},
/* STATE 2 { REAL,       REAL,  UNKNOWN, REJECT,   REJECT,  REJECT,  REJECT },
/* STATE 3 { OPERATOR,  REJECT, REJECT,  REJECT,   STRING,  REJECT,  REJECT },
/* STATE 4 { STRING,    STRING, REJECT,  STRING,   STRING,  REJECT,  REJECT },
/* STATE 5 { UNKNOWN,  UNKNOWN, UNKNOWN, UNKNOWN,  UNKNOWN, UNKNOWN, REJECT },
/* STATE 6 { SPACE,     REJECT, REJECT,  REJECT,   REJECT,  REJECT,  REJECT }};


//Finite State Machine Table
/*integer, real, operator,  string, unknown, space */
int stateTable[][5] = { {0, Integer,  Operator,  String,  Space},
/* STATE 1 */   {Integer,  Integer,  Ignore, Ignore, Ignore},
/* STATE 2 */   {Operator, Ignore, Ignore, Ignore, Ignore},
/* STATE 3 */   {String,  String, Ignore, Ignore, Ignore},
/* STATE 4 */   {Space,  Ignore, Ignore, String, Ignore}};

char keywords[32][10] = { "auto","break","case","char","const","continue","default",
					 "do","double","else","enum","extern","float","for","goto",
					 "if","int","long","register","return","short","signed",
					 "sizeof","static","struct","switch","typedef","union",
					 "unsigned","void","volatile","while" };

struct lexeme
{
	string lex; //String or char? Should be a string according to professor since we are taking in words from the text document
};

class LexAnalysis {
private:
	lexeme *lexArr = new lexeme[1000000]; //Create a type lexeme array to store data from the text file 
	int countWord; //Acts as the index for the lexArr array

public:
	//Create helper functions to go inside lexer (one strategy that can be used)
	//Implement Enumeration and Switch Statement here


	 void lexer(string filename) {  
		 fstream file(filename, ios::in); //This will read in the file
		 if (!file.is_open()) {
			 cout << "Cannot open file";
		 }
		 else {
			 while (!file.eof()) {
				 countWord++;
				 file >> lexArr[countWord].lex; //Stores each word and character as a string from the file 
			 }							  //into the struct lexeme under the variable
		 }
	}
};