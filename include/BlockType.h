#ifndef __BLOCKTYPE_H__
#define __BLOCKTYPE_H__

#include <cstdint>

enum class BlockType : uint8_t
{
    Air = 0,
    Stone = 1,
    Dirt = 2,
    Grass = 3,
    Sand = 4,
    Wood = 5,
    Leaves = 6,
    Tree = 7,
    Cloth_0 = 8,
    Cloth_1 = 9,
    Cloth_2 = 10,
    Cloth_3 = 11,
    Cloth_4 = 12,
    Cloth_5 = 13,
    Cloth_6 = 14,
    Cloth_7 = 15,
    Cloth_8 = 16,
    Cloth_9 = 17,
    Cloth_10 = 18,
    Cloth_11 = 19,
    Cloth_12 = 20,
    Cloth_13 = 21,
    Cloth_14 = 22,
    Cloth_15 = 23,
    Quartzblock = 24,
    Quartzblock_chiseled = 25,
    Quartzblock_lines = 26,
    Pumpkin_face = 27,
    Pumpkin_jack = 28,
    Glass = 29,
    Diamond = 30,
    Emerald = 31,
    Gold = 32,
    Iron = 33,
    Brick = 34,
    Stonebricksmooth = 35,
    Stonebricksmooth_carved = 36,

    Count
};

#endif