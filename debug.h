#include <atlbase.h>
#include "crypt/xorstr.hpp"
#include <clocale>
#include <TlHelp32.h>
#include "lazy.hpp"
#include <iostream>
std::wstring s2ws(const std::string& s) {
	std::string curLocale = setlocale(LC_ALL, "");
	const char* _Source = s.c_str();
	size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
	wchar_t* _Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

DWORD FindProcessId(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);
	auto createtoolhelp = LI_FN(CreateToolhelp32Snapshot);
	HANDLE processesSnapshot = createtoolhelp(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		auto closehand = LI_FN(CloseHandle);
		closehand(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			auto closehand = LI_FN(CloseHandle);
			closehand(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	return 0;
}

// Faggot auth protection
void driverdetect()
{
	const TCHAR* devices[] = {
_T("\\\\.\\NiGgEr"),
_T("\\\\.\\KsDumper")
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE) {
			system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE just why. && ECHO why load with debugger?").c_str());
			exit(0);
		}
		else
		{

		}
	}
}

