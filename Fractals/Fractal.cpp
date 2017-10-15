#include "Fractal.h"
#include <math.h>

namespace
{  
	//global functions.
	void glMoveTo(double x, double y);
	void glLineTo(double x, double y);

	GLdouble G_X;
	GLdouble G_Y;
	void glMoveTo(double x, double y)
	{
		G_X = x;
		G_Y = y;
	}

	void glLineTo(double x, double y)
	{
		glBegin(GL_LINES);
		glVertex2d(G_X, G_Y);
		glVertex2d(x, y);
		glEnd();
		glFlush();
		glMoveTo(x, y);

	}
}
// static initializor
int graphics::Fractal::m_iteration = 0;


graphics::Fractal::Fractal(GLint iteration, GLdouble length, FractalType type)
{

	m_iteration = iteration;
	m_length = length;
	m_type = type;
}

graphics::Fractal::~Fractal()
{
}

double graphics::Fractal::iterationLength(int iteration)
{

	// Length calculation
	double length = m_length;
	while (iteration != 1)
	{
		length = length / 3;
		iteration--;
	}
	return length;
	
}

void graphics::Fractal::generateString()
{
	// Production string for a koch curve
	// F draw line
	// - rotate 60 degree right.
	// + rotate 60 degree left.
	const std::string kochSnowFlake = "F-F++F-F++F-F++F-F++F-F++F-F";	
	const std::string realKoch = "F+F--F+F";

    std::string koch = "F-F++F-F";
	
	// choosing the type of curve.
	switch (m_type)
	{
	case FRACTAL_KOCH_SNOWFLAKE:
		m_production = kochSnowFlake;
		break;
	case FRACTAL_KOCH:
		m_production = realKoch;
		koch = realKoch;
		break;

	}
	for (auto i = 0; i < m_iteration - 1; i++)
	{
		for (int j = 0; j < m_production.length(); j++)
		{
			switch (m_production[j])
			{
			// Do nothing.
			case '+':
			case '-':
				break;

			//replace F with Koch's or real Koch's string.
			case 'F':
				m_production.erase(j, 1);
				m_production.insert(j, koch);
				j = j + 8;
				break;

			}
		}
	}

	// for testing purpose.
	//std::cout << m_production << std::endl << m_production.length();;
	
}

void graphics::Fractal::draw()
{
	//Create the string.
	generateString();

	const double PI = 3.14159265;
	//get the length for each iteration
	
	double x = 400;
	double y = 540;
	double angle = 0;
	glMoveTo(x, y);

	double length = iterationLength(m_iteration);
	
	//Read the production string and print the fractal.
	for (auto &c : m_production)
	{
		switch (c)
		{
		case 'F':
			x = x + length * cos(angle * PI / 180.0);
			y = y + length * sin(angle* PI / 180.0);
			glLineTo(x, y);
			break;
		case '+':
			angle -= 60;
			break;
		case '-':
			angle += 60;
			break;
		}
	}

}

void graphics::Fractal::increaseIteration()
{
	m_iteration++;
}

void graphics::Fractal::decreaseIteration()
{
	m_iteration--;
}
