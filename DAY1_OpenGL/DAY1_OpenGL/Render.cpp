#include<glad/glad.h>
#include"Render.h"
#include<iostream>

float vertices[] =
{
	-0.5f , -0.5f , 0.0f,
	 0.5f , -0.5f , 0.0f,
	 0.0f , 0.5f ,0.0f

};

const char* VertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x , aPos.y , aPos.z , 1.0);\n"
"}";

const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f , 0.5f , 0.2f , 1.0f);\n"
"}";


unsigned int shaderProgram;     //完整（全局函数）
unsigned int VBO;    //无符号数（OpenGL多为编号）     存储数据
unsigned int VAO;    //解释数据，记录数据格式

void Render::initTriangle()
{

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

	glBindVertexArray(VAO);           //绑定

	glBindBuffer(GL_ARRAY_BUFFER, VBO);          //绑定缓冲区对象到目标

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);      //写入数据  （写入区域，写入大小，写入对象，相关操作）

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(0);          //启用索引
}

void Render::clear(float r, float g, float b)  //清屏颜色设置
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}


void Render::drawTriangle()           //执行画三角操作
{
	glUseProgram(shaderProgram);         
	glBindVertexArray(VAO);                //绑定顶点数据
	glDrawArrays(GL_TRIANGLES, 0, 3);           //绘制（画三角，从顶点0开始，共绘制三个顶点）
}