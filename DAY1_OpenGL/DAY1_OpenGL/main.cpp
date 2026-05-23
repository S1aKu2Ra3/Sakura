#include"window.h"
#include"Render.h"
#include<GLFW/glfw3.h>
int main()
{
	float cameraRadius = 10.0f;     //相机半径
	float cameraAngle = 0.0f;       //相机角度
	Window window(800, 600, "DAY3 Window");   //创建窗口
	Render render;
	render.initTriangle();
	while ( !window.shouldClose())
	{
		render.clear(0.2f, 0.3f, 0.3f);    //清屏

		if (window.isKeyPressed(GLFW_KEY_W))
		{
			cameraRadius -= 0.05f;     //按下W键，减小相机半径
		}
		if (window.isKeyPressed(GLFW_KEY_S))
		{
			cameraRadius += 0.05f;     //按下S键，增大相机半径
		}
		if (cameraRadius < 2.0f)     //限制相机半径的最小值
		{
			cameraRadius = 2.0f;
		}
		if (cameraRadius > 20.0f)    //限制相机半径的最大值
		{
			cameraRadius = 20.0f;
		}
		if (window.isKeyPressed(GLFW_KEY_A))
		{
			cameraAngle -= 0.02f;      //按下A键，增加相机角度
		}
		if (window.isKeyPressed(GLFW_KEY_D))
		{
			cameraAngle += 0.02f;      //按下D键，减少相机角度
		}

		render.drawTriangle(window.getAspectRatio(), cameraRadius , cameraAngle);

		window.swapBuffers();         //交换缓冲区

		window.pollEvents();       //处理窗口事件
		

	}
	return 0;
}