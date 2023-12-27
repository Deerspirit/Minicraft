#ifndef __BLOCKSTONE_H__
#define __BLOCKSTONE_H__

#include "Block.h"

class Block_Stone : public Block
{
public:
    Block_Stone() : Block(BlockType::Stone)
    {
        texture_top = "./Minecraft/textures/blocks/stone.png";
        texture_bottom = "./Minecraft/textures/blocks/stone.png";
        texture_left = "./Minecraft/textures/blocks/stone.png";
        texture_right = "./Minecraft/textures/blocks/stone.png";
        texture_front = "./Minecraft/textures/blocks/stone.png";
        texture_back = "./Minecraft/textures/blocks/stone.png";
        image = "./Minecraft/image/Stone.png";
    }
};

class Block_Quartzblock : public Block
{
public:
    Block_Quartzblock() : Block(BlockType::Quartzblock)
    {
        texture_top = "./Minecraft/textures/blocks/quartzblock_top.png";
        texture_bottom = "./Minecraft/textures/blocks/quartzblock_bottom.png";
        texture_left = "./Minecraft/textures/blocks/quartzblock_side.png";
        texture_right = "./Minecraft/textures/blocks/quartzblock_side.png";
        texture_front = "./Minecraft/textures/blocks/quartzblock_side.png";
        texture_back = "./Minecraft/textures/blocks/quartzblock_side.png";
        image = "./Minecraft/image/Quartz.png";
    }
};

class Block_Quartzblock_chiseled : public Block
{
public:
    Block_Quartzblock_chiseled() : Block(BlockType::Quartzblock_chiseled)
    {
        texture_top = "./Minecraft/textures/blocks/quartzblock_chiseled_top.png";
        texture_bottom = "./Minecraft/textures/blocks/quartzblock_chiseled_top.png";
        texture_left = "./Minecraft/textures/blocks/quartzblock_chiseled.png";
        texture_right = "./Minecraft/textures/blocks/quartzblock_chiseled.png";
        texture_front = "./Minecraft/textures/blocks/quartzblock_chiseled.png";
        texture_back = "./Minecraft/textures/blocks/quartzblock_chiseled.png";
        image = "./Minecraft/image/Quartz_Chiseled.png";
    }
};

class Block_Quartzblock_lines : public Block
{
public:
    Block_Quartzblock_lines() : Block(BlockType::Quartzblock_lines)
    {
        texture_top = "./Minecraft/textures/blocks/quartzblock_lines_top.png";
        texture_bottom = "./Minecraft/textures/blocks/quartzblock_lines_top.png";
        texture_left = "./Minecraft/textures/blocks/quartzblock_lines.png";
        texture_right = "./Minecraft/textures/blocks/quartzblock_lines.png";
        texture_front = "./Minecraft/textures/blocks/quartzblock_lines.png";
        texture_back = "./Minecraft/textures/blocks/quartzblock_lines.png";
        image = "./Minecraft/image/Quartz_Lines.png";
    }
};

class Block_Pumpkin_face : public Block
{
public:
    Block_Pumpkin_face() : Block(BlockType::Pumpkin_face)
    {
        texture_top = "./Minecraft/textures/blocks/pumpkin_top.png";
        texture_bottom = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_left = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_right = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_front = "./Minecraft/textures/blocks/pumpkin_face.png";
        texture_back = "./Minecraft/textures/blocks/pumpkin_side.png";
        image = "./Minecraft/image/Pumpkin_Face.png";
    }
};

class Block_Pumpkin_jack : public Block
{
public:
    Block_Pumpkin_jack() : Block(BlockType::Pumpkin_jack)
    {
        texture_top = "./Minecraft/textures/blocks/pumpkin_top.png";
        texture_bottom = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_left = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_right = "./Minecraft/textures/blocks/pumpkin_side.png";
        texture_front = "./Minecraft/textures/blocks/pumpkin_jack.png";
        texture_back = "./Minecraft/textures/blocks/pumpkin_side.png";
        image = "./Minecraft/image/Pumpkin_Jack.png";
    }
};

