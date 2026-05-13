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
bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}
void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}
void Window::pollEvents()
{
	glfwPollEvents();
}