#include "Engine.h"
#include "TestWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Graphics");

	TestWorld* world = new TestWorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}