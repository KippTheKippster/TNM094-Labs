#pragma once

#include <particlesystem/emitter.h>

class EmitterExplosion : public Emitter {
public:
	using Emitter::Emitter;
    void emit(std::function<void(Particle& particle)> addParticle);
	double getWaitTime() override;
};
