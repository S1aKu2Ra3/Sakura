#include<glad/glad.h>
#include"Render.h"
#include"camera.h"
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
	// positions           // colors          // tex coords     //Normal
	// back face
	-0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 0.0f,   0.0f , 0.0f , -1.0f,
	 0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 0.0f,   0.0f , 0.0f , -1.0f,
	 0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 1.0f,   0.0f , 0.0f , -1.0f,
	 0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  1.0f, 1.0f,   0.0f , 0.0f , -1.0f,
	-0.5f,  0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 1.0f,   0.0f , 0.0f , -1.0f,
	-0.5f, -0.5f, -0.5f,   0.2f, 0.4f, 1.0f,  0.0f, 0.0f,   0.0f , 0.0f , -1.0f,

	// front face
	-0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 0.0f,   0.0f , 0.0f , 1.0f,
	 0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 0.0f,   0.0f , 0.0f , 1.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 1.0f,   0.0f , 0.0f , 1.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  1.0f, 1.0f,   0.0f , 0.0f , 1.0f,
	-0.5f,  0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 1.0f,   0.0f , 0.0f , 1.0f,
	-0.5f, -0.5f,  0.5f,   1.0f, 0.4f, 0.2f,  0.0f, 0.0f,   0.0f , 0.0f , 1.0f,

	// left face
	-0.5f,  0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 0.0f,  -1.0f , 0.0f , 0.0f,
	-0.5f,  0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 1.0f,  -1.0f , 0.0f , 0.0f,
	-0.5f, -0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 1.0f,  -1.0f , 0.0f , 0.0f,
	-0.5f, -0.5f, -0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 1.0f,  -1.0f , 0.0f , 0.0f,
	-0.5f, -0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  0.0f, 0.0f,  -1.0f , 0.0f , 0.0f,
	-0.5f,  0.5f,  0.5f,   0.4f, 1.0f, 0.4f,  1.0f, 0.0f,  -1.0f , 0.0f , 0.0f,

	// right face
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 0.0f,   1.0f , 0.0f , 0.0f,
	 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 1.0f,   1.0f , 0.0f , 0.0f,
	 0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 1.0f,   1.0f , 0.0f , 0.0f,
	 0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 1.0f,   1.0f , 0.0f , 0.0f,
	 0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  0.0f, 0.0f,   1.0f , 0.0f , 0.0f,
	 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.3f,  1.0f, 0.0f,   1.0f , 0.0f , 0.0f,

	 // bottom face
	 -0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f,
	  0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 1.0f,  0.0f, -1.0f, 0.0f,
	  0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
	  0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
	 -0.5f, -0.5f,  0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 0.0f,  0.0f, -1.0f, 0.0f,
	 -0.5f, -0.5f, -0.5f,   0.3f, 1.0f, 1.0f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f,

	 // top face
	 -0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 1.0f,  0.0f ,1.0f , 0.0f,
	  0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 1.0f,  0.0f ,1.0f , 0.0f,
	  0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 0.0f,  0.0f ,1.0f , 0.0f,
	  0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  1.0f, 0.0f,  0.0f ,1.0f , 0.0f,
	 -0.5f,  0.5f,  0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 0.0f,  0.0f ,1.0f , 0.0f,
	 -0.5f,  0.5f, -0.5f,   1.0f, 0.3f, 1.0f,  0.0f, 1.0f,  0.0f ,1.0f , 0.0f
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
"layout (location = 3) in vec3 aNormal;\n"
"out vec3 ourColor;\n"
"out vec2 TexCoord;\n"
"out vec3 Normal;\n"
"out vec3 FragPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"   FragPos = vec3(model * vec4(aPos, 1.0));\n"
"   Normal = mat3(transpose(inverse(model))) * aNormal;\n"
"   gl_Position =projection * view * model * vec4(aPos, 1.0);\n"
"	ourColor = aColor;\n"
"	TexCoord = aTexCoord;\n"
"}";

const char* fragmentShaderSource =               //片段着色器源码
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"
"in vec3 Normal;\n"
"in vec3 FragPos;\n"
"uniform sampler2D diffuseMap;\n"
"uniform float mixValue;\n"
"uniform float ambientStrength;\n"
"uniform float specularStrength;\n"
"uniform float shininess;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 lightColor;\n"
"uniform bool isLight;\n"
"uniform vec3 viewPos;\n"
"uniform int renderMode;\n"
"void main()\n"
"{\n"
"if(isLight)\n"
"{\n"
"FragColor = vec4(lightColor, 1.0);\n"
"return;\n"
"}\n"
"if(renderMode==2)\n"
"{\n"
" vec3 debugNormal = normalize(Normal);\n"
" FragColor = vec4(debugNormal * 0.5 + 0.5, 1.0);\n"
"return;\n"
"}\n"
"if(renderMode==3)\n"
"{\n"
"FragColor = vec4(TexCoord , 0.0 , 1.0);\n"
"return;\n"
"}\n"
"if(renderMode==4)\n"
"{\n"
"vec3 debugPos = FragPos * 0.1 + 0.5;\n"
"FragColor = vec4(debugPos , 1.0);\n"
"return;\n"
"}\n"
"vec3 norm = normalize(Normal);\n"
"vec3 lightDir = normalize(vec3(lightPos) - FragPos);\n"
"float diff = max(dot(norm, lightDir), 0.0);\n"
"if(renderMode==5)\n"
"{\n"
" FragColor = vec4(vec3(diff) , 1.0);\n"
"return;\n"
"}\n"
"vec3 ambient = ambientStrength * lightColor;\n"
"vec3 diffuse = diff * vec3(lightColor);\n"
"vec3 viewDir = normalize(vec3(viewPos) - FragPos);\n"
"vec3 halfwayDir = normalize(lightDir + viewDir);\n"
"float spec = pow(max(dot(norm, halfwayDir), 0.0), shininess);\n"    //高光集中度
"vec3 specular = specularStrength * spec * lightColor;\n"
"if(renderMode==6)\n"
"{\n"
"FragColor = vec4(vec3(spec),1.0);\n"
"return;\n"
"}\n"
"vec4 texColor = texture(diffuseMap, TexCoord);\n"
"vec3 baseColor = mix(texColor.rgb, texColor.rgb * ourColor , mixValue);\n"
"vec3 result = (ambient + diffuse + specular) * baseColor;\n"
"FragColor = vec4(result , 1.0);\n"      
"}";


