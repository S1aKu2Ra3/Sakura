#pragma once
#include<GLFW/glfw3.h>

class Window 
{
public:
	Window(int width, int height, const char* title);
	~Window();
	void pollEvents();
	bool shouldClose();

	void swapBuffers();

	float getAspectRatio();
	bool isKeyPressed(int key);

private:

	GLFWwindow* window;

};
