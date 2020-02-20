//Hammad Qureshi
//CPSC 323
//Assignment 1

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

/*enum FSMTransitions { //Enumeration for Finite State Machine States
	Ignore = 0,
	Integer,
	Operator,
	String,
	Space
};*/

enum FSMTransitions {
	Ignore = 0,
	Integer,
	Real,
	Identifier,
	Space
};


//Finite State Machine Table
/*integer, real, operator,  string, unknown, space */
/*int stateTable[][5] = { {0, Integer,  Operator,  String,  Space},
				    {Integer,  Integer,  Ignore, Ignore, Ignore},     //State 1
				    {Operator, Ignore, Ignore, Ignore, Ignore},       //State 2
				    {String,  String, Ignore, Ignore, Ignore},        //State 3
				    {Space,  Ignore, Ignore, String, Ignore}};        //State 4*/

int stateTable[][5] = { {0 , Integer, Real, Identifier, Space},
				  {Integer, Integer, Real, Ignore, Ignore},
				  {Real, Integer, Ignore, Ignore, Ignore}, 
				  {Identifier, Identifier, Ignore, Ignore},
				  {Space, Ignore, Ignore, Ignore}};

string keywords[] = { "int", "float", "bool", "true", "false", "if", "else", "then", "endif", "while", 
				  "whileend", "do", "doend", "for", "forend", "input", "output", "and", "or" , "not" };

struct lexeme
{
	string lex; //String or char? Should be a string according to professor since we are taking in words from the text document
	int lexNumber; //lexeme
	string token;
};

class lexer {
private:
	lexeme *lexArr = new lexeme[1000000]; //Create a type lexeme array to store data from the text file 
	int countWord; //Acts as the index for the lexArr array

public:

	//This function determines the state of the character being read
	int getCharState(char currentC) {
		//whitespace
		if (isspace(currentC)) { return Space; }

		//Checks for integers
		else if (isdigit(currentC)) { return Integer; }

		//Checks for real numbers
		else if (currentC == '.') { return Real; }

		//Otherwise it is an identifier
		else { return Identifier; }
	}

	string lexName(int lexeme) { //String function that uses a switch statement to return what a certain token is
		switch (lexeme) {
		case Integer:
			return "Integer";
			break;
		case Real:
			return "Real";
			break;
		case Identifier:
			return "Identifier";
			break;
		case Space:
			return "Space";
			break;
		default:
			return "Error";
			break;
		}
	}

	string keyWordSearch(string word) { //Compares text from the text file to see if there any keywords
		string keyWordID = "		Keyword\n";
		string identifierID = "		Identifier\n";
		string Unknown = "		Unknown\n";

		for (int i = 0; i < sizeof(keywords); ++i) {
			if (word.compare(keywords[i]) == 1) {
				return keyWordID;
			}
			else /*if(word.compare(keywords[i]) == 0)*/{
				return identifierID;
			}
		}
		return Unknown;
	}

	lexer() {}; //Default Contructor

	lexer(string filename, string outputFile) {
		//Variable
		 char currentChar = ' ';
		 int col = Ignore;
		 int currentState = Ignore;
		 int prevState = Ignore;
		 string currentWord;

		 //File objects
		 fstream file(filename, ios::in); //This will read in the file
		 ofstream fileWriter; //Created so we can write the output to a separate file

		 fileWriter.open(outputFile); //This will create a new file to write the output to
		 fileWriter << "Token:          Lexeme:\n";

		 if (!file.is_open()) {
			 cout << "Cannot open file";
		 }
		 else {
			 while (!file.eof()) {
				 countWord++;
				 file >> lexArr[countWord].lex; /*Stores each word and character as a string from the file
			 							  into the struct lexeme under the variable*/
				 cout << "\n";
				 currentWord = lexArr[countWord].lex;//Gets the word from the struct array and sets it to a string

				 fileWriter << currentWord;
				 fileWriter << keyWordSearch(currentWord);
			 }
		 }
		 fileWriter.close();
		 file.close();
	}
};