#pragma once
class Render
{
public:
	void initTriangle();
	void clear(float r, float g, float b);
	void drawTriangle(float aspectRatio , float cameraRadius , float cameraAngle);

};