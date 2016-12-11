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
	int row_num=0, column_num=0;
	int** number = nullptr;

	Matrix_MxM(const int& row_num_, const int& column_num_)
	{
		row_num = row_num_;
		column_num = column_num_;

		number = new int*[row_num];
		for (int r = 0; r < row_num; r++)
			number[r] = new int[column_num];
	}

	int& assign(const int& _row_num_, const int& _column_num_)
	{
		row_num = _row_num_;
		column_num = _column_num_;

		return number[row_num][column_num];
	}

	friend VectorND operator*(const Matrix_MxM& mat_var_, const VectorND& vec_var_)
	{
		VectorND vector(3);
		
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				vector[r]=mat_var_.assign(r, c)*vec_var_.assign(r);
			}
		}
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
	cout << "Vector N값:";
	cin >> num;

	VectorND v(num);

	for (int i = 0; i<num; i++)
		v.assign(i) = 1 + i;

	for (int i = 0; i < num; i++)
		cout << v.assign(i) << " ";

	cout << endl << endl;

	int row, column;
	cout << "row 값:";
	cin >> row;
	cout << "column 값:";
	cin >> column;

	Matrix_MxM m(row, column);    //row, column

	if (column != num)
	{
		cout << "column와(과) N은 같아야합니다" << endl;
		return 0;
	}

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

	cout << endl;

	VectorND y(row);
	y = m * v;


	for (int r = 0; r < row; r++)
		cout << y.assign(r) << endl;
	return 0;

}