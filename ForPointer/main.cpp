#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int *a = NULL;
    int b=1;
    int c = 10;
    a = & b;
    a = & c;
    cout << a << endl;
    return 0;
}
