#ifndef __BLOCKDIRT_H__
#define __BLOCKDIRT_H__

#include "Block.h"

class Block_Dirt : public Block
{
public:
    Block_Dirt() : Block(BlockType::Dirt)
    {
        texture_top = "./Minecraft/textures/blocks/dirt.png";
        texture_bottom = "./Minecraft/textures/blocks/dirt.png";
        texture_left = "./Minecraft/textures/blocks/dirt.png";
        texture_right = "./Minecraft/textures/blocks/dirt.png";
        texture_front = "./Minecraft/textures/blocks/dirt.png";
        texture_back = "./Minecraft/textures/blocks/dirt.png";
        image = "./Minecraft/image/Dirt.png";
    }
};

#endif