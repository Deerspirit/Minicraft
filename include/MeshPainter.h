#ifndef _MESH_PAINTER_H_
#define _MESH_PAINTER_H_

#include "TriMesh.h"
#include "Angel.h"
#include "stb_image.h"

#include "Camera.h"

#include <vector>
#include <map>

struct openGLObject
{
	// 顶点数组对象
	GLuint vao;
	// 顶点缓存对象
	GLuint vbo;

	// 着色器程序
	GLuint program;
	// 着色器文件
	std::string vshader;
	std::string fshader;
	// 着色器变量
	GLuint pLocation;
	GLuint cLocation;
	GLuint nLocation;
	GLuint tLocation;

	// 纹理
	std::string texture_image;
	GLuint texture;

	// 投影变换变量
	GLuint modelLocation;
	GLuint viewLocation;
	GLuint projectionLocation;

	// 阴影变量
	GLuint shadowLocation;

	GLuint ambientOpen;
	GLuint DiffuseOpen;
	GLuint SpecularOpen;
};

class MeshPainter
{

public:
	MeshPainter();
	~MeshPainter();

	std::vector<std::string> getMeshNames();

	std::vector<TriMesh *> getMeshes();
	std::vector<openGLObject> getOpenGLObj();

	// 读取纹理文件
	static void load_texture_STBImage(const std::string &file_name, GLuint &texture);

	// 传递光线材质数据的
	// void bindLightAndMaterial( int mesh_id, int light_id, Camera* camera );
	void bindLightAndMaterial(TriMesh *mesh, openGLObject &object, Light *light, Camera *camera);

	void bindObjectAndData(TriMesh *mesh, openGLObject &object, const std::string &texture_image, const std::string &vshader, const std::string &fshader);

	// 添加物体
	void addMesh(TriMesh *mesh, const std::string &name, const std::string &texture_image, const std::string &vshader, const std::string &fshader);

	// 删除物体
	void deleteMesh(const std::string &name);

	// 绘制物体
	void drawMesh(TriMesh *mesh, openGLObject &object, Light *light, Camera *camera);

	// 绘制多个物体
	void drawMeshes(Light *light, Camera *camera);

	// 清空数据
	void cleanMeshes();

private:
	std::vector<std::string> mesh_names;
	std::vector<TriMesh *> meshes;
	std::vector<openGLObject> opengl_objects;
};

class TextureLibrary
{
public:
	std::map<std::string, GLuint> textures;

	TextureLibrary()
	{
		textures.clear();
	}

	GLuint getTexture(const std::string &texture_image)
	{
		if (textures.find(texture_image) == textures.end())
		{
			GLuint texture;
			texture = loadTexture(texture_image);
			textures[texture_image] = texture;
		}
		return textures[texture_image];
	}

	GLuint loadTexture(const std::string &file_name)
	{
		GLuint texture;
		glGenTextures(1, &texture);

		// 读取纹理图片，并将其传递给着色器
		int width, height, channels = 0;
		unsigned char *pixels = NULL;
		// 读取图片的时候先翻转一下图片，如果不设置的话显示出来是反过来的图片
		stbi_set_flip_vertically_on_load(true);
		// 读取图片数据
		pixels = stbi_load(file_name.c_str(), &width, &height, &channels, 0);

		// 调整行对齐格式
		if (width * channels % 4 != 0)
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		GLenum format = GL_RGB;
		// 设置通道格式
		switch (channels)
		{
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			format = GL_RGB;
			break;
		}

		// 绑定纹理对象
		glBindTexture(GL_TEXTURE_2D, texture);

		// 指定纹理的放大，缩小滤波，使用线性方式，即当图片放大的时候插值方式
		// 将图片的rgb数据上传给opengl
		glTexImage2D(
			GL_TEXTURE_2D,	  // 指定目标纹理，这个值必须是GL_TEXTURE_2D
			0,				  // 执行细节级别，0是最基本的图像级别，n表示第N级贴图细化级别
			format,			  // 纹理数据的颜色格式(GPU显存)
			width,			  // 宽度。早期的显卡不支持不规则的纹理，则宽度和高度必须是2^n
			height,			  // 高度。早期的显卡不支持不规则的纹理，则宽度和高度必须是2^n
			0,				  // 指定边框的宽度。必须为0
			format,			  // 像素数据的颜色格式(CPU内存)
			GL_UNSIGNED_BYTE, // 指定像素数据的数据类型
			pixels			  // 指定内存中指向图像数据的指针
		);

		// 生成多级渐远纹理，多消耗1/3的显存，较小分辨率时获得更好的效果
		// glGenerateMipmap(GL_TEXTURE_2D);

		// 指定插值方法
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		// 恢复初始对齐格式
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		// 释放图形内存
		stbi_image_free(pixels);
		return texture;
	}
};

#endif