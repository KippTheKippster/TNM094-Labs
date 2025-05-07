#pragma once

#include <particlesystem/emitterDirectional.h>
#include <particlesystem/particle.h>
#include <glm/geometric.hpp>



void EmitterDirectional::emit(std::function<void(Particle& particle)> addParticle) {
    Particle particle = Particle(position, glm::vec2(0.1, 0.0), lifeTime);
    addParticle(particle);
}
