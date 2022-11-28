#ifndef PARSER
#define PARSER

#include <algorithm>
#include <vector>
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

/* INSTRUCTION:  Complete all ** parts.                                                                               
   You may use any method to connect this file to scanner.cpp                                                         
   that you had written.                                                                                              
  e.g. You can copy scanner.cpp here by:                                                                              
          cp ../ScannerFiles/scanner.cpp .                                                                            
       and then append the two files into one:                                                                        
          cat scanner.cpp parser.cpp > myparser.cpp                                                                   
*/



//i ll copy scanner.cpp and Utility function into this file                                                           
enum State                          // create an enum for every state                                                 
  {
    q0,                             // starting state/ accepting state                                                
    q0q1,                           // final/accepting state                                                          
    q0qy,                           // final/accepting state                                                          
    qy,                             // transition state                                                               
    qs,                             // transition state                                                               
    qc,                             // transition state                                                               
    qt,                             // transition state                                                               
    qsa                             // transition state                          
                                                                                                                      
  };


bool contains(vector<char> v, char c)
{
  return std::find(v.begin(), v.end(), c) != v.end();   // return true if char is found                               
}

// WORD DFA                                                                                                           
// Done by: Ased, Micah                                                                                               
// RE:   **                                                                                                           


bool word(string s)                                       // returns true if string follows the gamer rule            
{
  State state = q0;                                     // starting state                                             
  int charpos = 0;                                      // initial char                                               

  while (s[charpos] != '\0')                              // while loop will end when we get to the end of string     
    {
      char c = s[charpos]; // easier to type              // get char at postition charpos                            
      bool isVowel = contains({'a', 'e', 'i', 'o', 'u', 'I', 'E'}, c);    // this bool variable says true if char c contains any of the vowle listed in the gramer rule                                                                    

      // cout << "State: " << state << ", char: " << c << endl;                                                       

      switch (state)                                      // switch statment to track if a string is following the grammar rule                                                                                                            
        {
        case (q0):                                          // starting state (q0) CASE #1                            
          if (isVowel)                                    // if the char is a vowel go to state q0q1                  
            state = q0q1;
          else if (contains({'b', 'g', 'h', 'k', 'm', 'n', 'p', 'r'}, c)) // if char contains one of those charactersgo to state qy                                                                                                       
            state = qy;
          else if (c == 't')                              // if char is 't' go to state qt                            
            state = qt;
          else if (c == 's')                              // if char is 's' go to state qs                            
            state = qs;
          else if (c == 'c')                              // if char is 'c' go to state qc                            
            state = qc;
          else if (contains({'d', 'w', 'z', 'y', 'j'}, c))// if char contains one of those characters go to state qsa
            state = qsa;
          else                                            // if char is not one of the character listed in the above case, return false.                                                                                                   
            { /* cout << "Fail in q0 with character: " << c << endl; */
              return false;
            }
          break;
        case (q0q1):                                        //  state (q0q1) CASE #2                                  
          if (isVowel)
            state = q0q1;
          else if (contains({'b', 'g', 'h', 'k', 'm', 'p', 'r'}, c))      // if char contains one of those characters go to state qy                                                                                                       
            state = qy;
          else if (c == 'n')                              // if char is 'n' go to state q0qy                          
            state = q0qy;
          else if (c == 't')                              // if char is 't' go to state qt                            
            state = qt;
          else if (c == 's')                              // if char is 's' go to state qs                            
            state = qs;
          else if (c == 'c')                              // if char is 'c' go to state qc                            
            state = qc;
          else if (contains({'d', 'w', 'z', 'y', 'j'}, c)) // if char contains one of those characters go to state qsa                                                                                                                     
            state = qsa;
          else                                            // if char is not one of the character listed in the above case, return false. string does not follow the grammar rules                                                          
            { /* cout << "Fail in q0q1 with character: " << c << endl; */
              return false;
            }
          break;

        case (q0qy):                                        ////  state (q0qy) CASE #3                                
          if (isVowel)                                    // if the char is a vowel go to state q0q1                                                                                                                                       
            state = q0q1;
          else if (contains({'b', 'g', 'h', 'k', 'm', 'n', 'p', 'r'}, c))// if char contains one of those characters go to state qy                                                                                                        
            state = qy;
          else if (c == 't')                                // if char is 't' go to state qt                          
            state = qt;
          else if (c == 's')                               // if char is 's' go to state qs                           
            state = qs;
          else if (c == 'c')                              // if char is 'c' go to state qc                            
            state = qc;
          else if (contains({'d', 'w', 'z', 'y', 'j'}, c))// if char contains one of those characters go to state qsa
        state = qsa;
        else             // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                          
          { /* cout << "Fail in q0qy with character: " << c << endl; */
            return false;
          }
      break;

    case (qy):                                        //  state (q0qy) CASE #4                                        
      if (isVowel)                                  // if the char is a vowel go to state q0q1                        
        state = q0q1;
      else if (c == 'y')                            // if char is 'y' go to state qsa                                 
        state = qsa;
      else             // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                            
        { /* cout << "Fail in qy with character: " << c << endl; */
          return false;
        }
      break;
      if (isVowel)                                  // if the char is a vowel go to state q0q1                        
        state = q0q1;
      else if (c == 'h')                              // if char is 'h' go to state qsa                               
        state = qsa;
      else              // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                           
        { /* cout << "Fail in qs with character: " << c << endl; */
          return false;
        }
      break;

    case (qc):                                      //  state (q0qy) CASE #6                                          
      if (c == 'h')                               // if char is 'h' go to state qsa                                   
        state = qsa;
      else              // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                           
        { /* cout << "Fail in qc with character: " << c << endl; */
          return false;
        }
      break;
		      
		      
    case (qt):                                        //  state (q0qy) CASE #7                                        
      if (isVowel)                                  // if the char is a vowel go to state q0q1                        
        state = q0q1;
      else if (c == 's')                               // if char is 's' go to state qsa                              
        state = qsa;
      else              // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                           
        { /* cout << "Fail in qt with character: " << c << endl; */
          return false;
        }
      break;

    case (qsa):                                        //  state (q0qy) CASE #8                                       
      if (isVowel)                                   // if the char is a vowel go to state q0q1                       
        state = q0q1;
      else              // if char is not one of the character listed in the above cases, return false. string does not follow the grammar rules                                                                                           
        { /* cout << "Fail in qsa with character: " << c << endl; */
          return false;
        }
      break;
    }
  charpos++;                                         // increment the character position                              
} // end of while                                                                                                     

// where did I end up????                              // return true if we end up in one of the accepted state which\
 are q0, q0q1, and q0qy                                                                                               
return state == q0 || state == q0q1 || state == q0qy;
}

