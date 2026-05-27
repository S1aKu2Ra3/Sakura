#pragma once
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Window;

class Camera 
{
public:
	Camera();

	void processInput(Window& window, float deltaTime);

	glm::mat4 getViewMatrix() const;

	glm::vec3 getPosition() const;
	glm::vec3 getTarget() const;
	glm::vec3 getUp() const;

private:
	void updateCameraVectors();
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;

	float yaw;
	float pitch;

};