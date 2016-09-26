#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdbool.h>

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

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

void drawBox(const int& i_c, const int& j_c)
{
	const int thickness = 70;

	for (int j = j_c - thickness; j < j_c + thickness; j++)
		for (int i = i_c - thickness; i < i_c + thickness; i++)
		{
			drawPixel(i, j, 0.0f, 1.0f, 1.0f);
		}
}

void drawTriangle(const int& left, const int& right, const int& up)
{
	drawLine(left, (up / 2), (left + right) / 2, up - 10, 1.0f, 0.0f, 0.0f);
	drawLine((left + right) / 2, up - 10, right, (up / 2), 1.0f, 0.0f, 0.0f);
	drawLine(left, (up / 2), right, (up / 2), 1.0f, 0.0f, 0.0f);
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

		drawPixel(x0 + x, y0 + y, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 + y, y0 + x, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 - y, y0 + x, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 - x, y0 + y, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 - x, y0 - y, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 - y, y0 - x, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 + y, y0 - x, 0.0f, 1.0f, 1.0f);
		drawPixel(x0 + x, y0 - y, 0.0f, 1.0f, 1.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

bool IntheCircle(const double x, const double y, const double x_c, const double y_c, const int radius)
{
	const double func = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - radius*radius;

	if (func > 0.0) return false;
	else return true;
}

int main(void)
{
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

		//First Icon
		drawCircle(80, 400, 60);
		drawLine(40, 380, 120, 420, 1.0f, 0.0f, 0.0f);
		drawLine(41, 380, 121, 420, 1.0f, 0.0f, 0.0f);
		drawLine(42, 380, 122, 420, 1.0f, 0.0f, 0.0f);  //3-width-line
		if (IntheCircle(xpos, ypos, 80, height - 400, 60) == true)
		{
			ChangeCircle_Color(80, 400, 60);
		}

		//Second Icon
		drawCircle(200, 400, 60);
		SecondCircle(200, 400, 30);

		if (IntheCircle(xpos, ypos, 200, height - 400, 60) == true)
		{
			ChangeCircle_Color(200, 400, 60);
		}

		//Third Icon
		drawCircle(320, 400, 60);
		drawEmptyBox(300, 380, 340, 420);

		if (IntheCircle(xpos, ypos, 320, height - 400, 60) == true)
		{
			ChangeCircle_Color(320, 400, 60);
		}

		//Fourth Icon
		drawCircle(440, 400, 60);
		drawLine(410, 380, 460, 430, 1.0f, 0.0f, 0.0f);
		drawLine(410, 430, 460, 380, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 430, height - 400, 60) == true)
		{
			ChangeCircle_Color(440, 400, 60);
		}

		//Fifth Icon
		drawCircle(560, 400, 60);
		for (int i = 370; i < 440; i++)
			drawPixel(560, i, 1.0f, 0.0f, 0.0f);

		drawLine(530, 390, 560, 370, 1.0f, 0.0f, 0.0f);
		drawLine(560, 370, 590, 390, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 560, height - 400, 60) == true)
		{
			ChangeCircle_Color(560, 400, 60);
		}

		//Sixth Icon
		drawCircle(80, 150, 60);

		drawLine(50, 150, 110, 150, 1.0f, 0.0f, 0.0f);
		drawLine(85, 165, 110, 150, 1.0f, 0.0f, 0.0f);
		drawLine(85, 135, 110, 150, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 80, height - 150, 60) == true)
		{
			ChangeCircle_Color(80, 150, 60);
		}

		//Seventh Icon
		drawCircle(200, 150, 60);

		drawLine(170, 120, 200, 180, 1.0f, 0.0f, 0.0f);
		drawLine(200, 180, 230, 120, 1.0f, 0.0f, 0.0f);
		drawLine(183, 145, 217, 145, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 200, height - 150, 60) == true)
		{
			ChangeCircle_Color(200, 150, 60);
		}

		//Eigth Icon
		drawCircle(320, 150, 60);
		for (int i = 100; i < 190; i++)
			drawPixel(320, i, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 320, height - 150, 60) == true)
		{
			ChangeCircle_Color(320, 150, 60);
		}


		//Nineth Icon
		drawCircle(440, 150, 60);

		drawLine(405, 150, 475, 150, 1.0f, 0.0f, 0.0f);
		drawLine(405, 150, 420, 165, 1.0f, 0.0f, 0.0f);
		drawLine(405, 150, 420, 135, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 440, height - 150, 60) == true)
		{
			ChangeCircle_Color(440, 150, 60);
		}

		//Tenth Icon
		drawCircle(560, 150, 60);

		for (int i = 120; i < 175; i++)
			drawPixel(560, i, 1.0f, 0.0f, 0.0f);

		drawLine(545, 160, 560, 175, 1.0f, 0.0f, 0.0f);
		drawLine(560, 175, 575, 160, 1.0f, 0.0f, 0.0f);

		if (IntheCircle(xpos, ypos, 560, height - 150, 60) == true)
		{
			ChangeCircle_Color(560, 150, 60);
		}

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		//We do that.


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}