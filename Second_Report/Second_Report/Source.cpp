#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdbool.h>
#include <iostream>

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

const int num_lines = 5;
const int num_boxes = 10;
const int num_circles = 20;

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawEmptyBox(const int& i_s, const int& j_s, const int& i_e, const int& j_e);
void drawCircle(int x0, int y0, int radius);
void drawBox(const int& i_c, const int& j_c);
void drawTriangle(const int& left, const int& right, const int& up);
void SecondCircle(const int& x_c, const int& y_c, const int& radius);
void Tenth_Circle(const int& x_c, const int& y_c, const int& radius);
void ChangeCircle_Color(int x0, int y0, int radius);  //Change Color
bool IntheCircle(const double x, const double y, const int x_c, const int y_c, const int radius);

class GeometricObject
{
public:
	virtual void draw()
	{
		std::cout << "Error!" << std::endl;
	}
};

class Circle : public GeometricObject
{
public:
	int center_x, center_y;
	int radius;
	double xpos, ypos;

public:
	Circle(const int& _center_x, const int& _center_y, const int& _radius)
	{
		initialize(_center_x,_center_y,_radius);
	}

public:
	void initialize(const int& _center_x, const int& _center_y, const int& _radius)
	{
		center_x = _center_x;
		center_y = _center_y;
		radius = _radius;
	}

public:
	void draw()
	{
		drawCircle(center_x, center_y, radius);

		if (IntheCircle(xpos, ypos, center_x, height-center_y, radius)==true)
		{
			ChangeCircle_Color(center_x, center_y, radius);
		}
	}
};

GeometricObject **my_objects = new GeometricObject*[num_circles];

void drawOnPixelBuffer(double xpos, double ypos)
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	for (int i = 0; i < num_circles / 2; i++)
	{
		my_objects[i]->draw();

		if (IntheCircle(xpos, ypos, (i + 1) * 60, height - 400, 30) == true)
		{
			ChangeCircle_Color((i + 1) * 60, 400, 30);
		}
	}

	for (int i = num_circles / 2; i < num_circles; i++)
	{
		my_objects[i]->draw();

		if (IntheCircle(xpos, ypos, (i - 9) * 60, height - 150, 30) == true)
		{
			ChangeCircle_Color((i - 9) * 60, 150, 30);
		}
	}
}

int main(void)
{
	//Circle my_circle(60, 70, 30);
	/*Circle my_box(50, 50, 180, 200);*/
	
	//initialize Line
	/*for (int i = 0; i < 5; i++)
	{
		Line *temp = new Line;
		temp->start_x = 0 + 50 * i;
		temp->start_y = 0 ;
		temp->end_x = 50 + 50 * i;
		temp->end_y = 50;

		my_objects[i] = temp;
	}*/

	//initialize Box
	//for (int i = 5; i < 10; i++)
	//{
	//	my_objects[i] = new Circle(i * 50, 70, i * 50 + 120, 120);
	//	//my_boxes[i]->initialize(i*50, 70, i * 50 + 120, 120);
	//}

	//initialize Circle
	for (int i = 0; i < num_circles/2; i++)
	{
		my_objects[i] = new Circle((i+1) * 60, 400, 30);
	}

	for (int i = num_circles/2; i < num_circles; i++)
	{
		my_objects[i] = new Circle((i-9)* 60, 150, 30);
	}

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "GLFW Test", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		double xpos, ypos;

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);	// white background
		glfwGetCursorPos(window, &xpos, &ypos);

		drawOnPixelBuffer(xpos, ypos);

		////First Icon
		//drawLine(40, 380, 120, 420, 1.0f, 0.0f, 0.0f);
		//drawLine(41, 380, 121, 420, 1.0f, 0.0f, 0.0f);
		//drawLine(42, 380, 122, 420, 1.0f, 0.0f, 0.0f);  //3-width-line
		//if (IntheCircle(xpos, ypos, 80, height - 400, 60) == true)
		//{
		//	ChangeCircle_Color(80, 400, 60);
		//}

		////Second Icon
		//SecondCircle(200, 400, 30);

		//if (IntheCircle(xpos, ypos, 200, height - 400, 60) == true)
		//{
		//	ChangeCircle_Color(200, 400, 60);
		//}

		////Third Icon
		//drawEmptyBox(300, 380, 340, 420);

		//if (IntheCircle(xpos, ypos, 320, height - 400, 60) == true)
		//{
		//	ChangeCircle_Color(320, 400, 60);
		//}

		////Fourth Icon
		//drawLine(410, 380, 460, 430, 1.0f, 0.0f, 0.0f);
		//drawLine(410, 430, 460, 380, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 430, height - 400, 60) == true)
		//{
		//	ChangeCircle_Color(440, 400, 60);
		//}

		////Fifth Icon
		//for (int i = 370; i < 440; i++)
		//	drawPixel(560, i, 1.0f, 0.0f, 0.0f);

		//drawLine(530, 390, 560, 370, 1.0f, 0.0f, 0.0f);
		//drawLine(560, 370, 590, 390, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 560, height - 400, 60) == true)
		//{
		//	ChangeCircle_Color(560, 400, 60);
		//}

		////Sixth Icon
		//drawLine(50, 150, 110, 150, 1.0f, 0.0f, 0.0f);
		//drawLine(85, 165, 110, 150, 1.0f, 0.0f, 0.0f);
		//drawLine(85, 135, 110, 150, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 80, height - 150, 60) == true)
		//{
		//	ChangeCircle_Color(80, 150, 60);
		//}

		////Seventh Icon

		//drawLine(170, 120, 200, 180, 1.0f, 0.0f, 0.0f);
		//drawLine(200, 180, 230, 120, 1.0f, 0.0f, 0.0f);
		//drawLine(183, 145, 217, 145, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 200, height - 150, 60) == true)
		//{
		//	ChangeCircle_Color(200, 150, 60);
		//}

		////Eigth Icon
		//for (int i = 100; i < 190; i++)
		//	drawPixel(320, i, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 320, height - 150, 60) == true)
		//{
		//	ChangeCircle_Color(320, 150, 60);
		//}

		////Nineth Icon

		//drawLine(405, 150, 475, 150, 1.0f, 0.0f, 0.0f);
		//drawLine(405, 150, 420, 165, 1.0f, 0.0f, 0.0f);
		//drawLine(405, 150, 420, 135, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 440, height - 150, 60) == true)
		//{
		//	ChangeCircle_Color(440, 150, 60);
		//}

		////Tenth Icon

		//for (int i = 120; i < 175; i++)
		//	drawPixel(560, i, 1.0f, 0.0f, 0.0f);

		//drawLine(545, 160, 560, 175, 1.0f, 0.0f, 0.0f);
		//drawLine(560, 175, 575, 160, 1.0f, 0.0f, 0.0f);

		//if (IntheCircle(xpos, ypos, 560, height - 150, 60) == true)
		//{
		//	ChangeCircle_Color(560, 150, 60);
		//}



		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		//We do that.


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;
	delete[] my_objects;

	glfwTerminate();
	return 0;
}


