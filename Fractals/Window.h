#pragma once
#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#include <string>

namespace graphics {	
	// Class to handle the window operations.
	class Window
	{
	private:
		const char* m_Name;
		int m_Width;
		int m_Height;
		GLFWwindow* m_Window;
		//Input* inputHandler;
		bool m_IsClosed;

	public:
		static void windowResize(GLFWwindow* win, int width, int height);
		~Window();
		Window(int width, int height, const char* windowname);
		void clear() const;
		void update();
		bool closed() const;

		// handle input

	private:
		bool init();
		// Keyboard call back function
		static void keyboardCallBack(GLFWwindow* win_, int key_, int scancode_, int action_, int mods_);
	};
}

