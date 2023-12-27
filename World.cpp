#include "World.h"
#include <iostream>
#include <fstream>

const glm::vec4 zero(0.0, 0.0, 0.0, 0.0);
const glm::vec3 x90(90.0, 0.0, 0.0);
const glm::vec4 Ka(0.8, 0.8, 0.8, 0.8);
const glm::vec4 Kd(0.0, 0.0, 0.0, 0.0);
const glm::vec4 Ks(0.0, 0.0, 0.0, 0.0);
const float Ns = 0.0;
const std::string vshader = "shaders/vshader.glsl";
const std::string fshader = "shaders/fshader.glsl";

Block *air;
Block *cloth_0 = new Block_Cloth_0();
Block *cloth_1 = new Block_Cloth_1();
Block *cloth_2 = new Block_Cloth_2();
Block *cloth_3 = new Block_Cloth_3();
Block *cloth_4 = new Block_Cloth_4();
Block *cloth_5 = new Block_Cloth_5();
Block *cloth_6 = new Block_Cloth_6();
Block *cloth_7 = new Block_Cloth_7();
Block *cloth_8 = new Block_Cloth_8();
Block *cloth_9 = new Block_Cloth_9();
Block *cloth_10 = new Block_Cloth_10();
Block *cloth_11 = new Block_Cloth_11();
Block *cloth_12 = new Block_Cloth_12();
Block *cloth_13 = new Block_Cloth_13();
Block *cloth_14 = new Block_Cloth_14();
Block *cloth_15 = new Block_Cloth_15();
Block *dirt = new Block_Dirt();
Block *grass = new Block_Grass();
Block *leaves = new Block_Leaves();
Block *sand = new Block_Sand();
Block *stone = new Block_Stone();
Block *tree = new Block_Tree();
Block *wood = new Block_Wood();
Block *quartzblock = new Block_Quartzblock();
Block *quartzblock_chiseled = new Block_Quartzblock_chiseled();
Block *quartzblock_lines = new Block_Quartzblock_lines();
Block *pumpkin_face = new Block_Pumpkin_face();
Block *pumpkin_jack = new Block_Pumpkin_jack();
Block *glass = new Block_Glass();
Block *diamond = new Block_Diamond();
Block *emerald = new Block_Emerald();
Block *gold = new Block_Gold();
Block *iron = new Block_Iron();
Block *brick = new Block_Brick();
Block *stonebricksmooth = new Block_Stonebricksmooth();
Block *stonebricksmooth_carved = new Block_Stonebricksmooth_carved();

namespace block
{
    float Length = 0.05f;
}

const std::vector<Block *> BlockList = {
    air, stone, dirt, grass, sand, wood, leaves, tree, cloth_0, cloth_1, cloth_2, cloth_3, cloth_4, cloth_5, cloth_6, cloth_7, cloth_8, cloth_9, cloth_10, cloth_11, cloth_12, cloth_13, cloth_14, cloth_15, quartzblock, quartzblock_chiseled, quartzblock_lines, pumpkin_face, pumpkin_jack, glass, diamond, emerald, gold, iron, brick, stonebricksmooth, stonebricksmooth_carved};

void get_block_image(std::vector<std::string> &image)
{
    for (int i = 1; i < BlockList.size(); i++)
    {
        image.push_back(BlockList[i]->image);
    }
}

