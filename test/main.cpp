#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <typeinfo>
#include <time.h>
#include <sys/timeb.h>
#include <CString>
#include <CWchar>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

using namespace std;


extern "C"
{
    int main()
    {
        char *p = new char[100];
        int i = 16;
        string a = "1000345";
        string topic = "china";
        cout << 244 & 0x80 << endl;
        //string j = 11 % 10;
        //string path = topic + "/" + itoa(i);
        //i = atoi(j.c_str());
        char t_cmd[100];
        string t_cmd2;
        sprintf(t_cmd,"%s/%d",topic.c_str(),i);
        t_cmd2 = t_cmd;
        cout << t_cmd << endl;
        cout << typeid(t_cmd).name() << endl;
        cout << 102 % 2 << endl;
        struct timeb tb;
        cout << localtime(&tb.time) << endl;
        ftime(&tb);
        cout << tb.time << endl;
        cout << 1000 * tb.time + tb.millitm << endl;

        if(!0)
        {
            cout << "THis is 0" << endl;
        }
        if(!(-1))
        {
            cout << "This is -1" << endl;
        }

        return 0;
    }


}
