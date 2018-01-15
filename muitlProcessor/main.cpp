#include "stdafx_h/StdAfx.h"
#include "Windows.h"
#include <iostream>

using namespace std;

int main()
{
    STARTUPINFO startupInfo = { 0 };
    PROCESS_INFORMATION  processInformation = { 0 };

    BOOL bSuccess = CreateProcess(
                                  TEXT("D:\\Program Files\\Notepad++\\notepad++.exe"), NULL, NULL,
                                  NULL, FALSE, NULL, NULL, NULL, &startupInfo,
                                  &processInformation);

    if(bSuccess)
    {
        cout << "Process started! " << endl
             << "Process ID : \t" << processInformation.dwProcessId << endl;
    }
    else
    {
        cout << "Can not Start Process !" << endl
             << "Error code : \t" << GetLastError() << endl;
    }
    return 0;
}
