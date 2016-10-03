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
void ColorChange_EmptyBox(const int& i_s, const int& j_s, const int& i_e, const int& j_e);
void drawCircle(int x0, int y0, int radius);
void drawBox(const int& i_c, const int& j_c);
void drawTriangle(const int& left, const int& right, const int& up);
void Reverse_drawTriangle(const int& left, const int& right, const int& up);
void SecondCircle(const int& x_c, const int& y_c, const int& radius);
void Tenth_Circle(const int& x_c, const int& y_c, const int& radius);
void Reverse_Tenth_Circle(const int& x_c, const int& y_c, const int& radius);
void ChangeCircle_Color(int x0, int y0, int radius);  //Change Color
bool IntheCircle(const double x, const double y, const int x_c, const int y_c, const int radius);
bool IntheBox(const int x0, const int y0, const int x1, const int y1, const int xpos, const int ypos);


//mother class
class GeometricObject
{
public:
	virtual void draw()
	{
		std::cout << "Circle Error!" << std::endl;
	}

public:
	int start_x, start_y;
	int end_x,end_y;
	double xpos, ypos;

	GeometricObject()
	{}

public:
	void initialize(const int& _start_x, const int& _start_y,
					const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}

public:
	void draw_Box(int xpos, int ypos)
	{
		drawEmptyBox(start_x, start_y, end_x, end_y);
	
		if (IntheBox(start_x, start_y + 180, end_x, end_y + 180, xpos, ypos) == true)
		{
			ColorChange_EmptyBox(start_x, start_y, end_x, end_y);
		}

		if(IntheBox(start_x, start_y-320, end_x, end_y-320, xpos, ypos) == true)
			ColorChange_EmptyBox(start_x, start_y, end_x, end_y);
		
	}
};


class r_half_Circle : public GeometricObject
{
	int center_x, center_y;
	int radius;

public:
	r_half_Circle(const int& _center_x, const int& _center_y, const int& _radius)
	{
		initialize(_center_x, _center_y, _radius);
	}

	void initialize(const int& _center_x, const int& _center_y, const int& _radius)
	{
		center_x = _center_x;
		center_y = _center_y;
		radius = _radius;
	}

	void draw()
	{
		Reverse_Tenth_Circle(center_x, center_y, radius);
	}
};

class half_Circle : public GeometricObject
{
	int center_x, center_y;
	int radius;

public:
	half_Circle(const int& _center_x, const int& _center_y, const int& _radius)
	{
		initialize(_center_x, _center_y, _radius);
	}

	void initialize(const int& _center_x, const int& _center_y, const int& _radius)
	{
		center_x = _center_x;
		center_y = _center_y;
		radius = _radius;
	}

	void draw()
	{
		Tenth_Circle(center_x, center_y, radius);
	}
};


class Triangle :public GeometricObject
{
public:
	int left, right, up;

public:
	Triangle(const int& _left, const int& _right, const int& _up)
	{
		initialize(_left, _right, _up);
	}

	void initialize(const int& _left, const int& _right, const int& _up)
	{
		left = _left;
		right = _right;
		up = _up;
	}

	void draw()
	{
		drawTriangle(left, right, up);
	}

};

class r_Triangle :public GeometricObject
{
public:
	int left, right, up;

public:
	r_Triangle(const int& _left, const int& _right, const int& _up)
	{
		initialize(_left, _right, _up);
	}

	void initialize(const int& _left, const int& _right, const int& _up)
	{
		left = _left;
		right = _right;
		up = _up;
	}

	void draw()
	{
		Reverse_drawTriangle(left, right, up);
	}
};

class F_Box :public GeometricObject
{
public:
	int start_x, start_y;

public:
	F_Box() {}

	F_Box(const int& _start_x, const int& _start_y)
	{
		initialize(_start_x, _start_y);
	}

	void initialize(const int& _start_x, const int& _start_y)
	{
		start_x = _start_x;
		start_y = _start_y;
	}

	void draw()
	{
		drawBox(start_x, start_y);
	}
};

