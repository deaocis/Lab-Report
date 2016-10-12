#include <iostream>
#include <string>

template<class T>
void print(const T& input)
{
	std::cout << input << std::endl;
}

int main()
{
	print(1);
	print(1.2f);
	print(3.4);
	print("Hello World!");
}