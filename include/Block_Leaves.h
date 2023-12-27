#ifndef __BLOCKLEAVES_H__
#define __BLOCKLEAVES_H__

#include "Block.h"

class Block_Leaves : public Block
{
public:
    Block_Leaves() : Block(BlockType::Leaves)
    {
        texture_top = "./Minecraft/textures/blocks/leaves.png";
        texture_bottom = "./Minecraft/textures/blocks/leaves.png";
        texture_left = "./Minecraft/textures/blocks/leaves.png";
        texture_right = "./Minecraft/textures/blocks/leaves.png";
        texture_front = "./Minecraft/textures/blocks/leaves.png";
        texture_back = "./Minecraft/textures/blocks/leaves.png";
        image = "./Minecraft/image/Leaves.png";
    }
};

class Block_Glass : public Block
{
public:
    Block_Glass() : Block(BlockType::Glass)
    {
        texture_top = "./Minecraft/textures/blocks/glass.png";
        texture_bottom = "./Minecraft/textures/blocks/glass.png";
        texture_left = "./Minecraft/textures/blocks/glass.png";
        texture_right = "./Minecraft/textures/blocks/glass.png";
        texture_front = "./Minecraft/textures/blocks/glass.png";
        texture_back = "./Minecraft/textures/blocks/glass.png";
        image = "./Minecraft/image/Glass.png";
    }
};

#endif