void getBlockMesh(TriMesh *&top, TriMesh *&bottom, TriMesh *left, TriMesh *&right, TriMesh *&front, TriMesh *&back)
{
    // top
    top->cleanData();
    top->vertex_positions.push_back(block_vertices[0]);
    top->vertex_positions.push_back(block_vertices[1]);
    top->vertex_positions.push_back(block_vertices[2]);
    top->vertex_positions.push_back(block_vertices[3]);
    for (int i = 0; i < 4; i++)
    {
        top->vertex_normals.push_back(axis[1]);
        top->vertex_colors.push_back(axis[1]);
    }
    top->faces.push_back(vec3i(0, 2, 1));
    top->faces.push_back(vec3i(0, 3, 2));
    top->vertex_textures.push_back(glm::vec2(0, 0));
    top->vertex_textures.push_back(glm::vec2(1, 0));
    top->vertex_textures.push_back(glm::vec2(1, 1));
    top->vertex_textures.push_back(glm::vec2(0, 1));
    top->normal_index = top->faces;
    top->color_index = top->faces;
    top->texture_index = top->faces;
    top->storeFacesPoints();

    // bottom
    bottom->cleanData();
    bottom->vertex_positions.push_back(block_vertices[7]);
    bottom->vertex_positions.push_back(block_vertices[6]);
    bottom->vertex_positions.push_back(block_vertices[5]);
    bottom->vertex_positions.push_back(block_vertices[4]);
    for (int i = 0; i < 4; i++)
    {
        bottom->vertex_normals.push_back(axis[4]);
        bottom->vertex_colors.push_back(axis[4]);
    }
    bottom->faces.push_back(vec3i(0, 2, 1));
    bottom->faces.push_back(vec3i(0, 3, 2));
    bottom->vertex_textures.push_back(glm::vec2(0, 0));
    bottom->vertex_textures.push_back(glm::vec2(1, 0));
    bottom->vertex_textures.push_back(glm::vec2(1, 1));
    bottom->vertex_textures.push_back(glm::vec2(0, 1));
    bottom->normal_index = bottom->faces;
    bottom->color_index = bottom->faces;
    bottom->texture_index = bottom->faces;
    bottom->storeFacesPoints();

    // left
    left->cleanData();
    left->vertex_positions.push_back(block_vertices[0]);
    left->vertex_positions.push_back(block_vertices[3]);
    left->vertex_positions.push_back(block_vertices[7]);
    left->vertex_positions.push_back(block_vertices[4]);
    for (int i = 0; i < 4; i++)
    {
        left->vertex_normals.push_back(axis[3]);
        left->vertex_colors.push_back(axis[3]);
    }
    left->faces.push_back(vec3i(0, 2, 1));
    left->faces.push_back(vec3i(0, 3, 2));
    left->vertex_textures.push_back(glm::vec2(0, 0));
    left->vertex_textures.push_back(glm::vec2(1, 0));
    left->vertex_textures.push_back(glm::vec2(1, 1));
    left->vertex_textures.push_back(glm::vec2(0, 1));
    left->normal_index = left->faces;
    left->color_index = left->faces;
    left->texture_index = left->faces;
    left->storeFacesPoints();

    // right
    right->cleanData();
    right->vertex_positions.push_back(block_vertices[2]);
    right->vertex_positions.push_back(block_vertices[1]);
    right->vertex_positions.push_back(block_vertices[5]);
    right->vertex_positions.push_back(block_vertices[6]);
    for (int i = 0; i < 4; i++)
    {
        right->vertex_normals.push_back(axis[0]);
        right->vertex_colors.push_back(axis[0]);
    }
    right->faces.push_back(vec3i(0, 2, 1));
    right->faces.push_back(vec3i(0, 3, 2));
    right->vertex_textures.push_back(glm::vec2(0, 0));
    right->vertex_textures.push_back(glm::vec2(1, 0));
    right->vertex_textures.push_back(glm::vec2(1, 1));
    right->vertex_textures.push_back(glm::vec2(0, 1));
    right->normal_index = right->faces;
    right->color_index = right->faces;
    right->texture_index = right->faces;
    right->storeFacesPoints();

    // front
    front->cleanData();
    front->vertex_positions.push_back(block_vertices[3]);
    front->vertex_positions.push_back(block_vertices[2]);
    front->vertex_positions.push_back(block_vertices[6]);
    front->vertex_positions.push_back(block_vertices[7]);
    for (int i = 0; i < 4; i++)
    {
        front->vertex_normals.push_back(axis[2]);
        front->vertex_colors.push_back(axis[2]);
    }
    front->faces.push_back(vec3i(0, 2, 1));
    front->faces.push_back(vec3i(0, 3, 2));
    front->vertex_textures.push_back(glm::vec2(0, 0));
    front->vertex_textures.push_back(glm::vec2(1, 0));
    front->vertex_textures.push_back(glm::vec2(1, 1));
    front->vertex_textures.push_back(glm::vec2(0, 1));
    front->normal_index = front->faces;
    front->color_index = front->faces;
    front->texture_index = front->faces;
    front->storeFacesPoints();

    // back
    back->cleanData();
    back->vertex_positions.push_back(block_vertices[1]);
    back->vertex_positions.push_back(block_vertices[0]);
    back->vertex_positions.push_back(block_vertices[4]);
    back->vertex_positions.push_back(block_vertices[5]);
    for (int i = 0; i < 4; i++)
    {
        back->vertex_normals.push_back(axis[5]);
        back->vertex_colors.push_back(axis[5]);
    }
    back->faces.push_back(vec3i(0, 2, 1));
    back->faces.push_back(vec3i(0, 3, 2));
    back->vertex_textures.push_back(glm::vec2(0, 0));
    back->vertex_textures.push_back(glm::vec2(1, 0));
    back->vertex_textures.push_back(glm::vec2(1, 1));
    back->vertex_textures.push_back(glm::vec2(0, 1));
    back->normal_index = back->faces;
    back->color_index = back->faces;
    back->texture_index = back->faces;
    back->storeFacesPoints();
}

