#pragma once

#include <particlesystem/emitter.h>

Emitter::Emitter(glm::vec2 position, float lifeTime, int amount) {
    this->position = position;
    this->lifeTime = lifeTime;
    this->amount = amount;
    this->timeLeft = getWaitTime();
}
Emitter::~Emitter() {}

void Emitter::update(double delta, std::function<void(Particle& particle)> addParticle) {
    timeLeft -= delta;
    if (timeLeft <= 0.0) {
        emit(addParticle);
        timeLeft = getWaitTime();
    }
}

void Emitter::emit(std::function<void(Particle& particle)> addParticle) {
    Particle particle = Particle(position, glm::vec2(0.0, 0.0), lifeTime);
    addParticle(particle);
}

double Emitter::getWaitTime() { return lifeTime / (double)amount; }