unsigned int shaderProgram;     //完整（全局函数）
unsigned int VBO;    //无符号数（OpenGL多为编号）     存储数据
unsigned int VAO;    //解释数据，记录数据格式
unsigned int EBO;    //索引数据
unsigned int diffuseTexture;    //纹理对象

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
	glGenTextures(1, &diffuseTexture);        //创建纹理对象并保留地址

	glBindVertexArray(VAO);           //绑定

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);        //绑定索引缓冲区对象到目标

	glBindBuffer(GL_ARRAY_BUFFER, VBO);          //绑定缓冲区对象到目标

	glBindTexture(GL_TEXTURE_2D, diffuseTexture);        //绑定纹理对象到目标


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);      //写入数据  （写入区域，写入大小，写入对象，相关操作）
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);      //写入数据  （写入区域，写入大小，写入对象，相关操作）

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(0);          //启用索引
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(1);          //启用索引
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(2);          //启用索引
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));   //定义顶点属性的布局（索引属性，vec数量，分量类型，数据是否初始化，分量步长，偏移量）
	glEnableVertexAttribArray(3);          //启用索引
	
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

void Render::setRenderMode(int mode)     //设置渲染模式
{
	renderMode = mode;
}
void Render::setAmbientStrength(float value)     //设置环境光强度
{
	ambientStrength = value;
}

void Render::setSpecularStrength(float value)     //设置镜面反射强度
{
	specularStrength = value;
}

void Render::setShininess(float value)     //设置高光集中度
{
	shininess = value;
}

int Render::getRenderMode() const     //获取渲染模式
{
	return renderMode;
}

void Render::drawScene(
	float aspectRatio,
	const glm::mat4& view,
	const glm::vec3& viewPos
)

{
	glUseProgram(shaderProgram);  

	int diffuseMapLocation = glGetUniformLocation(shaderProgram, "diffuseMap");
	glUniform1f(diffuseMapLocation, 0);

	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);     //光源位置
	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);     //光源颜色

	int lightPosLocation = glGetUniformLocation(shaderProgram, "lightPos");
	glUniform3f(lightPosLocation, lightPos.x, lightPos.y, lightPos.z);     //设置光源位置

	int lightColorLocation = glGetUniformLocation(shaderProgram, "lightColor");
	glUniform3f(lightColorLocation, lightColor.x, lightColor.y, lightColor.z);     //设置光源颜色

	int ambientStrengthLocation = glGetUniformLocation(shaderProgram, "ambientStrength");
	glUniform1f(ambientStrengthLocation, ambientStrength);     //设置环境光强度

	int specularStrengthLocation = glGetUniformLocation(shaderProgram, "specularStrength");
	glUniform1f(specularStrengthLocation, specularStrength);     //设置镜面反射强度

	int shininessLocation = glGetUniformLocation(shaderProgram, "shininess");
	glUniform1f(shininessLocation, shininess);     //设置高光集中度

	int viewPosLocation = glGetUniformLocation(shaderProgram, "viewPos");
	glUniform3f(viewPosLocation, viewPos.x, viewPos.y, viewPos.z);     //设置观察位置

	int viewLocation = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));

	int isLightLocation = glGetUniformLocation(shaderProgram, "isLight");
	int renderModeLocation = glGetUniformLocation(shaderProgram, "renderMode");
	glUniform1i(renderModeLocation, renderMode);     //设置渲染模式


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
	
	int mixlocation = glGetUniformLocation(shaderProgram, "mixValue");     //获取uniform变量位置

	float mixvalue = (sin(glfwGetTime()) + 1.0f) / 2.0f;     //计算混合值，范围在0到1之间

	

	glUniform1f(mixlocation, mixvalue);     //设置uniform变量值
	glBindVertexArray(VAO);                //绑定顶点数据
	glActiveTexture(GL_TEXTURE0);        //激活纹理单元0
	glBindTexture(GL_TEXTURE_2D, diffuseTexture);        //绑定纹理对象到目标
	glUniform1i(isLightLocation, false);     //设置isLight为false，渲染普通物体

	for (int i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle) + (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glUniform1i(isLightLocation, true);     //设置isLight为true，渲染光源

	glm::mat4 lightModel = glm::mat4(1.0f);

	lightModel = glm::translate(lightModel, lightPos);

	lightModel = glm::scale(lightModel, glm::vec3(0.2f)); // 将光源缩小为原来的20%

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(lightModel));    // 设置光源的模型矩阵

	glDrawArrays(GL_TRIANGLES, 0, 36);    // 绘制光源（使用相同的顶点数据，但可以使用不同的着色器来渲染为一个小的立方体）
}