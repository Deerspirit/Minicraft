#include "Player.h"
#include "World.h"
#include <chrono>
#include <vector>

float isn = 3.33333f;
std::vector<glm::vec3> normals = {
    glm::vec3(1, 0, 0),   // x
    glm::vec3(0, 1, 0),   // y
    glm::vec3(0, 0, 1),   // z
    glm::vec3(-1, 0, 0),  //-x
    glm::vec3(0, -1, 0),  //-y
    glm::vec3(0, 0, -1)}; //-z

struct TriFace
{
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 v3;
    glm::vec3 n;
    TriFace(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 n) : v1(v1), v2(v2), v3(v3), n(n) {}
};

glm::vec3 Player::getFrontBlock(World *world)
{
    glm::vec3 ray_origin = camera->cameraPos;
    glm::vec3 ray_direction = camera->cameraFront;

    float t = 0.0f;
    while (t <= handLength)
    {
        glm::vec3 current_point = ray_origin + ray_direction * t;
        float x = (floor((current_point.x + 0.05) * 10)) / 10.0;
        float y = (floor((current_point.y + 0.05) * 10)) / 10.0;
        float z = (floor((current_point.z + 0.05) * 10)) / 10.0;
        if (world->is_block(x, y, z))
        {
            return glm::vec3(x, y, z);
        }
        t += 0.05f;
    }
    return glm::vec3(isn, isn, isn);
}

bool isthought(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 p, glm::vec3 d)
{
    glm::vec3 n = glm::cross(v2 - v1, v3 - v1);
    if (glm::dot(n, d) == 0)
        return false;
    if (glm::dot(n, d) > 0)
        n = -n;
    float t = glm::dot(n, v1 - p) / glm::dot(n, d);
    glm::vec3 x = p + t * d;

    glm::vec3 a = glm::normalize(v1 - x);
    glm::vec3 b = glm::normalize(v2 - x);
    glm::vec3 c = glm::normalize(v3 - x);

    float alpha = glm::acos(glm::dot(a, b));
    float beta = glm::acos(glm::dot(b, c));
    float gamma = glm::acos(glm::dot(c, a));

    if (std::abs(alpha + beta + gamma - 2 * glm::pi<float>()) < 0.01)
        return true;
    return false;
}

void Player::place_block(World *world, int type)
{
    glm::vec3 frontBlock = getFrontBlock(world);
    if (frontBlock.x == isn && frontBlock.y == isn && frontBlock.z == isn)
        return;
    glm::vec3 ray = camera->cameraFront;
    glm::vec3 points[8] = {
        glm::vec3(frontBlock.x - 0.05f, frontBlock.y + 0.05f, frontBlock.z - 0.05f),
        glm::vec3(frontBlock.x + 0.05f, frontBlock.y + 0.05f, frontBlock.z - 0.05f),
        glm::vec3(frontBlock.x + 0.05f, frontBlock.y + 0.05f, frontBlock.z + 0.05f),
        glm::vec3(frontBlock.x - 0.05f, frontBlock.y + 0.05f, frontBlock.z + 0.05f),
        glm::vec3(frontBlock.x - 0.05f, frontBlock.y - 0.05f, frontBlock.z - 0.05f),
        glm::vec3(frontBlock.x + 0.05f, frontBlock.y - 0.05f, frontBlock.z - 0.05f),
        glm::vec3(frontBlock.x + 0.05f, frontBlock.y - 0.05f, frontBlock.z + 0.05f),
        glm::vec3(frontBlock.x - 0.05f, frontBlock.y - 0.05f, frontBlock.z + 0.05f)};
    TriFace faces[12] = {
        TriFace(points[0], points[1], points[2], glm::vec3(0, 1, 0)),
        TriFace(points[0], points[2], points[3], glm::vec3(0, 1, 0)),
        TriFace(points[5], points[4], points[7], glm::vec3(0, -1, 0)),
        TriFace(points[5], points[7], points[6], glm::vec3(0, -1, 0)),
        TriFace(points[1], points[5], points[6], glm::vec3(1, 0, 0)),
        TriFace(points[1], points[6], points[2], glm::vec3(1, 0, 0)),
        TriFace(points[4], points[0], points[3], glm::vec3(-1, 0, 0)),
        TriFace(points[4], points[3], points[7], glm::vec3(-1, 0, 0)),
        TriFace(points[3], points[2], points[6], glm::vec3(0, 0, 1)),
        TriFace(points[3], points[6], points[7], glm::vec3(0, 0, 1)),
        TriFace(points[4], points[5], points[1], glm::vec3(0, 0, -1)),
        TriFace(points[4], points[1], points[0], glm::vec3(0, 0, -1))};
    std::vector<TriFace> thrfaces;
    for (int i = 0; i < 12; i++)
    {
        if (isthought(faces[i].v1, faces[i].v2, faces[i].v3, camera->cameraPos, ray))
        {
            thrfaces.push_back(faces[i]);
        }
    }
    float dot = 0.0f;
    int index = 0;
    for (int i = 0; i < thrfaces.size(); i++)
    {
        float temp = glm::dot(-ray, thrfaces[i].n);
        if (temp > dot)
        {
            dot = temp;
            index = i;
        }
    }
    glm::vec3 len(0.1f, 0.1f, 0.1f);
    glm::vec3 offset(len.x * thrfaces[index].n.x, len.y * thrfaces[index].n.y, len.z * thrfaces[index].n.z);
    glm::vec3 placeBlock = frontBlock + offset;
    world->add_block_render(placeBlock.x, placeBlock.y, placeBlock.z, static_cast<BlockType>(type));
}

void Player::destroy_block(World *world)
{
    glm::vec3 frontBlock = getFrontBlock(world);
    if (frontBlock.x == isn && frontBlock.y == isn && frontBlock.z == isn)
        return;
    world->delete_block_render(frontBlock.x, frontBlock.y, frontBlock.z);
}

std::chrono::steady_clock::time_point lastClickTime;

void Player::mouse_callback(sf::Window *window, World *world)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastClickTime).count() > 150)
        {
            destroy_block(world);
            lastClickTime = now;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && isReleaseRight)
    {
        auto now = std::chrono::steady_clock::now();
        place_block(world, currentBlock);
        isReleaseRight = false;
    }
}