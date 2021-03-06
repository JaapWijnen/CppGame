#include "Human.h"

#include <ctime>
#include <random>

#define GLM_FORCE_RADIANS
#include <glm/gtx/rotate_vector.hpp>

Human::Human() :
    _frames(0)
{
}


Human::~Human()
{
}

void Human::init(float speed, glm::vec2 pos) {

    static std::mt19937 randomEngine((int)time(nullptr));
    static std::uniform_real_distribution<float> randDir(-3.14f, 3.14f);

    _health = 20;

    _color.r = 200;
    _color.g = 0;
    _color.b = 200;
    _color.a = 255;

    _speed = speed;
    _position = pos;
    // Get random direction
    _direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
    // Make sure direction isn't zero
    if (_direction.length() == 0) _direction = glm::vec2(1.0f, 0.0f);

    _direction = glm::normalize(_direction);
}

void Human::update(const std::vector<std::string>& levelData,
                   std::vector<Human*>& humans,
                   std::vector<Zombie*>& zombies,
                   float deltaTime) {

    static std::mt19937 randomEngine((unsigned int)time(nullptr));
    static std::uniform_real_distribution<float> randRotate(-40.0f * 6.28f / 360.0f, 40.0f * 6.28f / 360.0f);

    _position += _direction * _speed * deltaTime;

    // Randomly change direction every 20 frames
    if (_frames == 20) {
        _direction = glm::rotate(_direction, randRotate(randomEngine));
        _frames = 0;
    } else {
        _frames++;
    }

    if (collideWithLevel(levelData)) {
        _direction = glm::rotate(_direction, randRotate(randomEngine));
    }
}