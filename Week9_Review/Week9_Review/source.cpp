#include <iostream>
using namespace std;

class VectorND
{
public:
	int dim;
	int* b = nullptr;

	VectorND(const int& dim_)
	{
		dim = dim_;
		b = new int[dim];
	}

	VectorND()
	{}

	int operator[](const int& dim)
	{
		return b[dim];
	}

	int& assign(const int& dim)
	{
		return b[dim];
	}
};

class Matrix_MxM
{
public:
	int row_num, column_num;
	int* number1 = nullptr;
	int** number = nullptr;


	Matrix_MxM(const int& row_num_, const int& column_num_)
	{
		int* temp = nullptr;
		row_num = row_num_;
		column_num = column_num_;

		number = (int**)malloc(sizeof(int*)*row_num);

		for (int r = 0; r<row_num; r++)
			number[r] = (int*)malloc(sizeof(int)*column_num);

		//	number1 = new int[column_num];
		//	number = new int*[number1];    
	}

	int& assign(const int& _row_num_, const int& _column_num_)
	{
		row_num = _row_num_;
		column_num = _column_num_;

		return number[row_num][column_num];
	}

	friend int& operator*(const Matrix_MxM& mat_var, const VectorND& vec_var)
	{
		int result;
		mat_var*vec_var;


		return result;
	}

};

ostream& operator<<(ostream& os, const VectorND& dt)
{
	os << dt << endl;
	return os;
}

int main()
{
	int num = 0;
	cout << "Vector N°ª:";
	cin >> num;

	VectorND v(num);

	for (int i = 0; i<num; i++)
		v.assign(i) = 1 + i;

	for (int i = 0; i < num; i++)
		cout << v.assign(i) << " ";

	cout << endl << endl;

	int row, column;
	cout << "row °ª:";
	cin >> row;
	cout << "column °ª:";
	cin >> column;

	Matrix_MxM m(row, column);    //row, column

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < column; c++)
		{
			m.assign(r, c) = r + c + 1;
		}
	}

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < column; c++)
		{
			cout << m.assign(r, c) << " ";
		}
		cout << endl;
	}

	//VectorND y = m * v;
	//std::cout << y << std::endl;
	//return 0;

}