World::World() {}

void World::create(int width, int height, int depth)
{
    this->width = width;
    this->height = height;
    this->depth = depth;

    // 0-127为地下，128-255为地上
    blocks = new BlockType **[width];
    for (int x = 0; x < width; x++)
    {
        blocks[x] = new BlockType *[height];
        for (int y = 0; y < height; y++)
        {
            blocks[x][y] = new BlockType[depth];
            for (int z = 0; z < depth; z++)
            {
                if (z == 125)
                    blocks[x][y][z] = BlockType::Stone;
                else if (z == 126)
                    blocks[x][y][z] = BlockType::Dirt;
                else if (z == 127)
                    blocks[x][y][z] = BlockType::Grass;
                else
                    blocks[x][y][z] = BlockType::Air;
            }
        }
    }
}

void World::load(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Failed to open file " << filename << std::endl;
        return;
    }

    std::string line;
    file >> line;
    if (line != "MINECRAFTWORLD")
    {
        std::cout << "Invalid file format" << std::endl;
        return;
    }

    file >> line >> line >> line;
    file >> width >> height >> depth;

    blocks = new BlockType **[width];
    for (int x = 0; x < width; x++)
    {
        blocks[x] = new BlockType *[height];
        for (int y = 0; y < height; y++)
        {
            blocks[x][y] = new BlockType[depth];
            for (int z = 0; z < depth; z++)
                blocks[x][y][z] = BlockType::Air;
        }
    }

    file >> line >> line >> line >> line;
    while (!file.eof())
    {
        int x, y, z, type;
        file >> x >> y >> z >> type;
        blocks[x][y][z] = static_cast<BlockType>(type);
    }
}

void World::save(const std::string &filename)
{
    // width height depth
    // x y z type
    std::ofstream file(filename);
    file << "MINECRAFTWORLD" << std::endl;
    file << "width height depth" << std::endl;
    file << width << " " << height << " " << depth << std::endl;
    file << "x y z type" << std::endl;
    for (int z = 0; z < depth; z++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
                if (blocks[x][y][z] != BlockType::Air)
                    file << x << " " << y << " " << z << " " << static_cast<int>(blocks[x][y][z]) << std::endl;
        }
    }
}

const int distance = 25;
int minx, miny, maxx, maxy;
void World::world_render(int x, int y, int z, const std::string &vshader, const std::string &fshader)
{
    minx = (x > distance) ? x - distance : 0;
    miny = (y > distance) ? y - distance : 0;
    maxx = (x < width - distance) ? x + distance : width;
    maxy = (y < height - distance) ? y + distance : height;
    for (int i = minx; i < maxx; i++)
    {
        for (int j = miny; j < maxy; j++)
        {
            for (int k = 0; k < depth; k++)
            {
                if (blocks[i][j][k] == BlockType::Air || (blocks[i + 1][j][k] != BlockType::Air && blocks[i - 1][j][k] != BlockType::Air && blocks[i][j + 1][k] != BlockType::Air && blocks[i][j - 1][k] != BlockType::Air && blocks[i][j][k + 1] != BlockType::Air && blocks[i][j][k - 1] != BlockType::Air && i != minx && i != maxx - 1 && j != miny && j != maxy - 1))
                    continue;
                block_render(i, j, k);
            }
        }
    }
}

