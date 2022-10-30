#ifndef SCANNER
#define SCANNER

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 16
//=====================================================

// --------- Two DFAs ---------------------------------
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

//This function will return true if char c is found in the vector v
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
            else if (contains({'b', 'g', 'h', 'k', 'm', 'n', 'p', 'r'}, c)) // if char contains one of those characters go to state qy
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
            else if (contains({'d', 'w', 'z', 'y', 'j'}, c)))// if char contains one of those characters go to state qsa
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

        case (qs):                                        //  state (q0qy) CASE #5
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

    // where did I end up????                              // return true if we end up in one of the accepted state which are q0, q0q1, and q0qy
    return state == q0 || state == q0q1 || state == q0qy;
}

// PERIOD DFA
// Done by: ** Micah
bool period(string s)                                       // return true if the string contain only period
{ // complete this **
    return s == ".";
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: ** Micah
// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype                                              // this enum contains all of the tokentype that will be labeled by the scanner
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

    /* If you are going to add any new type, do so above here.
    Otherwise the code will break. Do not break ze code pls. */
    /* No touchy */ CONNECTOR /* No touch */
    /* Do not put anything below here. */
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "EOFM", "PRONOUN", "SUBJECT", "VERB", "VERBNEG", "IS",
                        "WAS", "OBJECT", "DESTINATION", "VERBPAST", "VERBPASTNEG",

                        /* Add new type ABOVE here.
                        Do not add anything below here.
                        Otherwise the code will break.
                        Do not break the code. */
                        "CONNECTOR"
                        /* Do not. Do not. Do not. */};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

vector<vector<string>> reservedwords;

void initreservedwords() // this function will organize the the reserved words with their tokentype in double vector
{
    for (int i = WORD1; i <= CONNECTOR; ++i)      
    {
        reservedwords.push_back(vector<string>());
    }
    reservedwords[VERB].push_back("masu");
    reservedwords[VERBNEG].push_back("masen");
    reservedwords[VERBPAST].push_back("mashita");
    reservedwords[VERBPASTNEG].push_back("masendeshita");
    reservedwords[IS].push_back("desu");
    reservedwords[WAS].push_back("deshita");
    reservedwords[OBJECT].push_back("o");
    reservedwords[SUBJECT].push_back("wa");
    reservedwords[DESTINATION].push_back("ni");

    reservedwords[PRONOUN].push_back("watashi");
    reservedwords[PRONOUN].push_back("anata");
    reservedwords[PRONOUN].push_back("kare");
    reservedwords[PRONOUN].push_back("kanojo");
    reservedwords[PRONOUN].push_back("sore");
    reservedwords[CONNECTOR].push_back("mata");
    reservedwords[CONNECTOR].push_back("soshite");
    reservedwords[CONNECTOR].push_back("shikashi");
    reservedwords[CONNECTOR].push_back("dakara");
}

// ------------ Scanner and Driver -----------------------

ifstream fin; // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Micah
tokentype scanner(string &w)
{
    if (reservedwords.empty())          //if the reservedword is empty call initreservedwords function to store the resurved words in to double vector 
        initreservedwords();

    fin >> w;                                // ** Grab the next word from the file via fin
    if (w == "eofm")                         // 1. If it is eofm, return right now.
        return EOFM;

    /*  **
    2. Call the token functions (word and period)
    one after another (if-then-else).
    Generate a lexical error message if both DFAs failed.
    Let the tokentype be ERROR in that case. */
    if (period(w))
        return PERIOD;
    if (!word(w))
        return ERROR;

    /* 3. If it was a word,
    check against the reservedwords list.
    If not reserved, tokentype is WORD1 or WORD2
    decided based on the last character. */
    for (int i = WORD1; i < CONNECTOR; ++i)
    {
        if (std::find(reservedwords[i].begin(), reservedwords[i].end(), w) != reservedwords[i].end())
            return static_cast<tokentype>(i);
    }
    /* 4. Return the token type & string  (pass by reference) */
    char last = w[w.length() - 1];
    return (last == 'I' || last == 'E') ? WORD2 : WORD1;
} // the end of scanner

void wordTest()
{
    cout << word("soshite") << endl;
    cout << word("watashi") << endl;
    cout << word("wa") << endl;
    cout << word("rika") << endl;
    cout << word("riKa") << endl;
    cout << word("rIka") << endl;
    cout << word("YarI") << endl;
    cout << word("boiiiiilmaokkkk") << endl;
}

// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis, Micah
int main()
{

    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename /* .c_str() */);

    // the loop continues until eofm is returned.
    while (true)
    {
        thetype = scanner(theword); // call the scanner which sets
                                    // the arguments
        if (theword == "eofm")
            break; // stop now

        cout << "\n\"" << theword << "\" is token type " << tokenName[thetype] << endl;
    }

    cout << "End of file is encountered." << endl;
    fin.close();

} // end

#endif
