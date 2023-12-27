#ifndef __BLOCKTREE_H__
#define __BLOCKTREE_H__

#include "Block.h"

class Block_Tree : public Block
{
public:
    Block_Tree() : Block(BlockType::Tree)
    {
        texture_top = "./Minecraft/textures/blocks/tree_top.png";
        texture_bottom = "./Minecraft/textures/blocks/tree_top.png";
        texture_left = "./Minecraft/textures/blocks/tree_side.png";
        texture_right = "./Minecraft/textures/blocks/tree_side.png";
        texture_front = "./Minecraft/textures/blocks/tree_side.png";
        texture_back = "./Minecraft/textures/blocks/tree_side.png";
        image = "./Minecraft/image/Tree.png";
    }
};

#endif