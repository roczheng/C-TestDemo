#include "stdafx_h/StdAfx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    STARTUPINFO startupinfo = { 0 };
    PROCESS_INFORMATION process_infomation = { 0 };

    BOOL bSuccess = CreateProcess(
                                  TEXT("D:\\Program Files\\Notepad++\\notepad++.exe"),NULL, NULL, NULL, FALSE, NULL, NULL, NULL,
                                  &startupinfo,&process_infomation);

    if(bSuccess)
    {
        cout << "Process Started!" << endl
        << "Process ID :\t" << process_infomation.dwProcessId << endl;
    }
    else
    {
        cout << "Process cannot Started!" << endl
        << "Error Code :\t" << GetLastError() << endl;
    }
    return 0;
}
