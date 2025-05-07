#pragma once

#include <particlesystem/effect.h>

class EffectGravityWell : public Effect {
public:
	using Effect::Effect;
    void apply(Particle& particle, double delta);
};