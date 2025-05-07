#pragma once

#include <particlesystem/particlesystem.h>
#include <particlesystem/emitterDirectional.h>
#include <particlesystem/effectWind.h>
#include <particlesystem/effectGravityWell.h>

ParticleSystem::ParticleSystem(unsigned int numParticles) {
    elapsedTime = 0.0;
    this->numParticles = numParticles;

    particles.reserve(numParticles);
    position.reserve(numParticles);
    size.reserve(numParticles);
    color.reserve(numParticles);
}

void ParticleSystem::update(double delta) { 
    for (unsigned int i = 0; i < particles.size(); i++) {
        for (unsigned int j = 0; j < effects.size(); j++) {
            effects[j]->apply(particles[i], delta);
        }
        particles[i].update(delta);
        position[i] = particles[i].position;
    }

    if (particles.size() < numParticles) {
        for (unsigned int i = 0; i < emitters.size(); i++) {
            Emitter* emitter = emitters[i];
            std::function<void(Particle&)> f = std::bind(&ParticleSystem::addParticle, this, std::placeholders::_1);
            emitter->update(delta, f);
        }
    }

    unsigned int particleCount = particles.size();
    for (int i = 0; i < particleCount; i++) {
        if (particles.front().elapsedTime >= particles.front().lifeTime) {
            particles.erase(particles.begin());
            position.erase(position.begin());
            size.erase(size.begin());
            color.erase(color.begin());
        }
    }
}

void ParticleSystem::clearParticles() {
    particles.clear();
    position.clear();
    size.clear();
    color.clear();
}

void ParticleSystem::addEmitter(Emitter* emitter) { 
    emitters.push_back(emitter);
}

void ParticleSystem::addEffect(Effect* effect) {
    effects.push_back(effect); }

void ParticleSystem::addParticle(Particle& particle) {
    particles.push_back(particle);
    position.push_back(particle.position);
    size.push_back(5.0);
    color.push_back(glm::vec4(0.4, 0.5, 0.7, 0.3));
}

void ParticleSystem::removeEmitter(Emitter* emitter) { 
    emitters.erase(std::find(emitters.begin(), emitters.end(), emitter));
}

void ParticleSystem::removeEffect(Effect* effect) {
    effects.erase(std::find(effects.begin(), effects.end(), effect));
}
