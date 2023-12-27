#ifndef __BLOCKGRASS_H__
#define __BLOCKGRASS_H__

#include "Block.h"

class Block_Grass : public Block
{
public:
    Block_Grass() : Block(BlockType::Grass)
    {
        texture_top = "./Minecraft/textures/blocks/grass_top.png";
        texture_bottom = "./Minecraft/textures/blocks/dirt.png";
        texture_left = "./Minecraft/textures/blocks/grass_side.png";
        texture_right = "./Minecraft/textures/blocks/grass_side.png";
        texture_front = "./Minecraft/textures/blocks/grass_side.png";
        texture_back = "./Minecraft/textures/blocks/grass_side.png";
        image = "./Minecraft/image/Grass.png";
    }
};

#endif