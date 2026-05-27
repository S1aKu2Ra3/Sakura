#include"camera.h"
#include"window.h"
#include<GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtc/matrix_transform.hpp>

Camera::Camera() 
{
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	target = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = -90.0f;     //初始偏航角
	pitch = 0.0f;      //初始俯仰角

}

void Camera::processInput(Window& window, float deltaTime) 
{
	float turnspeed = 60.0f * deltaTime;     //旋转速度
	float cameraspeed = 3.0f * deltaTime;      //相机移动速度

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
	updateCameraVectors();

	glm::vec3 cameraRight = glm::normalize(glm::cross(target, up));    //计算相机右向量

	if (window.isKeyPressed(GLFW_KEY_W))
	{
		position += target * cameraspeed;     //按下W键，减小相机半径
	}
	if (window.isKeyPressed(GLFW_KEY_S))
	{
		position -= target * cameraspeed;     //按下S键，增大相机半径
	}

	if (window.isKeyPressed(GLFW_KEY_A))
	{
		position -= cameraRight * cameraspeed;     //按下A键，向左移动相机
	}
	if (window.isKeyPressed(GLFW_KEY_D))
	{
		position += cameraRight * cameraspeed;     //按下D键，向右移动相机
	}
	if (window.isKeyPressed(GLFW_KEY_Q))
	{
		position += up * cameraspeed;        //按下Q键，向上移动相机
	}
	if (window.isKeyPressed(GLFW_KEY_E))
	{
		position -= up * cameraspeed;        //按下E键，向下移动相机
	}



}
void Camera::updateCameraVectors() 
{
	glm::vec3 direction;

	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));          //根据偏航角和俯仰角计算相机前向量的x分量
	direction.y = sin(glm::radians(pitch));                                  // 根据俯仰角计算相机前向量的y分量
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));   // 根据偏航角和俯仰角计算相机前向量的z分量

	target = glm::normalize(direction);                                //更新相机目标向量
}
glm::vec3 Camera::getPosition() const 
{
	return position;
}

glm::vec3 Camera::getTarget() const 
{
	return target;
}

glm::vec3 Camera::getUp() const 
{
	return up;
}
