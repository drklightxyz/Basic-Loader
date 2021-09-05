#pragma once
#include "crypt/xorstr.hpp"
#include <random>
#include <WinBase.h>
#include <consoleapi2.h>

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

namespace Util
{
    std::string random_string(const int len) {
        const std::string alpha_numeric("ABCDEFGHIJKLMNOPRSTUVZabcdefghijklmnoprstuvz");
        std::default_random_engine generator{ std::random_device{}() };
        const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };
        std::string str(len, 0);
        for (auto& it : str) {
            it = alpha_numeric[distribution(generator)];
        }

        return str;
    }

    void SetColor(unsigned short color)
    {
        HANDLE con = 0;
        con = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(con, color);
    }

    void clear()
    {
        // Clear console
        system(XorStr("cls").c_str());
    }

}

