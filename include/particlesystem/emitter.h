#pragma once

#include <glm/vec2.hpp>
#include <particlesystem/particle.h>
#include <functional>

class Emitter {
public:
    Emitter(glm::vec2 position, float lifeTime, int amount);
    virtual ~Emitter() = 0;

    glm::vec2 position;
    float lifeTime;
    int amount;
    double timeLeft;

    void update(double delta, std::function<void(Particle& particle)> addParticle);
    virtual void emit(std::function<void(Particle& particle)> addParticle) = 0;
    virtual double getWaitTime();
};