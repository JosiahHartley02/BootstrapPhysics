#include "Engine.h"

int main() {
	
	Engine* engine = new Engine(1280,720, "Graphics");

	engine->run();

	delete engine;

	return 0;
}