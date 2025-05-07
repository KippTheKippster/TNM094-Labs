#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class Particle {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 force;

    double elapsedTime;
    double lifeTime;

    float mass;

    Particle(glm::vec2 position, glm::vec2 velocity, double lifeTime);

    void update(double delta);
};  