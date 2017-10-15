#include "Window.h"
#include "Fractal.h"

namespace graphics {

	

	Window::Window(int width, int height, const char* windowname)
	{
		m_Height = height;
		m_Width = width;
		m_Name = windowname;
		m_IsClosed = false;
		if (init() == false)
			glfwTerminate();
		else // Sets the Co-ordinate axes to the Top left and uses the standard co-ordinate system instead of the normalized one.
		{

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0.0, width, height, 0.0, 1.0, -1.0); 
		}
		glfwSetKeyCallback(m_Window,keyboardCallBack);

	}
	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			perror("Init: ");
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (m_Window == NULL)
		{
			glfwTerminate();
			perror("Window creation : ");
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);

		if (glewInit() != GLEW_OK)
		{
			perror("GLEW init: ");
			return false;
		}

		std::cout << "version  " << glGetString(GL_VERSION) ;
		return true;
	}

	void Window::keyboardCallBack(GLFWwindow* win_, int key_, int scancode_, int action_, int mods_)
	{
		//Fractal f;
		if (key_ == GLFW_KEY_RIGHT && action_ == GLFW_PRESS)
		{
			Fractal::increaseIteration();
			
		}
		else if (key_ == GLFW_KEY_LEFT && action_ == GLFW_PRESS)
		{
			Fractal::decreaseIteration();
		}
	}

	void Window::clear() const
	{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::windowResize(GLFWwindow* win, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

}

