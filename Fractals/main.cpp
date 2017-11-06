#include "Fractal.h"

using namespace std;

GLdouble G_X = 0;
GLdouble G_Y = 0;

int main()
{

	graphics::Window win(1280,720,"Koch's Snowflake Fractal curve");


	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glClearColor(0.25f, 0.5f, 0.8f, 0.6f);
	glColor3f(0.0f, 1, 0.0f);

	// Set the starting point.
	graphics::Fractal::instance().setStartingPoint(300, 540);
	while (win.closed() == false)
	{
		win.clear();
		graphics::Fractal::instance().draw();
		win.update();
	}
	return 0;

}
