#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Camera.h"
#include "World.h"
#include <SFML/Window.hpp>

class Player
{
public:
    Player()
    {
        camera = new Camera();
    }
    ~Player() {}
    glm::vec3 getFrontBlock(World* world);
    void mouse_callback(sf::Window*window,World*world);
    void place_block(World*world,int type);
    void destroy_block(World*world);

    Camera *camera;
    float handLength = 1.0f;
    bool isReleaseRight = true;
    int currentBlock = 1;
};

#endif