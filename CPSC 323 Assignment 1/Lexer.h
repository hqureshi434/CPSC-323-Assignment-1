//Hammad Qureshi
//CPSC 323
//Assignment 1

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

enum FSMTransitions { //Enumeration for Finite State Machine States
	Ignore = 0,
	Integer,
	Operator,
	String,
	Space
};


//Finite State Machine Table
/*integer, real, operator,  string, unknown, space */
int stateTable[][5] = { {0, Integer,  Operator,  String,  Space},
				    {Integer,  Integer,  Ignore, Ignore, Ignore},     //State 1
				    {Operator, Ignore, Ignore, Ignore, Ignore},       //State 2
				    {String,  String, Ignore, Ignore, Ignore},        //State 3
				    {Space,  Ignore, Ignore, String, Ignore}};        //State 4

string keywords[32] = { "auto","break","case","char","const","continue","default",
					 "do","double","else","enum","extern","float","for","goto",
					 "if","int","long","register","return","short","signed",
					 "sizeof","static","struct","switch","typedef","union",
					 "unsigned","void","volatile","while" };

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
	//Create helper functions to go inside lexer (one strategy that can be used)

	string keyWordSearch(string word) { //Compares text from the text file to see if there any keywords
		string keyWordID = "          Keyword\n";
		string identifierID = "          Identifier\n";
		string Unknown = "          Unknown\n";

		for (int i = 0; i < sizeof(keywords); i++) {
			if (word.compare(keywords[i]) == 1) {
				return keyWordID;
			}
			else if(word.compare(keywords[i]) == 0){
				return identifierID;
			}
		}
		return Unknown;
	}

	lexer() {}; //Default Contructor

	lexer(string filename, string outputFile) {
		 string currentWord;
		 fstream file(filename, ios::in); //This will read in the file
		 ofstream fileWriter;

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
				 currentWord = lexArr[countWord].lex;

				 fileWriter << currentWord << "\n";
				 fileWriter << keyWordSearch(currentWord);
			 }
		 }
		 fileWriter.close();
		 file.close();
	}
};