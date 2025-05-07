#pragma once

#include <vector>
#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/effect.h>
#include <span>


class ParticleSystem {
private:
    double elapsedTime;
    unsigned int numParticles;

    std::vector<Particle> particles;
    std::vector<Emitter*> emitters;
    std::vector<Effect*> effects;
    std::vector<glm::vec2> position;
    std::vector<float> size;
    std::vector<glm::vec4> color;

    void addParticle(Particle& particle);

public:
    //typedef void (ParticleSystem::*addParticle)(Particle& particle);

    ParticleSystem(unsigned int numParticles);

    void update(double delta);

    void clearParticles();
    
    void addEmitter(Emitter* emitter);
    void addEffect(Effect* effect);

    void removeEmitter(Emitter* emitter);
    void removeEffect(Effect* effect);

    std::vector<Emitter*> getEmitters() const { return emitters; }
    std::vector<Effect*> getEffects() const { return effects; }

    //std::span<Particle> getParticles() const { return part };
    std::span<const glm::vec2> getPosition() const { return position; }
    std::span<const float> getSize() const { return size; }
    std::span<const glm::vec4> getColor() const { return color; }
};