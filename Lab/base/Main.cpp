#include <iostream>
#include <clocale>
#include "Interface.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	Interface b;
	b.Menu();
	int a;
	std::cout << "Goodbye world";
	_getch();
	//std::cin >> a;
	
}