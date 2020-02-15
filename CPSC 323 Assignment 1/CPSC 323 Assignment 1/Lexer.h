//Hammad Qureshi
//CPSC 323
//Assignment 1

#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct lexeme
{
	char* lex; //String or char?
};

class LexAnalysis {
private:
	char keywords[32][10] = { "auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while" };

	lexeme *lexArr = new lexeme[1000000]; //Create a type lexeme array to store data from the text file 

public:
	//Create helper functions to go inside lexer (one strategy that can be used)

	

	 void lexer(string filename) { //This will read in the file 
		 fstream file(filename, ios::in);
		 if (!file.is_open()) {
			 cout << "Cannot open file";
		 }
		 else {
			 while (!file.eof()) {

			 }
		 }
	}
};