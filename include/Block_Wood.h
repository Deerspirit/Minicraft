#ifndef __BLOCKWOOD_H__
#define __BLOCKWOOD_H__

#include "Block.h"

class Block_Wood : public Block
{
public:
    Block_Wood() : Block(BlockType::Wood)
    {
        texture_top = "./Minecraft/textures/blocks/wood.png";
        texture_bottom = "./Minecraft/textures/blocks/wood.png";
        texture_left = "./Minecraft/textures/blocks/wood.png";
        texture_right = "./Minecraft/textures/blocks/wood.png";
        texture_front = "./Minecraft/textures/blocks/wood.png";
        texture_back = "./Minecraft/textures/blocks/wood.png";
        image = "./Minecraft/image/Wood.png";
    }
};

#endif