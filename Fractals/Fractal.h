#pragma once
#include "Window.h"



namespace graphics {

	// At present, only 2 curves.
	enum FractalType
	{
		FRACTAL_KOCH,
		FRACTAL_KOCH_SNOWFLAKE
	};

	class Fractal
	{

	private:
		// No. of iterations the fractal is going to be processes.
		static GLint m_iteration;

		// Length of the curve initially.
		GLdouble m_length;

		// Production string which is used for drawing.
		std::string m_production;

		// Generates the production string.
		void generateString();

		// type of fractal curve.
		FractalType m_type;

	public:


		// sets the no. of iterations and length,
		Fractal(GLint iteration, GLdouble length, FractalType type = FRACTAL_KOCH_SNOWFLAKE);

		// Currently nothing to destroy.
		~Fractal();

		// Gets the length of the 'F' at the iteration given by the user.
		double iterationLength(int iteration);

		//returns the  Production string.
		std::string getProductionString() {
			return m_production;
		}

		// Returns the iteration.
		GLint getIterationCount() {
			return m_iteration;
		}

		//Makes use of global functions MoveTo and LineTo to draw the fractal curve to the screen.
		void draw();

		// Increase/decrease the fractal iteration.
		static void increaseIteration();
		static void decreaseIteration();


		
	};
}
