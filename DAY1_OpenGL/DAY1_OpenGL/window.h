#pragma once
#include<GLFW/glfw3.h>

class Window 
{
public:
	Window(int width, int height, const char* title);
	~Window();

	void clear(float r, float g, float b);
	bool shouldClose();
	void swapBuffers();
private:
	GLFWwindow* window;
};