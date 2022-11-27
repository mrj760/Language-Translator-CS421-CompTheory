#ifndef PARSER
#define PARSER

#include<iostream>
#include<fstream>
#include<string>
#include "ScannerFiles/scanner.cpp"

using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

/*

i will copy scanner.cpp and Utility function into this file 

*/

//=================================================
// File parser.cpp written by Group Number: ** 16
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------
string saved_lexeme;
bool avalible_token = false;
string choice;
tokentype saved_token;


enum parser_function {STORY, S, AFTER_SUBJECT, AFTER_NOUN, AFTER_OBEJCT, VERB1, TENSE, NOUN, BE };
string parserName[30] = { "story", "s", "after subject", "after noun", "after obejct", "verb", "tense", "noun", "be" };


// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: error when match fails
// Done by: Ased Adus
void syntaxerror1(tokentype TK){
   cout << endl << "LEXICAL ERROR: unexpected " << saved_lexeme << "is not a valid token" << endl;
}


// Type of error: for switch default
// Done by: Ased Adus
void syntaxerror2(parser_function x){
	cout << endl << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parserName[x] << endl;
	exit(1); 
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme


// next_token(void)
//    Looks ahead to see what token comes next from the scanner.
//    HOW: checks first to see if the token_available flag is false.
//                If so, saved_token gets scanner() result.
//                and the flag is set true.
//    A token is grabbed but is not eaten up.
//    Returns the saved_token


// Purpose: the purpose of this functions is to look adead and see the type of token comes next by calling scanner
// Done by: Ased Adus
tokentype next_token(){
   if (!avalible_token){
      scanner(saved_token, saved_lexeme);
      cout << "scanner called for: " << saved_lexeme << endl;
      avalible_token = true;
   }
   return saved_token;
}

// Purpose: **
// Done by: **
bool match(tokentype expected) {}

// ----- RDP functions - one per non-term -------------------
// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: <s>::= [CONNECTOR] <noun> SUBJECT <after subject>
// Done by: Ased Adus
void s() {
	cout << "Processing <s>" << endl;
	switch (next_token()) {
	case CONNECTOR:
		match(CONNECTOR);
		noun();
		match(SUBJECT);
		after_subject();
		break;
	default:
		noun();
		match(SUBJECT);
		after_subject();
		break;
	}
}

// Grammar: <story> ::= <s> {<s>}
// Done by: Ased Adus
void story(){
   cout << processing <story>\n" << endl;
   s();
   while(true){
      if (next_token() == EOFM) {
			cout << endl << "Successfully parsed <story>." << endl;
			break;
		}
		s();	
	}
}







string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

#endif
