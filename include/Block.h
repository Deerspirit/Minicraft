#ifndef __Block_H__
#define __Block_H__

#include "BlockType.h"
#include "MeshPainter.h"
#include "TriMesh.h"

const float L = 0.05f;
// namespace block
// {
//     float Length = 0.5f;
// }
// 立方体图例
//     0 ____________1
//     /            /|   +y
//  3 /___________2/ |    |
//   |             | |    |
//   |             | |    ----->+x
//   |  4          | |5  /
//   |             | /  /
//  7|_____________|/6 /+z
const glm::vec3 block_vertices[8] = {
    glm::vec3(-L, L, -L),
    glm::vec3(L, L, -L),
    glm::vec3(L, L, L),
    glm::vec3(-L, L, L),
    glm::vec3(-L, -L, -L),
    glm::vec3(L, -L, -L),
    glm::vec3(L, -L, L),
    glm::vec3(-L, -L, L)};

const glm::vec3 axis[6] = {
    glm::vec3(1, 0, 0),  // x
    glm::vec3(0, 1, 0),  // y
    glm::vec3(0, 0, 1),  // z
    glm::vec3(-1, 0, 0), //-x
    glm::vec3(0, -1, 0), //-y
    glm::vec3(0, 0, -1)  //-z
};

class Block
{
public:
    BlockType type;
    float Length = L;
    std::string texture_top;
    std::string texture_bottom;
    std::string texture_left;
    std::string texture_right;
    std::string texture_front;
    std::string texture_back;
    std::string image;
    
    Block() : type(BlockType::Air) {}
    Block(BlockType type) : type(type) {}
    BlockType getType() const { return type; }
};

#endif