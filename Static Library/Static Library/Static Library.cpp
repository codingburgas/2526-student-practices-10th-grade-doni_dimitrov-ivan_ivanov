

#include <iostream>
#include "Static Library.h"
#include <fstream>
using namespace std;

void print()
{

    cout << ifstream("menu.txt").rdbuf();
}


