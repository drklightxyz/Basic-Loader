// Required to work.
#include <iostream>
#include "trashauth/KeyAuth.hpp"
#include "util.h"
#include "debug.h"
#include "crypt/xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#pragma comment(lib, "urlmon.lib")
using namespace KeyAuth;
using namespace std;

std::string name = XorStr("pastedloader"); // Your own keyauth application name.
std::string ownerid = XorStr("*******"); // Your keyauth owener ID.
std::string secret = XorStr("59cb63ff48aaa323bd3b78c036d946ccd3a28774a33d22a9901e1919a168d729");  // Your own keyauth application secret.
std::string version = XorStr("1.0"); // Your own keyauth application version.
api KeyAuthApp(name, ownerid, secret, version);
// Some nice features.
void AntiDebug();
void cleanfiles();
bool pastedShitRunning = true;
//

void spoof()
{
	Util::clear();
	std::string spoof = XorStr("https://traps.gay/tranny.mapper.exe").c_str(); // Obviously wont work
	std::string spoof1 = XorStr("mapper.exe").c_str(); // Dont use this path lmao
	std::string spoof11 = XorStr("https://traps.gay/tranny.driver.sys").c_str();
	std::string spoof111 = XorStr("driver.sys").c_str(); // Dont use this path lmao
	std::string command = XorStr("mapper.exe driver.sys"); // Obviously wont work
	URLDownloadToFileA(NULL, spoof.c_str(), spoof1.c_str(), 0, NULL);
	URLDownloadToFileA(NULL, spoof11.c_str(), spoof111.c_str(), 0, NULL);
	Sleep(500);
	system(command.c_str());
}

void clean()
{
	Util::clear();
	std::string clean = XorStr("https://traps.gay/aids.bat").c_str(); // Obviously wont work
	std::string clean1 = XorStr("aids.bat").c_str(); // Dont use this path lmao
	std::string command = XorStr("start aids.bat"); // Obviously wont work
	URLDownloadToFileA(NULL, clean.c_str(), clean1.c_str(), 0, NULL);
	Sleep(500);
	system(command.c_str());
}


int main()
{
	std::string licensekey;
	int option;
	// Start faggot auth
	KeyAuthApp.init();
	// Create protection loop
	std::thread anti(AntiDebug);
	Util::SetColor(RED);
	std::cout << "    [LOADER] ";
	Util::SetColor(WHITE);
	std::cout << "key: ";
	std::cin >> licensekey;
	KeyAuthApp.license(licensekey);
	Util::SetColor(RED);
	std::cout << "    [1] ";
	Util::SetColor(WHITE);
	std::cout << "tranny spoof";
	Util::SetColor(RED);
	std::cout << "\n    [2] ";
	Util::SetColor(WHITE);
	std::cout << "tranny clean";
	Util::SetColor(RED);
	std::cout << "\n\n    [->] ";
	Util::SetColor(WHITE);
	std::cin >> option;

	switch (option)
	{
	case 1:
		spoof();
		break;
	case 2:
		clean();
		break;
	}
}

void AntiDebug()
{
	while (pastedShitRunning)
	{
		// Debug protection
		cleanfiles();
		driverdetect();
		SetConsoleTitleA(Util::random_string(1).c_str());
	}
}

void cleanfiles()
{
	// Clean cache.
	system(XorStr("@del /s /f /a:h /a:a /q C:\\Users\\%username%\\AppData\\Local\\Microsoft\\Windows\\INetCache\\IE\\*.* >nul 2>&1").c_str());
}