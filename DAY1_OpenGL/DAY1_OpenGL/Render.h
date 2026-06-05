#pragma once
#include<glm/glm.hpp>
class Render
{
public:
	void initTriangle();
	void clear(float r, float g, float b);
	void drawScene(
		float aspectRatio,
		const glm::mat4& view,
		const glm::vec3& viewPos
		
	);
	void setRenderMode(int mode);
	int getRenderMode() const;
private:
	int renderMode = 1;     //默认渲染模式
};