enum tokentype         // this enum contains all of the tokentype that will be labeled by the scanner                      
  {
    WORD1,
    WORD2,
    PERIOD,
    ERROR,
    EOFM,
    PRONOUN,
    SUBJECT,
    VERB,
    VERBNEG,
    IS,
    WAS,
    OBJECT,
    DESTINATION,
    VERBPAST,
    VERBPASTNEG,
    CONNECTOR
  };

string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "EOFM", "PRONOUN", "SUBJECT", "VERB", "VERBNEG", "IS",
                        "WAS", "OBJECT", "DESTINATION", "VERBPAST", "VERBPASTNEG","CONNECTOR" };

string reservedwords[20][2] = {             //store the reservedwords in 2D array clo o is the words and col 1 is tokenName
  "masu", "VERB",
  "masen", "VERBNEG",
  "mashita", "VERBPAST",
  "masendeshita", "VERBPASTNEG",
  "desu", "IS",
  "deshita", "WAS",
  "o", "OBJECT",
  "wa", "SUBJECT",
  "ni", "DESTINATION",
  "watashi", "PRONOUN",
  "anata", "PRONOUN",
  "kare", "PRONOUN",
  "kanojo", "PRONOUN",
  "sore", "PRONOUN",
  "mata", "CONNECTOR",
  "soshite", "CONNECTOR",
  "shikashi", "CONNECTOR",
  "dakara", "CONNECTOR",
  "eofm", "EOFM"
};


ifstream fin;  // global stream for reading from the input file   

// this scanner function will read one word at a time and return the tokentype and the string using pass by reference
int scanner(tokentype& TK, string& w)
{

  // ** Grab the next word from the file via fin                                                                                                                
  fin >> w;
  /*                                                                                                                                                            
    2. Call the token functions one after another (if-then-else)                                                                                                
    And generate a lexical error message if both DFAs failed.                                                                                                   
    Let the token_type be ERROR in that case.                                                                                                                   
    3. Make sure WORDs are checked against the reservedwords list                                                                                               
    If not reserved, token_type is WORD1 or WORD2.                                                                                                              
    4. Return the token type & string  (pass by reference)                                                                                                      
  */

  if ( word(w)) {		// if the string is a valid string, find the tokentype
    bool isreserved = false;

    // Check the grabbed string against the reserved words table                                                                                                
    for (int i = 0; i < 20; i++) {
      if (w == reservedwords[i][0]) {// w was found to be reserved, assign the correct token type                                                               
        if (reservedwords[i][1] == "VERB")        //if its VERB
          TK = VERB;
        else if (reservedwords[i][1] == "VERBNEG")  // if its VERBNEG
          TK = VERBNEG;
        else if (reservedwords[i][1] == "VERBPAST")   // if its VERBPAST
          TK = VERBPAST;
        else if (reservedwords[i][1] == "VERBPASTNEG")   // if its VERBPASTNEG
          TK = VERBPASTNEG;
        else if (reservedwords[i][1] == "IS")  
          TK = IS;
        else if (reservedwords[i][1] == "WAS")
          TK = WAS;
        else if (reservedwords[i][1] == "OBJECT")
          TK = OBJECT;
        else if (reservedwords[i][1] == "SUBJECT")
          TK = SUBJECT;
        else if (reservedwords[i][1] == "DESTINATION")
          TK = DESTINATION;
        else if (reservedwords[i][1] == "PRONOUN")
          TK = PRONOUN;
        else if (reservedwords[i][1] == "CONNECTOR")
          TK = CONNECTOR;
        else if (reservedwords[i][1] == "EOFM")
          TK = EOFM;
        isreserved = true;
        break;
      }
    }
    if (!isreserved){                       // if the string is not in the reservedwords, check the ending of the string to see if the tokentype is WORD1 or WORD2
       if (w[w.length() - 1] == 'I' || w[w.length() - 1] == 'E')
          TK = WORD2;
       else
          TK = WORD1;
    }
  }
  else if( period(w) ){                     // if the string is a period
    TK = PERIOD;
  }
  else if (w == "eofm") {                   // if the string is 'eofm
    TK = EOFM;
  }
  else {
    // Generated a lexical error                                                                                                                                
    cout << "Lexical error: " << w << " is not a valid token." << endl;
    TK = ERROR;
  }
  return 0;
}//the end of scanner     


