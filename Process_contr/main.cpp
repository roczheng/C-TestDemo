#include "stdafx_h/StdAfx.h"
#include <Windows.h>
#include "winternl.h"
#include <iostream>

using namespace std;

typedef NTSTATUS(NTAPI * QUERYINFORMATIONPROCESS)(
                                                  IN HANDLE Process_Handel,
                                                  IN PROCESSINFOCLASS ProcessInformationClass,
                                                  OUT PVOID ProcessInformation,
                                                  IN ULONG ProcessInformationLentgh,
                                                  OUT PULONG RetrunLength OPTIONAL
                                                  );

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

        PROCESS_BASIC_INFORMATION pbi;
        ULONG uLength = 0;

        HMODULE hDll = LoadLibrary(
                                  TEXT("C:\\Windows\\System32\ntdll.dll"));
        if(hDll)
        {
            QUERYINFORMATIONPROCESS QueryInformationProcess = (QUERYINFORMATIONPROCESS)GetProcAddress(hDll, "NtQueryInformationProcess");
            if(QueryInformationProcess)
            {
                NTSTATUS ntStatus = QueryInformationProcess(
                                                            process_infomation.hProcess,
                                                            PROCESSINFOCLASS::ProcessBasicInformation,
                                                            &pbi, sizeof(pbi), &uLength);
                if(NT_SUCCESS(ntStatus))
                {
                    cout << "Process ID(from PCB): \t"
                    << pbi.UniqueProcessId << endl;
                }
                else
                {
                    cout << "Connot Open PCB!" << endl
                    << "Error Code : \t" << GetLastError() << endl;
                }
            }
            else
            {
                cout << "Connot get NtQueryInformationProcess function! " << endl
                << "Error Code: \t" << GetLastEorror() << endl;
            }
            FreeLibrary(hDll);
        }
        else
        {
            cout << "Connt load ntdll.dll!" << endl
            << "Error code : \t" << GetLastError() << endl;
        }
    }
    else
    {
        cout << "Process cannot Started!" << endl
        << "Error Code :\t" << GetLastError() << endl;
    }
    return 0;
}
