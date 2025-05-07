#include <particlesystem/effectGravityWell.h>
#include <iostream>
#include <glm/geometric.hpp>

void EffectGravityWell::apply(Particle& particle, double delta)
{
    glm::vec2 dif = position - particle.position;
    float length = glm::length(dif); 
    glm::vec2 normalized_dif = dif / length;
    //std::cout << __FUNCTION__ << " x: " << dif.x << " "
    //          << " y: " << dif.y << " length: " << length << '\n';
    if (length > 0.0)
	{
        particle.force += normalized_dif / (length + 1.0f) * (float)delta;
	}
}
