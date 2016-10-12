#include <iostream>

template <class TT>
class Vector2D
{
public:
	TT x_, y_;

	void print()
	{
		std::cout << x_ << "  " << y_ << std::endl;
	}
};

int main()
{
	Vector2D<int> int_vec;
	int_vec.x_ = 3;
	int_vec.y_ = 5;
	int_vec.print();

	Vector2D<float> float_vec;
	float_vec.x_ = 3.4f;
	float_vec.y_ = 5.6f;
	float_vec.print();

	Vector2D<double> double_vec;
	double_vec.x_ = 7.7;
	double_vec.y_ = 8.8;
	double_vec.print();

	return 0;
}