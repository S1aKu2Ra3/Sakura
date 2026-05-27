#pragma once
#include<glm/glm.hpp>
class Render
{
public:
	void initTriangle();
	void clear(float r, float g, float b);
	void drawScene(
		float aspectRatio,
		const glm::mat4& view
	);

};