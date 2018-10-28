#include "display.h"
#include "render.h"
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
