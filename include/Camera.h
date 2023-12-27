#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Angel.h"

class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(bool isOrtho);

	glm::mat4 lookAt(const glm::vec4 &eye, const glm::vec4 &at, const glm::vec4 &up);

	glm::mat4 ortho(const GLfloat left, const GLfloat right,
					const GLfloat bottom, const GLfloat top,
					const GLfloat zNear, const GLfloat zFar);

	glm::mat4 perspective(const GLfloat fov, const GLfloat aspect,
						  const GLfloat zNear, const GLfloat zFar);

	glm::mat4 frustum(const GLfloat left, const GLfloat right,
					  const GLfloat bottom, const GLfloat top,
					  const GLfloat zNear, const GLfloat zFar);

	// 每次更改相机参数后更新一下相关的数值
	void updateCamera();
	// 处理相机的键盘操作
	void keyboard(int key, int x, int y);
	void mouse_callback(double xpos, double ypos);

	// 模视矩阵
	glm::mat4 viewMatrix;
	glm::mat4 projMatrix;
	// glm::mat4 clipMatrix;

	// 相机位置参数
	float radius = 2.0;
	float rotateAngle = 0.0;
	float upAngle = 0.0;
	glm::vec4 eye;
	glm::vec4 at;
	glm::vec4 up;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
	glm::vec3 cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));

	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
								 glm::vec3(0.0f, 0.0f, 0.0f),
								 glm::vec3(0.0f, 1.0f, 0.0f));

	// 投影参数
	float zNear = 0.1;
	float zFar = 100.0;
	// 透视投影参数
	float fov = 45.0;
	float aspect = 1.77;
	// 正交投影参数
	float scale = 1.5;
};
#endif