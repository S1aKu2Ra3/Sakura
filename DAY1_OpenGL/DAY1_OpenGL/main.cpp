#include"window.h"
#include"Render.h"
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
int main()
{
	Window window(800, 600, "DAY3 Window");   //创建窗口
	Render render;
	render.initTriangle();
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	float yaw = -90.0f;     //初始偏航角
	float pitch = 0.0f;      //初始俯仰角
	float deltaTime = 0.0f;    //每帧时间差
	float lastFrame = 0.0f;      //上次帧的时间
	while ( !window.shouldClose())
	{
		float currentFrame = static_cast<float>(glfwGetTime());     //获取当前时间
		deltaTime = currentFrame - lastFrame;     //计算每帧时间差
		lastFrame = currentFrame;     //更新上次帧的时间
		render.clear(0.2f, 0.3f, 0.3f);    //清屏
		float cameraspeed = 3.0f * deltaTime;      //相机移动速度
		float turnspeed = 60.0f * deltaTime;     //旋转速度

		if (window.isKeyPressed(GLFW_KEY_J))
		{
			yaw -= turnspeed;     //按下J键，向左旋转相机
		}
		if (window.isKeyPressed(GLFW_KEY_L))
		{
			yaw += turnspeed;     //按下L键，向右旋转相机
		}
		if (window.isKeyPressed(GLFW_KEY_I))
		{
			pitch += turnspeed;     //按下I键，向上旋转相机
			if (pitch > 89.0f)     //限制俯仰角，避免翻转
				pitch = 89.0f;
		}
		if (window.isKeyPressed(GLFW_KEY_K))
		{
			pitch -= turnspeed;     //按下K键，向下旋转相机
			if (pitch < -89.0f)     //限制俯仰角，避免翻转
				pitch = -89.0f;
		}
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraTarget = glm::normalize(front);     //更新相机目标向量
		render.drawScene(window.getAspectRatio(), cameraPos, cameraTarget, cameraUp);   //定义相机位置和方向
		glm::vec3 cameraRight = glm::normalize(glm::cross(cameraTarget, cameraUp));


		if (window.isKeyPressed(GLFW_KEY_W))
		{
			cameraPos += cameraTarget * cameraspeed;     //按下W键，减小相机半径
		}
		if (window.isKeyPressed(GLFW_KEY_S))
		{
			cameraPos -= cameraTarget * cameraspeed;     //按下S键，增大相机半径
		}
		
		if (window.isKeyPressed(GLFW_KEY_A))
		{
			cameraPos -= cameraRight * cameraspeed;     //按下A键，向左移动相机
		}
		if (window.isKeyPressed(GLFW_KEY_D))
		{
			cameraPos += cameraRight * cameraspeed;     //按下D键，向右移动相机
		}
		if (window.isKeyPressed(GLFW_KEY_Q))
		{
			cameraPos += cameraUp * cameraspeed;        //按下Q键，向上移动相机
		}
		if (window.isKeyPressed(GLFW_KEY_E))
		{
			cameraPos -= cameraUp * cameraspeed;        //按下E键，向下移动相机
		}
		
		

		window.swapBuffers();         //交换缓冲区

		window.pollEvents();       //处理窗口事件
		

	}
	return 0;
}