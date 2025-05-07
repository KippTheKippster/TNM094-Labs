#include <catch2/catch_all.hpp>
#include <glm/glm.hpp>

#include <particlesystem/particlesystem.h>
#include <particlesystem/emitterDirectional.h>
#include <particlesystem/emitterUniform.h>
#include <particlesystem/emitterExplosion.h>

/* Unit tests using the catch2 framework
 * Homepage: https://github.com/catchorg/Catch2
 * Tutorial: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md
 * Docs: https://github.com/catchorg/Catch2/blob/devel/docs/Readme.md
 */

TEST_CASE("Check if emitters spawns and removes particles correctly", "[ParticleSystem]") {
    ParticleSystem system = ParticleSystem(100);

    // Create emitters
    auto emitterDirectional = new EmitterDirectional({0, 0}, 1.0, 10);
    auto emitterUniform = new EmitterUniform({0.5, 0}, 1.0, 10);

    system.addEmitter(emitterDirectional);
    system.addEmitter(emitterUniform);

    SECTION("Particles are removed when their lifetime expires") {
        // Run for 1 second to spawn particles
        system.update(1.0f);
        REQUIRE(system.getPosition().size() > 0);  // Ensure particles exist

        // Delete emitters (stop spawning new particles)
        system.removeEmitter(emitterDirectional);
        system.removeEmitter(emitterUniform);

        delete emitterDirectional;
        delete emitterUniform;

        // Fast-forward time to let all particles die
        system.update(100.0f);

        // Check that no particles remain
        REQUIRE(system.getPosition().size() == 0);
    }
}

// lab 3 new emitter test case
TEST_CASE("Explosion emitter spawns multiple particles correctly", "[ParticleSystem]") {
    ParticleSystem system = ParticleSystem(40);

    // Create emitter with known burst timing
    auto emitter = new EmitterExplosion({0, 0}, 2.0, 40);  // 12 particles = 30° apart
    system.addEmitter(emitter);

    SECTION("Verify particles amount") {
        system.update(0.0);
        REQUIRE(system.getPosition().size() == 40);
        system.update(1.0);
        REQUIRE(system.getPosition().size() == 40);
        system.update(8.0);
        REQUIRE(system.getPosition().size() == 0);
    }

    // 
}
