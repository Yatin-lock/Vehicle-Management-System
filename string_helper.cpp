#include <bits/stdc++.h>
//#include <"string_helper.h">
using namespace std ;
vector <string> split (const string &s, char delimiter)
{
    vector <string> tokens ;
    string token ;
    istringstream tokenStream (s) ;

    while (getline (tokenStream , token , delimeter) )
    {
        tokens.push_back (token);
    }

    return tokens ;
}