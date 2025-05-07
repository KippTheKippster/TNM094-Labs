#pragma once

#include <particlesystem/emitterUniform.h>
#include <particlesystem/particle.h>
#include <glm/geometric.hpp>



void EmitterUniform::emit(std::function<void(Particle& particle)> addParticle) {
    glm::vec2 velocity =
        glm::vec2(0.5f - (float)(rand()) / (float)(RAND_MAX), 0.5f - (float)(rand()) / (float)(RAND_MAX));
    float length = glm::length(velocity);
    velocity /= length;
    velocity *= 0.1;
    Particle particle = Particle(position, velocity, lifeTime);
    addParticle(particle);
}
