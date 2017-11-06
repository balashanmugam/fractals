#pragma once
#include "Window.h"



namespace graphics {

	// At present, only 2 curves.
	enum FractalType
	{
		FRACTAL_KOCH,
		FRACTAL_KOCH_SNOWFLAKE
	};

	// A singleton class. Only one instance of the Fractal can be created.

	class Fractal
	{

	private:

		// Starting point of the point
		GLdouble m_x;
		GLdouble m_y;

		// No. of iterations the fractal is going to be processes.
		static GLint m_iteration;

		// Length of the curve initially.
		GLdouble m_length;

		// Production string which is used for drawing.
		std::string m_production;

		// Generates the production string.
		void generateString();

		// type of fractal curve.
		static FractalType m_type;

		// private constructor.
		Fractal() { m_length = 400; } //m_type = FractalType::FRACTAL_KOCH_SNOWFLAKE; };

	public:
		static Fractal& instance()
		{
			static Fractal singleton;
			return singleton;
		}

		// Currently nothing to destroy.
		~Fractal();

		void setStartingPoint(double x_, double y_);

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

		// go to next iteration
		static void increaseIteration();

		// Go back an iteration.
		static void decreaseIteration();

	
		//set fractal type
		static void setFractalType();


		
	};
}
