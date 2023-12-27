#include "Angel.h"
#include "TriMesh.h"
#include "Camera.h"
#include "MeshPainter.h"
#include "ASSIMP.h"
#include "SFML.h"
#include "World.h"
#include "Player.h"

#include <vector>
#include <string>

Player *player = new Player();
Camera *camera = player->camera;
Light *light = new Light();
MeshPainter *painter = new MeshPainter();
World *world = new World();
std::vector<std::string> musicFiles = {"./Minecraft/sounds/Minecraft.mp3", "./Minecraft/sounds/Sweden.mp3"};
sf::Music music;
sf::Texture centering;

int current_block_index = 0;
int current_music_index = 0;

// 这个用来回收和删除我们创建的物体对象
std::vector<TriMesh *> meshList;

bool playNextMusic()
{
	if (music.openFromFile(musicFiles[current_music_index]))
	{
		music.play();
		current_music_index = (current_music_index + 1) % musicFiles.size();
		return true;
	}
	else
	{
		return false;
	}
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void init()
{
	std::string vshader, fshader;
	// 读取着色器并使用
	vshader = "shaders/vshader.glsl";
	fshader = "shaders/fshader.glsl";

	// 设置光源位置
	light->setTranslation(glm::vec3(0.0, 0.0, 2.0));
	light->setAmbient(glm::vec4(1.0, 1.0, 1.0, 1.0));  // 环境光
	light->setDiffuse(glm::vec4(1.0, 1.0, 1.0, 1.0));  // 漫反射
	light->setSpecular(glm::vec4(1.0, 1.0, 1.0, 1.0)); // 镜面反射
	light->setAttenuation(1.0, 0.045, 0.0075);		   // 衰减系数

	// world->create(100, 100, 255);
	world->load("./save/save1.txt");
	world->world_render(world->width / 2, world->height / 2, 127, vshader, fshader);

	glClearColor(0.5, 0.5, 0.5, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// painter->drawMeshes(light, camera);
	world->render->drawMeshes(light, camera);
}

bool transmode = false;
void translateCamera(sf::Window &window)
{
	float cameraSpeed = 0.025f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		cameraSpeed *= 2.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		transmode = !transmode;

	if (transmode)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			camera->cameraPos += cameraSpeed * camera->cameraFront;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			camera->cameraPos -= cameraSpeed * camera->cameraFront;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			camera->cameraPos -= glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			camera->cameraPos += glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			camera->cameraPos += cameraSpeed * camera->cameraUp;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			camera->cameraPos -= cameraSpeed * camera->cameraUp;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			glm::vec3 front = glm::normalize(glm::vec3(camera->cameraFront.x, 0.0f, camera->cameraFront.z)) * cameraSpeed;
			camera->cameraPos += front;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glm::vec3 back = glm::normalize(glm::vec3(camera->cameraFront.x, 0.0f, camera->cameraFront.z)) * cameraSpeed;
			camera->cameraPos -= back;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			glm::vec3 left = glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
			camera->cameraPos -= glm::vec3(left.x, 0.0f, left.z);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			glm::vec3 right = glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
			camera->cameraPos += glm::vec3(right.x, 0.0f, right.z);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			camera->cameraPos.y += cameraSpeed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			camera->cameraPos.y -= cameraSpeed;
	}
}

float _yaw = -90.0f, _pitch = 0.0f;
void mouse_callback(sf::Window &window)
{
	static float const BOUND = 89.0f;
	static auto lastMousePos = sf::Mouse::getPosition(window);
	auto change = sf::Mouse::getPosition(window) - lastMousePos;

	_yaw += change.x * 0.05f;
	_pitch -= change.y * 0.05f;
	if (_pitch > BOUND)
		_pitch = BOUND;
	if (_pitch < -BOUND)
		_pitch = -BOUND;

	glm::vec3 front;
	front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	front.y = sin(glm::radians(_pitch));
	front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

	camera->cameraFront = glm::normalize(front);

	auto cx = static_cast<int>(window.getSize().x / 2);
	auto cy = static_cast<int>(window.getSize().y / 2);

	sf::Mouse::setPosition({cx, cy}, window);
	lastMousePos = sf::Mouse::getPosition(window);
	player->mouse_callback(&window, world);
}

void cleanData()
{
	// 释放内存
	delete camera;
	camera = NULL;

	delete light;
	light = NULL;

	painter->cleanMeshes();
	world->render->cleanMeshes();
	world->clean();

	delete painter;
	delete world->render;
	delete world;
	painter = NULL;
	world->render = NULL;
	world = NULL;

	for (int i = 0; i < meshList.size(); i++)
	{
		delete meshList[i];
	}
	meshList.clear();
}

bool hadInit = false;
int main(int argc, char **argv)
{
	// 初始化GLFW库，必须是应用程序调用的第一个GLFW函数
	glfwInit();

	// 配置GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// 创建SFML窗口
	sf::RenderWindow sfwindow(sf::VideoMode::getDesktopMode(), "Minecraft", sf::Style::Fullscreen, sf::ContextSettings(32));
	sfwindow.setMouseCursorVisible(false);

	// 初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 启用深度测试
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// 加载音乐
	if (!playNextMusic())
	{
		std::cout << "Failed to load music" << std::endl;
		return -1;
	}

	// 加载准星
	if (!centering.loadFromFile("./MineCraft/centering.png"))
	{
		std::cout << "Failed to load centering.png" << std::endl;
		return -1;
	}
	sf::Sprite centeringSprite;
	centeringSprite.setTexture(centering);
	sf::Vector2u windowSize = sfwindow.getSize();
	centeringSprite.setScale(3, 3);
	centeringSprite.setOrigin(centering.getSize().x / 2, centering.getSize().y / 2);
	centeringSprite.setPosition(windowSize.x / 2, windowSize.y / 2);

	sf::Sprite currentBlockSprite;
	std::vector<std::string> block_image_list;
	world->getBlockImage(block_image_list);
	std::vector<sf::Texture> block_texture_list;
	for (int i = 0; i < block_image_list.size(); i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile(block_image_list[i]))
		{
			std::cout << "Failed to load " << block_image_list[i] << std::endl;
			return -1;
		}
		block_texture_list.push_back(texture);
	}
	currentBlockSprite.setTexture(block_texture_list[current_block_index]);
	currentBlockSprite.setScale(1, 1);
	currentBlockSprite.setOrigin(block_texture_list[current_block_index].getSize().x / 2, block_texture_list[current_block_index].getSize().y / 2);
	// 底部居中
	currentBlockSprite.setPosition(windowSize.x / 2, windowSize.y - currentBlockSprite.getGlobalBounds().height / 2 - 20);

	while (sfwindow.isOpen())
	{
		if (!hadInit)
		{
			hadInit = true;
			init();
		}
		if (music.getStatus() == sf::Music::Stopped)
		{
			if (!playNextMusic())
			{
				std::cout << "Failed to load music" << std::endl;
				return -1;
			}
		}
		display();
		sf::Event event;
		while (sfwindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				sfwindow.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					world->save("./save/save1.txt");
					music.stop();
					sfwindow.close();
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				player->isReleaseRight = true;
			}
			else if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta < 0)
				{
					current_block_index = (current_block_index + 1) % block_image_list.size();
				}
				else
				{
					current_block_index = (current_block_index - 1 + block_image_list.size()) % block_image_list.size();
				}
				player->currentBlock = current_block_index + 1;
				currentBlockSprite.setTexture(block_texture_list[current_block_index]);
			}
		}
		sfwindow.draw(centeringSprite);
		sfwindow.draw(currentBlockSprite);
		sfwindow.resetGLStates();
		glEnable(GL_DEPTH_TEST);
		sfwindow.display();
		mouse_callback(sfwindow);
		translateCamera(sfwindow);
	}
	cleanData();
	return 0;
}