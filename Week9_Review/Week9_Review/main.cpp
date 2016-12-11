#include <iostream>

using namespace std;

class hypothesis
{
public:
	float a_, b_;

	hypothesis()
	{
		a_ = 0.0f;
		b_ = 0.0f;
	}

	float getY(const float& x_input)
	{
		return (a_*x_input + b_);
	}
};


int main()
{
	hypothesis number;

	const float x_input[3] = { 0.0f,1.0f,2.0f };
	const float y_data[3] = { 0.0f,2.0f,4.0f };

	const float learning_rate = 0.01f;

	for (int tr = 0; tr < 500; tr++)
	{
		for (int i = 0; i < 3; i++)
		{
			const float error = y_data[i] - number.getY(x_input[i]);
			const float square_error = 0.5*error*error;

			const float dse_da = error*-x_input[i];
			const float dse_db = error*-1;

			number.a_ -= dse_da*learning_rate;
			number.b_ -= dse_db*learning_rate;


			cout << y_data[i] << "  " << number.getY(x_input[i]) << endl << endl;
		}
	}


	//cout << number.getY(30) << endl;
}