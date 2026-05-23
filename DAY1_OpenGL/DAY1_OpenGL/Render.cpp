#include<glad/glad.h>
#include"Render.h"
#include<iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include<GLFW/glfw3.h>
#include<cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float vertices[] =
{
	// positions           // colors          // tex coords
	// back face
	-0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 0.0f,

	// front face
	-0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 0.0f,

	// left face
	-0.5f,  0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 0.0f,

	// right face
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 0.0f,

	 // bottom face
	 -0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 1.0f,
	  0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 1.0f,
	  0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 0.0f,
	  0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 0.0f,
	 -0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 0.0f,
	 -0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 1.0f,

	 // top face
	 -0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 1.0f,
	  0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 1.0f,
	  0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 0.0f,
	  0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 0.0f,
	 -0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 0.0f,
	 -0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 1.0f
};
glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};
unsigned int indices[] =      //缓冲对象（EBO）  索引数据
{
	0 , 1 , 3 ,
	1 , 2 , 3 
};

const char* VertexShaderSource =                       //顶点着色器源码
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"out vec3 ourColor;\n"
"out vec2 TexCoord;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    gl_Position =projection * view * model * vec4(aPos, 1.0);\n"
"	ourColor = aColor;\n"
"	TexCoord = aTexCoord;\n"
"}";

const char* fragmentShaderSource =               //片段着色器源码
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D ourTexture;\n"
"uniform float mixValue;\n"
"void main()\n"
"{\n"
"vec4 texColor = texture(ourTexture, TexCoord);\n"
"vec4 vertexColor = vec4(ourColor, 1.0);\n"
"   FragColor = mix (texColor , texColor * vertexColor , mixValue );\n"    //纹理*顶点
"}";


unsigned int shaderProgram;     //完整（全局函数）
unsigned int VBO;    //无符号数（OpenGL多为编号）     存储数据
unsigned int VAO;    //解释数据，记录数据格式
unsigned int EBO;    //索引数据
unsigned int texture;    //纹理对象

void Render::initTriangle()
{

	glEnable(GL_DEPTH_TEST);

	unsigned int vertexShader;             //顶点（用后删除）
	unsigned int fragmentShader;           //像素

	vertexShader = glCreateShader(GL_VERTEX_SHADER);                                       //顶点shader完整附带验证流程
	glShaderSource(vertexShader, 1, &VertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "Vertex Shader compilation failed:\n" << infoLog << std::endl;
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);                   //像素shader完整附带验证流程

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);    //nullptr   自己判断在哪里结束，读到\0
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "Fragment Shader compilation failed:\n" << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram();                                         //打包vertex和fragment，真正执行者附验证流程
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
		std::cout << "Shader Program linking failed:\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);                      //清理中间资源
	glDeleteShader(fragmentShader);                   //清理中间资源

	glGenVertexArrays(1, &VAO);        //创建解释并保留地址
	glGenBuffers(1, &VBO);            //创建缓存并保留地址
	glGenBuffers(1, &EBO);            //创建索引缓存并保留地址
	glGenTextures(1, &texture);        //创建纹理对象并保留地址

	glBindVertexArray(VAO);           //绑定

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);        //绑定索引缓冲区对象到目标

	glBindBuffer(GL_ARRAY_BUFFER, VBO);          //绑定缓冲区对象到目标

	glBindTexture(GL_TEXTURE_2D, texture);        //绑定纹理对象到目标


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);      //写入数据  （写入区域，写入大小，写入对象，相关操作）
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);      //写入数据  （写入区域，写入大小，写入对象，相关操作）

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(0);          //启用索引
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(1);          //启用索引
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(2);          //启用索引
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width;
	int height;
	int nrChannels;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

	if (data)
	{	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);
}

void Render::clear(float r, float g, float b)  //清屏颜色设置
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Render::drawTriangle(float aspectRatio)           //执行画三角操作
{

	float timevalue = glfwGetTime();     //获取时间

	glUseProgram(shaderProgram);  

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(
		model,
		glm::vec3(0.5f, 0.3f, 0.0f)
	);

	float scaleValue = (sin(glfwGetTime()) + 1.0f) / 2.0f;
	scaleValue = scaleValue * 0.5f + 0.5f;     //缩放值范围在0.5到1之间

	model = glm::scale(
		model,
		glm::vec3(scaleValue, scaleValue, scaleValue)
	);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(
		view,
		glm::vec3(0.0f, 0.0f, -3.0f)
	);

	int viewLocation = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(
		glm::radians(30.0f),
		aspectRatio,
		0.1f,
		100.0f
	);

	int projectionLocation = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

	int modelLocation = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	
	int mixlocation = glGetUniformLocation(shaderProgram, "mixValue");     //获取uniform变量位置

	float mixvalue = (sin(glfwGetTime()) + 1.0f) / 2.0f;     //计算混合值，范围在0到1之间

	

	glUniform1f(mixlocation, mixvalue);     //设置uniform变量值
	glBindVertexArray(VAO);                //绑定顶点数据
	glBindTexture(GL_TEXTURE_2D, texture);        //绑定纹理对象到目标
	for (int i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle) + (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}