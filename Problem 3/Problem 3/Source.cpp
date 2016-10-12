#include <GLFW/glfw3.h>
#include <algorithm>
#include <vector>

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

void drawEmptyBox(const int& i_s, const int& j_s, const int& i_e, const int& j_e)  //s=start, e=end
{
	for (int j = j_s; j <= j_e; j++)
		for (int i = i_s; i <= i_e; i++)
		{
			if (j == j_e || j == j_s || i == i_s || i == i_e)
				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
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

		drawPixel(x0 + x, y0 + y, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 + y, y0 + x, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 - y, y0 + x, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 - x, y0 + y, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 - x, y0 - y, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 - y, y0 - x, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 + y, y0 - x, 0.0f, 1.0f, 0.0f);
		drawPixel(x0 + x, y0 - y, 0.0f, 1.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

class Box   // NO PARENT
{
public:
	void draw()
	{
		drawEmptyBox(400, 200, 500, 300);
	}
};

class Circle  // NO PARENT
{
public:
	void draw()
	{
		drawCircle(150, 150, 40);
	}
};

template <class TTT>
class GeometricObject:public GeometricObjectInterface
{
public:
	void draw()
	{
		TTT doing;
		doing.draw();
	}
};

class GeometricObjectInterface
{
public:
	virtual void draw() = 0;
};

// And implement an templatized GeometricObject class.
int main(void)
{
	std::vector<GeometricObjectInterface*> obj_list;
	obj_list.push_back(new GeometricObject<Circle>);
	obj_list.push_back(new GeometricObject<Box>);

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

		for (auto itr : obj_list)
			itr->draw();

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