class Line : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;

	Line()
	{}

	void draw()
	{
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

class r_Line : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;

	r_Line()
	{}
	void draw()
	{
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

class Box :public GeometricObject
{
	int start_x, start_y;
	int end_x, end_y;

public:
	Box() {}

	Box(const int& _start_x, const int& _start_y,
		const int& _end_x, const int& _end_y)
	{
		initialize(_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int& _start_x, const int& _start_y,
		const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}

	void draw()
	{
		drawEmptyBox(start_x, start_y, end_x, end_y);
	}
};

class s_Circle : public GeometricObject
{
	int center_x, center_y;
	int radius;

public:
	s_Circle(const int& _center_x, const int& _center_y, const int& _radius)
	{
		initialize(_center_x, _center_y, _radius);
	}

	void initialize(const int& _center_x, const int& _center_y, const int& _radius)
	{
		center_x = _center_x;
		center_y = _center_y;
		radius = _radius;
	}

	void draw()
	{
		drawCircle(center_x, center_y, radius);
	}
};

class L_Line :public GeometricObject
{
	int start_x;
	int start_y, end_y;

public:
	L_Line() {}

	L_Line(const int& _start_x, const int& _start_y,
		const int& _end_y)
	{
		initialize(_start_x, _start_y, _end_y);
	}

	void initialize(const int& _start_x, const int& _start_y,
		const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_y = _end_y;
	}

	void draw()
	{
		for (int i = start_y; i < end_y; i++)
			drawPixel(start_x, i, 0.0f, 0.0f, 0.0f);
	}
};

GeometricObject **my_objects = new GeometricObject*[40];

void drawOnPixelBuffer(int xpos, int ypos)
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	//draw Icon
	for (int i = 0; i < 20; i++)
		my_objects[i]->draw();

	//draw Box
	for (int i = 20; i < 40; i++)
		my_objects[i]->draw_Box(xpos, ypos);
}

int main(void)
{
	//initialize Line
	for (int i = 0; i < 2; i++)
	{
		Line *temp = new Line;
		temp->start_x = 50 + 50 * i;
		temp->start_y = 135;
		temp->end_x = 80 + 50 * i;
		temp->end_y = 165;

		my_objects[i] = temp;
	}

	//initialize Box
	for (int i = 2, k = 0; i < 4; i++)
	{
		my_objects[i] = new Box((i + k) * 30 - 15, 385, 30 * (i + k + 1) - 15, 415);
		k++;
	}

	//initialize s_Circle
	for (int i = 4; i < 6; i++)
	{
		my_objects[i] = new s_Circle(i * 60 - 60, 400, 20);
	}

	//initialize Full_Box
	for (int i = 6; i < 8; i++)
	{
		my_objects[i] = new F_Box(i * 60 - 180, 150);
	}

	//initialize Triangle
	for (int i = 8, k = 0; i < 10; i++)
	{
		my_objects[i] = new Triangle((i + k - 3) * 30 + 135, (i + k - 3) * 30 + 170, 280);
		k++;
	}

	//initialize half_Circle
	for (int i = 10, k = 2; i < 12; i++)
	{
		my_objects[i] = new half_Circle((i + k) * 30 - 55, 400, 10);
		k++;
	}

	//initialize re_half_Circle
	for (int i = 12, k = 3; i < 14; i++)
	{
		my_objects[i] = new r_half_Circle((i + k) * 30 - 35, 150, 10);
		k++;
	}

	//initialize reverse_Line
	for (int i = 14; i < 16; i++)
	{
		r_Line *temp = new r_Line;
		temp->start_x = 350 + 50 * i;
		temp->start_y = 415;
		temp->end_x = 380 + 50 * i;
		temp->end_y = 385;

		my_objects[i] = temp;
	}

	//initialize re_Triangle
	for (int i = 16, k = 0; i < 18; i++)
	{
		my_objects[i] = new r_Triangle((i + k) * 30 + 680, (i + k + 1) * 30 + 690, 820);
		k++;
	}

	//initialize 1-Line
	for (int i = 18, k = 0; i < 20; i++)
	{
		my_objects[i] = new L_Line(30 * (i + k) + 640, 130, 160);
		k++;
	}

	//initialize Circle  ->  Box
	for (int i = 20; i < 40; i++)
	{
		GeometricObject *temp = new GeometricObject;
		temp->start_x = (i - 19) * 60-25;
		temp->start_y = 370;
		temp->end_x = (i - 19) * 60+25;
		temp->end_y=430;

		my_objects[i] = temp;
		if (i >= 30)
		{
			GeometricObject *temp = new GeometricObject;
			temp->start_x = (i - 29) * 60-25;
			temp->start_y = 120;
			temp->end_x = (i - 29) * 60+25;
			temp->end_y = 180;

			my_objects[i] = temp;
		}
		/*my_objects[i] = new GeometricObject((i - 19) * 60, 400, 30);
		if (i >= 30)
		my_objects[i] = new GeometricObject((i - 29) * 60, 150, 30);*/
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

		drawOnPixelBuffer(xpos, ypos);  //Draw Function

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
				drawPixel(i, j, 0.0f, 0.0f, 1.0f);

		}
}

void drawBox(const int& i_c, const int& j_c)
{
	const int thickness = 15;

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
	drawLine(left, (up / 2), (left + right) / 2, up / 2 + 30, 1.0f, 0.0f, 0.0f);
	drawLine((left + right) / 2, up / 2 + 30, right, (up / 2), 1.0f, 0.0f, 0.0f);
	drawLine(left, (up / 2), right, (up / 2), 1.0f, 0.0f, 0.0f);
}

void Reverse_drawTriangle(const int& left, const int& right, const int& up)
{
	drawLine(left, (up / 2), (left + right) / 2, up / 2 - 30, 1.0f, 0.0f, 0.0f);
	drawLine((left + right) / 2, up / 2 - 30, right, (up / 2), 1.0f, 0.0f, 0.0f);
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

void Reverse_Tenth_Circle(const int& x_c, const int& y_c, const int& radius)
{
	for (double j = 0; j<height; j++)
		for (double i = 0; i < width; i++)
		{
			double func = ((i - x_c)*(i - x_c) + (j - y_c)*(j - y_c) - radius*radius);
			if (func >= 0 && func <= 120 && i >= x_c)
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

bool IntheBox(const int start_x, const int start_y,
			  const int end_x, const int end_y,
			  const int xpos, const int ypos)
{
	/*if ((xpos >= start_x&&xpos <= end_x)||(ypos >= start_y&&ypos <= end_y))
		return true;
	else return false;*/ //위아래 둘다바뀌는게 문제
	if ((xpos >= start_x&&xpos <= end_x) && (ypos >= start_y&&ypos <= end_y))
		return true;
	else return false;
}

void ColorChange_EmptyBox(const int& i_s, const int& j_s, const int& i_e, const int& j_e)  //s=start, e=end
{
	for (int j = j_s; j <= j_e; j++)
		for (int i = i_s; i <= i_e; i++)
		{
			if (j == j_e || j == j_s || i == i_s || i == i_e)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
}