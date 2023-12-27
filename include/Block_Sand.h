#ifndef __BLOCKSAND_H__
#define __BLOCKSAND_H__

#include "Block.h"

class Block_Sand : public Block
{
public:
    Block_Sand() : Block(BlockType::Sand)
    {
        texture_top = "./Minecraft/textures/blocks/sand.png";
        texture_bottom = "./Minecraft/textures/blocks/sand.png";
        texture_left = "./Minecraft/textures/blocks/sand.png";
        texture_right = "./Minecraft/textures/blocks/sand.png";
        texture_front = "./Minecraft/textures/blocks/sand.png";
        texture_back = "./Minecraft/textures/blocks/sand.png";
        image = "./Minecraft/image/Sand.png";
    }
};

#endif