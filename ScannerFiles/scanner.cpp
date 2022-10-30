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

enum State
{
    q0,
    q0q1,
    q0qy,
    qy,
    qs,
    qc,
    qt,
    qsa
};

bool contains(vector<char> v, char c)
{
    return std::find(v.begin(), v.end(), c) != v.end();
}

// WORD DFA
// Done by: Ased Adus, Micah Johnson
// RE:   **
bool word(string s)
{

    State state = q0;
    int charpos = 0;

    while (s[charpos] != '\0')
    {
        char c = s[charpos]; // easier to type

        bool isVowel = contains({'a', 'e', 'i', 'o', 'u', 'I', 'E'}, c);

        // cout << "State: " << state << ", char: " << c << endl;

        switch (state)
        {

        case (q0):
            if (isVowel)
                state = q0q1;
            else if (contains({'b', 'g', 'h', 'k', 'm', 'n', 'p', 'r'}, c))
                state = qy;
            else if (c == 't')
                state = qt;
            else if (c == 's')
                state = qs;
            else if (c == 'c')
                state = qc;
            else if (contains({'d', 'w', 'z', 'y', 'j'}, c))
                state = qsa;
            else
            { /* cout << "Fail in q0 with character: " << c << endl; */
                return false;
            }
            break;

        case (q0q1):
            if (isVowel)
                state = q0q1;
            else if (contains({'b', 'g', 'h', 'k', 'm', 'p', 'r'}, c))
                state = qy;
            else if (c == 'n')
                state = q0qy;
            else if (c == 't')
                state = qt;
            else if (c == 's')
                state = qs;
            else if (c == 'c')
                state = qc;
            else if (contains({'d', 'w', 'z', 'y', 'j'}, c))
                state = qsa;
            else
            { /* cout << "Fail in q0q1 with character: " << c << endl; */
                return false;
            }
            break;

        case (q0qy):
            if (isVowel)
                state = q0q1;
            else if (contains({'b', 'g', 'h', 'k', 'm', 'n', 'p', 'r'}, c))
                state = qy;
            else if (c == 't')
                state = qt;
            else if (c == 's')
                state = qs;
            else if (c == 'c')
                state = qc;
            else if (contains({'d', 'w', 'z', 'y', 'j'}, c))
                state = qsa;
            else
            { /* cout << "Fail in q0qy with character: " << c << endl; */
                return false;
            }
            break;

        case (qy):
            if (isVowel)
                state = q0q1;
            else if (c == 'y')
                state = qsa;
            else
            { /* cout << "Fail in qy with character: " << c << endl; */
                return false;
            }
            break;

        case (qs):
            if (isVowel)
                state = q0q1;
            else if (c == 'h')
                state = qsa;
            else
            { /* cout << "Fail in qs with character: " << c << endl; */
                return false;
            }
            break;

        case (qc):
            if (c == 'h')
                state = qsa;
            else
            { /* cout << "Fail in qc with character: " << c << endl; */
                return false;
            }
            break;

        case (qt):
            if (isVowel)
                state = q0q1;
            else if (c == 's')
                state = qsa;
            else
            { /* cout << "Fail in qt with character: " << c << endl; */
                return false;
            }
            break;

        case (qsa):
            if (isVowel)
                state = q0q1;
            else
            { /* cout << "Fail in qsa with character: " << c << endl; */
                return false;
            }
            break;
        }
        charpos++;
    } // end of while

    // where did I end up????
    return state == q0 || state == q0q1 || state == q0qy;
}

// PERIOD DFA
// Done by: ** Micah
bool period(string s)
{ // complete this **
    return s == ".";
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: ** Micah

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype
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
string tokenName[30] = {"WORD1",   "WORD2", "PERIOD", "ERROR",  "EOFM",        "PRONOUN",  "SUBJECT",    "VERB",
                        "VERBNEG", "IS",    "WAS",    "OBJECT", "DESTINATION", "VERBPAST", "VERBPASTNEG"};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

vector<vector<string>> reservedwords;

void initreservedwords()
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
// ** Done by:
tokentype scanner(string &w)
{
    if (reservedwords.empty())
        initreservedwords();

    // ** Grab the next word from the file via fin
    // 1. If it is eofm, return right now.
    fin >> w;
    if (w == "eofm")
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
// Done by:  Louis
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

        // cout << "Type is:" << tokenName[thetype] << endl;
        // cout << "Word is:" << theword << endl;
        cout << "\n\"" << theword << "\" is token type " << tokenName[thetype] << endl;
    }

    cout << "End of file is encountered." << endl;
    fin.close();

} // end

#endif