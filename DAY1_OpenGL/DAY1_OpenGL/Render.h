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
	void setAmbientStrength(float value);
	void setSpecularStrength(float value);
	void setShininess(float value);

		
	void setRenderMode(int mode);
	int getRenderMode() const;
private:
	int renderMode = 1;     //默认渲染模式
	float ambientStrength = 0.1f;     //环境光强度
	float specularStrength = 0.5f;     //镜面反射强度
	float shininess = 64.0f;     //高光集中度
};