class Block_Diamond : public Block
{
public:
    Block_Diamond() : Block(BlockType::Diamond)
    {
        texture_top = "./Minecraft/textures/blocks/blockDiamond.png";
        texture_bottom = "./Minecraft/textures/blocks/blockDiamond.png";
        texture_left = "./Minecraft/textures/blocks/blockDiamond.png";
        texture_right = "./Minecraft/textures/blocks/blockDiamond.png";
        texture_front = "./Minecraft/textures/blocks/blockDiamond.png";
        texture_back = "./Minecraft/textures/blocks/blockDiamond.png";
        image = "./Minecraft/image/Diamond.png";
    }
};

class Block_Emerald : public Block
{
public:
    Block_Emerald() : Block(BlockType::Emerald)
    {
        texture_top = "./Minecraft/textures/blocks/blockEmerald.png";
        texture_bottom = "./Minecraft/textures/blocks/blockEmerald.png";
        texture_left = "./Minecraft/textures/blocks/blockEmerald.png";
        texture_right = "./Minecraft/textures/blocks/blockEmerald.png";
        texture_front = "./Minecraft/textures/blocks/blockEmerald.png";
        texture_back = "./Minecraft/textures/blocks/blockEmerald.png";
        image = "./Minecraft/image/Emerald.png";
    }
};

class Block_Gold : public Block
{
public:
    Block_Gold() : Block(BlockType::Gold)
    {
        texture_top = "./Minecraft/textures/blocks/blockGold.png";
        texture_bottom = "./Minecraft/textures/blocks/blockGold.png";
        texture_left = "./Minecraft/textures/blocks/blockGold.png";
        texture_right = "./Minecraft/textures/blocks/blockGold.png";
        texture_front = "./Minecraft/textures/blocks/blockGold.png";
        texture_back = "./Minecraft/textures/blocks/blockGold.png";
        image = "./Minecraft/image/Gold.png";
    }
};

class Block_Iron : public Block
{
public:
    Block_Iron() : Block(BlockType::Iron)
    {
        texture_top = "./Minecraft/textures/blocks/blockIron.png";
        texture_bottom = "./Minecraft/textures/blocks/blockIron.png";
        texture_left = "./Minecraft/textures/blocks/blockIron.png";
        texture_right = "./Minecraft/textures/blocks/blockIron.png";
        texture_front = "./Minecraft/textures/blocks/blockIron.png";
        texture_back = "./Minecraft/textures/blocks/blockIron.png";
        image = "./Minecraft/image/Iron.png";
    }
};

class Block_Brick : public Block
{
public:
    Block_Brick() : Block(BlockType::Brick)
    {
        texture_top = "./Minecraft/textures/blocks/brick.png";
        texture_bottom = "./Minecraft/textures/blocks/brick.png";
        texture_left = "./Minecraft/textures/blocks/brick.png";
        texture_right = "./Minecraft/textures/blocks/brick.png";
        texture_front = "./Minecraft/textures/blocks/brick.png";
        texture_back = "./Minecraft/textures/blocks/brick.png";
        image = "./Minecraft/image/Brick.png";
    }
};

class Block_Stonebricksmooth : public Block
{
public:
    Block_Stonebricksmooth() : Block(BlockType::Stonebricksmooth)
    {
        texture_top = "./Minecraft/textures/blocks/stonebricksmooth.png";
        texture_bottom = "./Minecraft/textures/blocks/stonebricksmooth.png";
        texture_left = "./Minecraft/textures/blocks/stonebricksmooth.png";
        texture_right = "./Minecraft/textures/blocks/stonebricksmooth.png";
        texture_front = "./Minecraft/textures/blocks/stonebricksmooth.png";
        texture_back = "./Minecraft/textures/blocks/stonebricksmooth.png";
        image = "./Minecraft/image/StoneBrickSmooth.png";
    }
};

class Block_Stonebricksmooth_carved : public Block
{
public:
    Block_Stonebricksmooth_carved() : Block(BlockType::Stonebricksmooth_carved)
    {
        texture_top = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        texture_bottom = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        texture_left = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        texture_right = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        texture_front = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        texture_back = "./Minecraft/textures/blocks/stonebricksmooth_carved.png";
        image = "./Minecraft/image/StoneBrickSmooth_Carved.png";
    }
};

#endif