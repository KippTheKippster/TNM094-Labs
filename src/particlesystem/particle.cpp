#include <particlesystem/particle.h>

Particle::Particle(glm::vec2 position, glm::vec2 velocity, double lifeTime) {
    this->elapsedTime = 0.0;
    this->position = position;
    this->velocity = velocity;
    this->force = glm::vec2(0.0);
    this->mass = 0.1f;
    this->lifeTime = lifeTime;
}

void Particle::update(double delta) {
    elapsedTime += delta;
    glm::vec2 acceleration = force / mass;
    velocity += acceleration * (float)delta;
    position += velocity * (float)delta; 
    force = glm::vec2(0.0, 0.0);
}