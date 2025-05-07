#include <particlesystem/effectWind.h>
#include <iostream>
#include <glm/geometric.hpp>

void EffectWind::apply(Particle& particle, double delta)
{
    glm::vec2 dif = particle.position - position;
    if (glm::length(dif) < 0.3)
	{
		particle.force += -0.1;
	}
}
