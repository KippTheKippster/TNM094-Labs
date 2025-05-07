#pragma once

#include <particlesystem/emitter.h>

class EmitterUniform : public Emitter {
public:
	using Emitter::Emitter;
    void emit(std::function<void(Particle& particle)> addParticle);
};