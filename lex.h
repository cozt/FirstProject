#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<string.h>
using namespace std;
bool separation =false;
bool operation =false;
int curIndex = 0;

bool sep=false;
bool op=false;
bool ident=false;
bool num=false;
ifstream myFile;
ofstream outFile;
char keywords[20][10] = {"int", "float", "bool", "true", "false", "if", "else", "then", "endif","while", "whileend", "do", "doend","for", "forend", "input", "output", "and", "or", "not"};
char separators[] = "'(){}[],:;";
char operators[] = {'*', '+', '-', '=', '/', '>', '<', '%'};
char ch;
char buffer[20];
int x = 0;
bool comments=false;
char detection[2] = {'\0'};
int y = 0;
bool containsKey(char buffer[]){
  int i = 0;
  while(i<20){
    if (strcmp(keywords[i], buffer) == 0){
      return true;
    }
    i++;
  }
return false;
 }
// check if there are seprators in it
bool containsSep(char ch){
  int i =0;
  while(i <10){
    if (ch == separators[i])
  		return true;
    i++;
  }
		return false;
	}
//contains operator
bool containsOp(char ch){
  int i =0;
  while (i< 10){
    if (ch == operators[i])
      return true;
    i++;
  }
	  return false;
	}
// check if it contians if there is an integer
bool containsNum(char buffer[]){
for (int i = 0; i <= (curIndex-1); i++){
	if (!isdigit(buffer[i]))
		return false;
		continue;
	 }
		return true;
}
//out out toa file
void print(){
	if (ident){
		cout << "Identifier 						" << buffer << endl;
		outFile << "Identifier 						" << buffer << endl;
		ident = false;
	}
	if (num){
		cout << "Integer 						" << buffer << endl;
		outFile << "Integer 							" << buffer << endl;
		num = false;
	}
	//printing of separators
	if (sep){
		cout << "Separator 						" << ch << endl;
		outFile << "Separator 						" << ch << endl;
		sep = false;
		separation = false;
	}
	//printing of operators
	if (op){
		cout << "Operator 						" << ch << endl;
		outFile << "Operator 						" << ch << endl;
		op = false;
		operation = false;
	}
}
//check the comments
void check_comment(char a, char b[]){
  if (a == 33){
		b[y] = a; y+=1;
	if (b[1] == a){
		comments = 0; y = 0;
		b[0] ='\0';
		b[1] ='\0';
	}
	else
		comments = 1;
		}
}
void no_comment(char a, bool b){
  if (!b){
	if (containsSep(a)){
		separation = 1; sep = 1;
	}
	if (containsOp(a)){
		operation = 1; op = 1;
	}
	if (isalnum(a) || a=='.' || a=='$'){
		buffer[x++] = a; curIndex+=1;
	}
	else if ((a=='\n' ||a ==' ' ||separation||operation||myFile.eof())&&(x != 0)){
		buffer[x] ='\0'; x = 0;
	if (containsKey(buffer)){
		cout << "Keyword 						" << buffer << endl;
		outFile << "Keywords 		 			" << buffer << endl;
	}
	else if (containsNum(buffer)) num = 1;
	else {
	if (!isdigit(buffer[0]))
		ident = 1;
		}
	curIndex = 0;
		}
		print();
	}
}
void lexical(){
  check_comment(ch,detection);
  no_comment(ch, comments);
}