//=================================================                                                                                                             
// File parser.cpp written by Group Number: ** 16                                                                                                               
//=================================================                                                                                                             

// ----- Four Utility Functions and Globals -----------------------------------                                                                                 
string saved_lexeme;
bool avalible_token = false;
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
// Done by: Ased Adus
bool match(tokentype expec){
  if (next_token() != expec){
    syntaxerror1(expec); // call syntax error1 message
  }
  else{
    avalible_token = false;
    cout << "Matched " << tokenName[expec] << endl;
    return true;
  }
}

// ----- RDP functions - one per non-term -------------------
// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: <tense> ::= VERBPAST | VERBPASTNEG | VERB | VERBNEG
// Done by: ----- 
void tense() {
  cout << "Processing <tense>" << endl;
  switch (next_token()) {
  case VERBPAST:
    match(VERBPAST);
    break;
  case VERBPASTNEG:
    match(VERBPASTNEG);
    break;
  case VERB:
    match(VERB);
    break;
  case VERBNEG:
    match(VERBNEG);
    break;
  default:
    syntaxerror2(TENSE);
  }
}

// Done by: ----- 
// Grammar: <be> ::= IS | WAS
void be() {
  cout << "Processing <be>" << endl;
  switch (next_token()) {
  case IS:
    match(IS);
    break;
  case WAS:
    match(WAS);
    break;
  default:
    syntaxerror2(BE);
  }
}

// Done by: -----
// Grammar: <verb> ::= WORD2
void verb() {
  cout << "Processing <verb>" << endl;
  match(WORD2);
}

// Done by: -----------
// Grammar: <noun> ::= WORD1 | PRONOUN
void noun() {
  cout << "Processing <noun>" << endl;
  switch (next_token()) {
  case WORD1:
    match(WORD1);
    break;
  case PRONOUN:
    match(PRONOUN);
    break;
  default:
    syntaxerror2(NOUN);
  }
}

// Done by: -----
// Grammar: <after_object> ::= <noun> DESTINATION <verb> <tense> PERIOD | <verb> <tense> PERIOD
void after_object() {
  cout << "Processing <afterObject>" << endl;
  switch (next_token()) {
  case WORD1: case PRONOUN:
    noun();
    match(DESTINATION);
    verb();
    tense();
    match(PERIOD);
    break;
  case WORD2:
    verb();
    tense();
    match(PERIOD);
    break;
  default:
    syntaxerror2(AFTER_OBEJCT);
  }
}

// Done by: -----
// Grammar: <after noun> ::= <be> PERIOD | DESTINATION <verb> <tense> PERIOD | OBJECT <after obejct>
void after_noun() {
  cout << "Processing <afterNoun>" << endl;
  switch (next_token()) {
  case IS: case WAS:
    be();
    match(PERIOD);
    break;
  case DESTINATION:
    match(DESTINATION);
    verb();
    tense();
    match(PERIOD);
    break;
  case OBJECT:
    match(OBJECT);
    after_object();
    break;
  default:
    syntaxerror2(AFTER_NOUN);
  }
}


// Done by: Ased Adus
// Grammar: <after subject>::= <verb> <tense> PERIOD | <noun> <after noun>
void after_subject() {
  cout << "Processing <afterSubject>" << endl;
  switch (next_token())
    {
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
    case WORD1: case PRONOUN:
      noun();
      after_noun();
      break;
    default:
      syntaxerror2(AFTER_SUBJECT);
    }
}


// Grammar: <s>::= [CONNECTOR] <noun> SUBJECT <after subject>
// Done by: Ased Adus
void s(){
  cout << "Processing <s>" << endl;    
  switch (next_token()){         // the next token
  case CONNECTOR:                // if the next token is CONNECTOR
    match(CONNECTOR);            // match
    noun();                      // call <noun> 
    match(SUBJECT);              // match
    after_subject();             // call <after subject> 
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
  cout << "processing <story>\n" << endl;
  s();                          // start with <s>
  while(true)                   
    {
      if (next_token() == EOFM) { //if the next token is EOFM end the parsing
	cout << endl << "Successfully parsed <story>." << endl;
	break;
      }
      s();                        // parse the next <s> if found
    }
}


//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  Ased Adus
int main()
{
  string filename;
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  story();//** calls the <story> to start parsing
  fin.close();//** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

#endif



