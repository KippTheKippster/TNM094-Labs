#include <rendering/window.h>
#include <example/randomsystem.h>
#include <particlesystem/particlesystem.h>
#include <particlesystem/emitterUniform.h>
#include <particlesystem/emitterDirectional.h>
#include <particlesystem/emitterExplosion.h>
#include <particlesystem/effectGravityWell.h>
#include <particlesystem/effectWind.h>

#include <fmt/format.h>

#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <string> 

/*
 * This application represents the "Client" the uses your particle system
 */
int main() try {
    rendering::Window window("Particle System v0.0.2 pre-release alpha", 850, 850);

    // Creates an example system with a 1000 particles.
    // This should be replaced with your new particle system
    const size_t numParticles = 4000;
    ParticleSystem system{numParticles};

    //EmitterUniform* emitter = new EmitterUniform(glm::vec2(0.0));
    //system.addEmitter(emitter);

    Effect* currentEffect = nullptr;
    Emitter* currentEmitter = nullptr;

    double elapsedTime = window.time();
    float speed = 1.0f;
    bool running = true;

    while (running) {
        window.beginFrame();

        double newTime = window.time();
        double delta = (newTime - elapsedTime) * speed;
        elapsedTime = newTime;

        // Update the example system.
        // This should be replaced with a call to the new particle system
        if (currentEffect == nullptr) {
            system.update(delta); 
        } 
        else {
            system.update(delta);
        }

        // Clear screen with color
        window.clear({0, 0, 0, 1});

        // Draw particles
        // This should also be adjusted to work with the new particle system

        window.drawPoints(system.getPosition(), system.getSize(), system.getColor());
        
        // Example user interface, extend for your needs.
        // Might add controls for effects and emitters etc.
        {
            window.beginGuiWindow("GUI");
            window.sliderFloat("Speed", speed, 0.001f, 10.0f);
            if (window.button("Clear particles")) {
                system.clearParticles();
            }
            window.text("----------");
            window.text("Emitter");
            if (window.button("Uniform")) {
                EmitterUniform* emitter = new EmitterUniform(glm::vec2(0.0), 4.0, 40);
                system.addEmitter(emitter);
                if (currentEmitter == nullptr) {
                    currentEmitter = emitter;
                }
            }
            if (window.button("Directional")) {
                EmitterDirectional* emitter = new EmitterDirectional(glm::vec2(0.0), 4.0, 40);
                system.addEmitter(emitter);
                if (currentEmitter == nullptr) {
                    currentEmitter = emitter;
                }
            }
            if (window.button("Explosion")) {
                EmitterExplosion* emitter = new EmitterExplosion(glm::vec2(0.0), 4.0, 40);
                system.addEmitter(emitter);
                if (currentEmitter == nullptr) {
                    currentEmitter = emitter;
                }
            }
            window.text("Effect");
            if (window.button("Gravity Well")) {
                EffectGravityWell* effect = new EffectGravityWell(glm::vec2(0.0));
                system.addEffect(effect);
                if (currentEffect == nullptr) {
                    currentEffect = effect;
                }
            }
            if (window.button("Wind")) {
                EffectWind* effect = new EffectWind(glm::vec2(0.0));
                system.addEffect(effect);
                if (currentEffect == nullptr) {
                    currentEffect = effect;
                }
            }
            window.text("----------");

            if (window.button("Close application")) {
                running = false;
            }

            window.endGuiWindow();
        }

        {
            window.beginGuiWindow("Active element");
            window.text("Emitters: ");
            std::vector<Emitter*> emitters = system.getEmitters();
            for (unsigned int i = 0; i < emitters.size(); i++) {
                //auto emitter = emitters[i];
                window.drawPoint(emitters[i]->position, 3.0, glm::vec4(0.9, 0.1, 0.1, 0.8));
                if (window.button("Emitter - " + std::to_string(i))) {
                    currentEmitter = emitters[i];
                }
            }
            window.text("Effects: ");
            std::vector<Effect*> effects = system.getEffects();
            for (unsigned int i = 0; i < effects.size(); i++) {
                // auto emitter = emitters[i];
                window.drawPoint(effects[i]->position, 3.0, glm::vec4(0.1, 0.9, 0.1, 0.8));
                if (window.button("Effect - " + std::to_string(i))) {
                    currentEffect = effects[i];
                }
            }
            window.endGuiWindow();
        }

        if (currentEmitter != nullptr) {
            window.beginGuiWindow("Emitter");
            window.sliderFloat("x", currentEmitter->position.x, -1.0f, 1.0f);
            window.sliderFloat("y", currentEmitter->position.y, -1.0f, 1.0f);
            window.sliderInt("amount", currentEmitter->amount, 1, 1000);
            window.sliderFloat("lifeTime", currentEmitter->lifeTime, 0.01, 24.0f);
            if (window.button("Remove")) {
                system.removeEmitter(currentEmitter);
                delete currentEmitter;
                currentEmitter = nullptr;
            }
            window.endGuiWindow();
        }

        if (currentEffect != nullptr) {
            window.beginGuiWindow("Effect");
            window.sliderFloat("x", currentEffect->position.x, -1.0f, 1.0f);
            window.sliderFloat("y", currentEffect->position.y, -1.0f, 1.0f);
            if (window.button("Remove")) {
                system.removeEffect(currentEffect);
                delete currentEffect;
                currentEffect = nullptr;
            }
            window.endGuiWindow();
        }

        window.endFrame();
        running = running && !window.shouldClose();
    }

    return EXIT_SUCCESS;
} catch (const std::exception& e) {
    fmt::print("{}", e.what());
    return EXIT_FAILURE;
}
