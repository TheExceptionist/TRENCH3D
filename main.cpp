#include "display.h"
#include "render.h"
#include "objects.h"
#include "defs.h"

int main(int argc, char* argv[])
{
	Display display("triangle_rasterier", 800, 600);

	if(!display.init())
	{
		printf("Could not initialize display!\n");
	}

	Render render(display);

	if(!render.init())
	{
		printf("Could not initialize renderer!\n");
	}

	Entity player("Lambert", 2, 4);
	render.setPlayer(&player);
	
	#ifdef DEBUG
	{
		using namespace e_math;

		vec3i vector2(1, 0, 3);
		vec3i vector3(3, 2, 0);

		vec3f vector1(2.0, 5.0, 7.0);

		vector2.printTests(vector3);

		vec3f vector4(vector1);
		vec3f vector5 = vector4;

		vector4.printStats();
		vector5.printStats();

		vec3f plane = player.getDir()->rotate2D(90);

		printf("===================");
		plane.printStats();
	}
	#endif

	while(display.isRunning())
	{
		display.clearColor(&BLUE);
		render.update();

		display.update();
	}

	return 0;
}
