#include <bits/stdc++.h>
#include "y.tab.h"
#include <fstream>


using namespace std;

extern vector<string> declares, uses, declerrors, typerrors;

int main()
{


    //ofstream fstream;

    yyparse();


    return 0;
}