#include"window.h"
#include<GLFW/glfw3.h>
int main()
{
	Window window(800, 600, "DAY3 Window");
	while ( !window.shouldClose())
	{
		window.clear(0.2f, 0.3f, 0.3f);

		window.swapBuffers();

		glfwPollEvents();
	}
	return 0;
}