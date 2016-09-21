#include <GLFW/glfw3.h>
#include <algorithm>

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
	drawLine(left, left, right, left, 0.0f, 1.0f, 0.0f);
	drawLine(up, up, right, left, 0.0f, 1.0f, 0.0f);
	drawLine(left, left, up, up, 0.0f, 1.0f, 0.0f);
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

//void drawPentagon(const int& i0, const int& i1, const int& i2, const int& i3, const int& i4)  //No
//{
//	drawLine(i0, i0, i1, i1, 0.0f, 0.0f, 1.0f);
//	drawLine(i1, i1, i2, i2, 0.0f, 0.0f, 1.0f);
//	drawLine(i2, i2, i3, i3, 0.0f, 0.0f, 1.0f);
//	drawLine(i3, i3, i4, i4, 0.0f, 0.0f, 1.0f);
//	drawLine(i4, i4, i0, i0, 0.0f, 0.0f, 1.0f);
//}

void drawCircle(const int& x_c, const int& y_c, const int& radius)  //first - distance=radius ->draw
{
	for (double j = 0; j<height; j++)
		for (double i = 0; i < width; i++)
		{
			double func = ((i - x_c)*(i - x_c) + (j - y_c)*(j - y_c) - radius*radius);

			if (func >= 0 && func <= 120)    
				drawPixel(i, j, 0.0f, 0.0f, 0.0f);
			else
				drawPixel(0, 0, 1.0f, 1.0f, 1.0f);
		}
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
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);	// white background


		drawLine(50, 350, 150, 450, 0.0f, 0.0f, 1.0f);
		drawLine(51, 350, 151, 450, 0.0f, 0.0f, 1.0f);
		drawLine(52, 350, 152, 450, 0.0f, 0.0f, 1.0f);  //3-width-line

		//for(int j=100;j<300;j++)
			//for (int i = 100; i < 300; i++)
			//{
				//pixels[(i + width*j) * 3 + 0] = 0.0f;
				//pixels[(i + width*j) * 3 + 1] = 1.0f;
				//pixels[(i + width*j) * 3 + 2] = 0.0f;
			//}

		drawBox(550, 370);               //full box

		drawEmptyBox(250, 300, 400, 450);   //i_s,j_s,i_e,j_e, empty box

		drawTriangle(40, 160, 100);     //left,right,up  triangle

		//drawLine(50, 150, 130, 229, 0.0f, 0.0f, 1.0f);
		//drawLine(51, 150, 180, 150, 0.0f, 0.0f, 1.0f);
		//drawLine(130, 229, 180, 150, 0.0f, 0.0f, 1.0f);  //triangle

		drawLine(300, 150, 370, 100, 1.0f, 0.0f, 1.0f);
		drawLine(230, 100, 300, 150, 1.0f, 0.0f, 1.0f);
		drawLine(230, 100, 260, 40, 1.0f, 0.0f, 1.0f);
		drawLine(260, 40, 340, 40, 1.0f, 0.0f, 1.0f);
		drawLine(340, 40, 370, 100, 1.0f, 0.0f, 1.0f);   //pentagon       (300,100), (370,50), (230,50), (260,10), (340,10)

		drawCircle(500, 100, 60);  //circle

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

