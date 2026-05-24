#pragma once
#include<glm/glm.hpp>
class Render
{
public:
	void initTriangle();
	void clear(float r, float g, float b);
	void drawScene(
		float aspectRatio,
		glm::vec3 cameraPos,
		glm::vec3 cameraTarget,
		glm::vec3 cameraUp
	);

};