#include"window.h"
#include"Render.h"
#include<GLFW/glfw3.h>
int main()
{
	Window window(800, 600, "DAY3 Window");
	Render render;
	while ( !window.shouldClose())
	{
		render.clear(0.2f, 0.3f, 0.3f);

		window.swapBuffers();

		glfwPollEvents();
	}
	return 0;
}