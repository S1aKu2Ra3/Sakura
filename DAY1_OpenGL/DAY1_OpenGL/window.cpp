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
Window::~Window()        //析构函数
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
bool Window::shouldClose()        //是否关闭窗口
{
	return glfwWindowShouldClose(window);
}
void Window::swapBuffers()        //交换缓冲区
{
	glfwSwapBuffers(window);
}
void Window::pollEvents()       //处理窗口事件
{
	glfwPollEvents();
}