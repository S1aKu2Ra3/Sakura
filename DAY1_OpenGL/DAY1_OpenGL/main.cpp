#include"window.h"
#include"Render.h"
#include"camera.h"

#include<GLFW/glfw3.h>

int main()
{
	Window window(800, 600, "DAY3 Window");   //创建窗口
	Render render;
	render.initTriangle();
	Camera camera;
	float deltaTime = 0.0f;    //每帧时间差
	float lastFrame = 0.0f;      //上次帧的时间
	while ( !window.shouldClose())
	{
		float currentFrame = static_cast<float>(glfwGetTime());     //获取当前时间
		deltaTime = currentFrame - lastFrame;     //计算每帧时间差
		lastFrame = currentFrame;     //更新上次帧的时间
		
		camera.processInput(window, deltaTime);   //处理相机输入

		render.clear(0.2f, 0.3f, 0.3f);    //清屏

	
		render.drawScene(window.getAspectRatio(), camera.getViewMatrix() , camera.getPosition());   //定义相机位置和方向
		
		window.swapBuffers();         //交换缓冲区

		window.pollEvents();       //处理窗口事件
		

	}
	return 0;
}