#pragma once

#include <glm/vec2.hpp>
#include <particlesystem/particle.h>


class Effect {
public:
    Effect(glm::vec2 position);
    virtual ~Effect() = 0;
    glm::vec2 position;
    virtual void apply(Particle& particle, double delta) = 0;
};