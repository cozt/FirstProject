#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<string.h>
#include "lex.h"
int main(int argc , char*argv[]){
	myFile.open(argv[1]);
	outFile.open(argv[2]);
	// throws a error if it can open the file
	if (!myFile.is_open()){
		cout << "Error\n";
		exit(0);
	}
	cout << "Tokens:					Lexemes:" << endl;
	outFile << "Tokens:					Lexemes:" << endl;
//implementation of lexical analyzer
	while (!myFile.eof()){
		ch=myFile.get();
		lexical();
	}
	//closing of Files
	myFile.close();
	outFile.close();
	return 0;
}
