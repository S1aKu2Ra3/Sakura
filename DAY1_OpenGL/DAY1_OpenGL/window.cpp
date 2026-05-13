#include<iostream>
#include<glad/glad.h>
#include"window.h"
Window::Window(int width, int height, const char* title) 
{
	if (!glfwInit())
	{
		std::cout << "Failed to intialzie GLFW" << std::endl;
	}
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!window)
	{
		std::cout << "Failed to create window" << std::endl;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}
Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
void Window::clear(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}
void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}