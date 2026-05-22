#include<iostream>
#include<glad/glad.h>
#include"window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)        //窗口大小改变回调函数
{
	std::cout << "Framebuffer resized: " << width << " x " << height << std::endl;

	glViewport(0, 0, width, height);
}


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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glViewport(0, 0, width, height);
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
float Window::getAspectRatio()       //获取窗口宽高比
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	if (height == 0)
	{
		return 1.0f; // 避免除以零
	}
	return static_cast<float>(width) / static_cast<float>(height);
}


