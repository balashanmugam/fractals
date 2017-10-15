#include "Fractal.h"

using namespace std;

GLdouble G_X = 0;
GLdouble G_Y = 0;

int main()
{

	graphics::Window win(1280,720,"Koch's Snowflake Fractal curve");
	graphics::Fractal fractal(1,200,graphics::FractalType::FRACTAL_KOCH_SNOWFLAKE); 

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glClearColor(0.25f, 0.5f, 0.8f, 0.6f);
	glColor3f(0.0f, 1, 0.0f);

	while (win.closed() == false)
	{
		win.clear();
		fractal.draw();
		win.update();
	}
	return 0;

}
