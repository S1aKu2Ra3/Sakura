#include"window.h"
#include"Render.h"
#include<GLFW/glfw3.h>
int main()
{
	Window window(800, 600, "DAY3 Window");   //创建窗口
	Render render;
	render.initTriangle();
	while ( !window.shouldClose())
	{
		render.clear(0.2f, 0.3f, 0.3f);    //清屏

		render.drawTriangle();

		window.swapBuffers();         //交换缓冲区

		window.pollEvents();       //处理窗口事件

	}
	return 0;
}