bool istransparent(BlockType type)
{
    if (type == BlockType::Air || type == BlockType::Glass)
        return true;
    return false;
}

void World::block_render(int i, int j, int k)
{
    TriMesh *top = new TriMesh();
    TriMesh *bottom = new TriMesh();
    TriMesh *left = new TriMesh();
    TriMesh *right = new TriMesh();
    TriMesh *front = new TriMesh();
    TriMesh *back = new TriMesh();
    getBlockMesh(top, bottom, left, right, front, back);

    float _x = block::Length * (2 * (i - width / 2));
    float _z = block::Length * (2 * (j - height / 2));
    float _y = block::Length * (2 * (k - 127 - 10));

    top->setTranslation(glm::vec3(_x, _y, _z));
    bottom->setTranslation(glm::vec3(_x, _y, _z));
    left->setTranslation(glm::vec3(_x, _y, _z));
    right->setTranslation(glm::vec3(_x, _y, _z));
    front->setTranslation(glm::vec3(_x, _y, _z));
    back->setTranslation(glm::vec3(_x, _y, _z));

    top->setRotation(zero);
    bottom->setRotation(zero);
    left->setRotation(zero);
    right->setRotation(zero);
    front->setRotation(zero);
    back->setRotation(zero);

    top->setScale(glm::vec3(1.0, 1.0, 1.0));
    bottom->setScale(glm::vec3(1.0, 1.0, 1.0));
    left->setScale(glm::vec3(1.0, 1.0, 1.0));
    right->setScale(glm::vec3(1.0, 1.0, 1.0));
    front->setScale(glm::vec3(1.0, 1.0, 1.0));
    back->setScale(glm::vec3(1.0, 1.0, 1.0));

    top->setAmbient(Ka);
    bottom->setAmbient(Ka);
    left->setAmbient(Ka);
    right->setAmbient(Ka);
    front->setAmbient(Ka);
    back->setAmbient(Ka);

    top->setDiffuse(Kd);
    bottom->setDiffuse(Kd);
    left->setDiffuse(Kd);
    right->setDiffuse(Kd);
    front->setDiffuse(Kd);
    back->setDiffuse(Kd);

    top->setSpecular(Ks);
    bottom->setSpecular(Ks);
    left->setSpecular(Ks);
    right->setSpecular(Ks);
    front->setSpecular(Ks);
    back->setSpecular(Ks);

    top->setShininess(Ns);
    bottom->setShininess(Ns);
    left->setShininess(Ns);
    right->setShininess(Ns);
    front->setShininess(Ns);
    back->setShininess(Ns);

    if (blocks[i][j][k] == BlockType::Glass)
    {
        top->isTransparency = true;
        bottom->isTransparency = true;
        left->isTransparency = true;
        right->isTransparency = true;
        front->isTransparency = true;
        back->isTransparency = true;
    }

    if (istransparent(blocks[i][j][k]))
    {
        std::string _name;
        if (istransparent(blocks[i][j][k + 1]))
        {
            _name = std::to_string(i) + std::to_string(j) + std::to_string(k + 1) + "bottom";
            render->deleteMesh(_name);
        }
        if (istransparent(blocks[i][j][k - 1]))
        {
            _name = std::to_string(i) + std::to_string(j) + std::to_string(k - 1) + "top";
            render->deleteMesh(_name);
        }
        if (istransparent(blocks[i + 1][j][k]))
        {
            _name = std::to_string(i + 1) + std::to_string(j) + std::to_string(k) + "left";
            render->deleteMesh(_name);
        }
        if (istransparent(blocks[i - 1][j][k]))
        {
            _name = std::to_string(i - 1) + std::to_string(j) + std::to_string(k) + "right";
            render->deleteMesh(_name);
        }
        if (istransparent(blocks[i][j + 1][k]))
        {
            _name = std::to_string(i) + std::to_string(j + 1) + std::to_string(k) + "back";
            render->deleteMesh(_name);
        }
        if (istransparent(blocks[i][j - 1][k]))
        {
            _name = std::to_string(i) + std::to_string(j - 1) + std::to_string(k) + "front";
            render->deleteMesh(_name);
        }
    }

    int current = static_cast<int>(blocks[i][j][k]);
    if (k == depth - 1 || istransparent(blocks[i][j][k + 1]))
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "top";
        render->addMesh(top, name, BlockList[current]->texture_top, vshader, fshader);
    }
    if (k == 0 || istransparent(blocks[i][j][k - 1]))
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "bottom";
        render->addMesh(bottom, name, BlockList[current]->texture_bottom, vshader, fshader);
    }
    if (i == 0 || istransparent(blocks[i - 1][j][k]) || i == minx)
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "left";
        render->addMesh(left, name, BlockList[current]->texture_left, vshader, fshader);
    }
    if (i == width - 1 || istransparent(blocks[i + 1][j][k]) || i == maxx - 1)
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "right";
        render->addMesh(right, name, BlockList[current]->texture_right, vshader, fshader);
    }
    if (j == 0 || istransparent(blocks[i][j - 1][k]) || j == miny)
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "back";
        render->addMesh(back, name, BlockList[current]->texture_back, vshader, fshader);
    }
    if (j == height - 1 || istransparent(blocks[i][j + 1][k]) || j == maxy - 1)
    {
        std::string name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "front";
        render->addMesh(front, name, BlockList[current]->texture_front, vshader, fshader);
    }
    BlockmeshList.push_back(top);
    BlockmeshList.push_back(bottom);
    BlockmeshList.push_back(left);
    BlockmeshList.push_back(right);
    BlockmeshList.push_back(front);
    BlockmeshList.push_back(back);
}