//function
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawEmptyBox(const int& i_s, const int& j_s, const int& i_e, const int& j_e)  //s=start, e=end
{
	for (int j = j_s; j <= j_e; j++)
		for (int i = i_s; i <= i_e; i++)
		{
			if (j == j_e || j == j_s || i == i_s || i == i_e)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			else
				drawPixel(i, j, 1.0f, 1.0f, 1.0f);
		}
}

void drawBox(const int& i_c, const int& j_c)
{
	const int thickness = 70;

	for (int j = j_c - thickness; j < j_c + thickness; j++)
		for (int i = i_c - thickness; i < i_c + thickness; i++)
		{
			drawPixel(i, j, 0.0f, 1.0f, 1.0f);
		}
}

void drawCircle(int x0, int y0, int radius)  //Real Circle
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{

		drawPixel(x0 + x, y0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 - y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + x, y0 - y, 1.0f, 0.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void drawTriangle(const int& left, const int& right, const int& up)
{
	drawLine(left, (up / 2), (left + right) / 2, up - 10, 1.0f, 0.0f, 0.0f);
	drawLine((left + right) / 2, up - 10, right, (up / 2), 1.0f, 0.0f, 0.0f);
	drawLine(left, (up / 2), right, (up / 2), 1.0f, 0.0f, 0.0f);
}

void SecondCircle(const int& x_c, const int& y_c, const int& radius)
{
	for (double j = 0; j<height; j++)
		for (double i = 0; i < width; i++)
		{
			double func = ((i - x_c)*(i - x_c) + (j - y_c)*(j - y_c) - radius*radius);
			if (func >= 0 && func <= 120)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			else
				drawPixel(0, 0, 1.0f, 1.0f, 1.0f);
		}
}

void Tenth_Circle(const int& x_c, const int& y_c, const int& radius)
{
	for (double j = 0; j<height; j++)
		for (double i = 0; i < width; i++)
		{
			double func = ((i - x_c)*(i - x_c) + (j - y_c)*(j - y_c) - radius*radius);
			if (func >= 0 && func <= 120 && i <= x_c)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			else
				drawPixel(0, 0, 1.0f, 1.0f, 1.0f);
		}
}

void ChangeCircle_Color(int x0, int y0, int radius)  //Change Color
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{

		drawPixel(x0 + x, y0 + y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + y, y0 + x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - y, y0 + x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - x, y0 + y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - x, y0 - y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - y, y0 - x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + y, y0 - x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + x, y0 - y, 0.0f, 0.0f, 1.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

bool IntheCircle(const double x, const double y, 
				 const int x_c, const int y_c, const int radius)
{
	const double func = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - radius*radius;

	if (func > 0.0) return false;
	else return true;
}




//class Line : public GeometricObject
//{
//public:
//	int start_x, start_y;
//	int end_x, end_y;
//
//	void draw()
//	{
//		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
//	}
//};

//class Box : public GeometricObject
//{
//public:
//	int start_x, start_y;
//	int end_x, end_y;
//
//public:
//	//constructor
//	Box()
//	{}
//
//	Box(const int& _start_x, const int& _start_y,
//		const int& _end_x, const int& _end_y)
//	{
//		initialize(_start_x, _start_y, _end_x, _end_y);
//	}
//
//public:
//	void initialize(const int& _start_x, const int& _start_y,
//		const int& _end_x, const int& _end_y)
//	{
//		start_x = _start_x;
//		start_y = _start_y;
//		end_x = _end_x;
//		end_y = _end_y;
//	}
//	void draw()
//	{
//		drawEmptyBox(start_x, start_y, end_x, end_y);
//	}
//};