#ifndef __GUI__
#define __GUI__
#include <iostream>
#include <Windows.h>
#include <string>

enum class Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

void Text_color(int textColor, int backgroundColor);
void Set_color(bool Is_end);
std::string Display(int& num);

inline void Text_color(int textColor, int backgroundColor)
{
	int color = textColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
inline void Set_color(bool Is_end)
{
	if (!Is_end)
		Text_color(static_cast<int>(Color::LIGHTRED), static_cast<int>(Color::BLACK));
	else
		Text_color(static_cast<int>(Color::WHITE), static_cast<int>(Color::BLACK));
}
inline std::string Display(int& num)
{
	std::string graph;
	if (num == 1)
	{
		std::cout << "그래프 번호를 입력하시오(1 ~ 4)\n" << "예시) graph1.txt >>  ";
		std::cin >> graph;
	}
	else
	{
		std::cout << "\n그래프 번호를 입력하시오(1 ~ 4) (종료 : -1)\n" << "예시) graph1.txt >>  ";
		std::cin >> graph;
	}
	return graph;
}

#endif __GUI__
