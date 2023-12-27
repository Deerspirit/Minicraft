#ifndef __WORLD_H__
#define __WORLD_H__

#include <iostream>
#include "Block.h"
#include "BlockType.h"
#include "Block_Cloth.h"
#include "Block_Dirt.h"
#include "Block_Grass.h"
#include "Block_Leaves.h"
#include "Block_Sand.h"
#include "Block_Stone.h"
#include "Block_Tree.h"
#include "Block_Wood.h"
#include "MeshPainter.h"

class World
{
public:
    World();
    void create(int width, int height, int depth);
    void load(const std::string &filename);
    void save(const std::string &filename);
    void world_render(int x, int y, int z, const std::string &vshader, const std::string &fshader);
    void block_render(int x, int y, int z);
    void delete_block_render(float x, float y, float z);
    void add_block_render(float x, float y, float z, BlockType type);
    bool is_block(float x, float y, float z);
    void clean();
    void getBlockImage(std::vector<std::string>& image);

    int width, height, depth;
    BlockType ***blocks;
    MeshPainter *render = new MeshPainter();
    std::vector<TriMesh *> BlockmeshList;
    std::vector<std::string> BlockmeshNames;
};

#endif