#pragma once

#include <particlesystem/effect.h>
class EffectWind : public Effect {
public:
    //EffectWind(glm::vec2 position);
	using Effect::Effect;
    void apply(Particle& particle, double delta);
};