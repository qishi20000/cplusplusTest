#include <iostream>

int main()
{
	char a[] = "中\0";
	std::cout << a << std::endl;
}