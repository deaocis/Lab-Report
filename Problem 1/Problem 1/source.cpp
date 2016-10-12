#include <iostream>
#include <string>

template <class T>
void print(const T& input)
{
	std::cout << input << std::endl;
}

int main()
{
	print(1);
	print(2.345f);
	print("Hello World");

	return 0;
}