void World::delete_block_render(float x, float y, float z)
{
    int i = x / (block::Length * 2) + width / 2;
    int j = z / (block::Length * 2) + height / 2;
    int k = y / (block::Length * 2) + 127 + 10;
    if (i < 0 || i >= width || j < 0 || j >= height || k < 0 || k >= depth)
        return;
    if (blocks[i][j][k] == BlockType::Air)
        return;
    blocks[i][j][k] = BlockType::Air;
    std::string name;
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "top";
    render->deleteMesh(name);
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "bottom";
    render->deleteMesh(name);
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "left";
    render->deleteMesh(name);
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "right";
    render->deleteMesh(name);
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "front";
    render->deleteMesh(name);
    name = std::to_string(i) + std::to_string(j) + std::to_string(k) + "back";
    render->deleteMesh(name);

    if (blocks[i + 1][j][k] != BlockType::Air)
    {
        block_render(i + 1, j, k);
    }
    if (blocks[i - 1][j][k] != BlockType::Air)
    {
        block_render(i - 1, j, k);
    }
    if (blocks[i][j + 1][k] != BlockType::Air)
    {
        block_render(i, j + 1, k);
    }
    if (blocks[i][j - 1][k] != BlockType::Air)
    {
        block_render(i, j - 1, k);
    }
    if (blocks[i][j][k + 1] != BlockType::Air)
    {
        block_render(i, j, k + 1);
    }
    if (blocks[i][j][k - 1] != BlockType::Air)
    {
        block_render(i, j, k - 1);
    }
}

void World::add_block_render(float x, float y, float z, BlockType type)
{
    int i = x / (block::Length * 2) + width / 2;
    int j = z / (block::Length * 2) + height / 2;
    int k = y / (block::Length * 2) + 127 + 10;
    if (i < 0 || i >= width || j < 0 || j >= height || k < 0 || k >= depth)
        return;
    if (blocks[i][j][k] != BlockType::Air)
        return;
    blocks[i][j][k] = type;
    block_render(i, j, k);
}

bool World::is_block(float x, float y, float z)
{
    int i = x / (block::Length * 2.0f) + width / 2.0f;
    int j = z / (block::Length * 2.0f) + height / 2.0f;
    int k = y / (block::Length * 2.0f) + 127 + 10;
    if (i < 0 || i >= width || j < 0 || j >= height || k < 0 || k >= depth)
        return false;
    if (blocks[i][j][k] == BlockType::Air)
    {
        return false;
    }
    return true;
}

void World::clean()
{
    for (int i = 0; i < BlockmeshList.size(); i++)
    {
        BlockmeshList[i]->cleanData();
        delete BlockmeshList[i];
    }
    BlockmeshList.clear();
}

void World::getBlockImage(std::vector<std::string> &image)
{
    get_block_image(image);
}