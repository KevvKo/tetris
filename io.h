#ifndef _IO_
#define _IO_

#ifndef LINUX
#include "SDL/include/SDL.h"							
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>									
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"	
#endif
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum color {BLACK, RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, COLOR_MAX;}

class IO {

	public:
		IO 						();

		void drawRectAngle		(int pX1, int pY1, int pX2, int pY2, enum color pC);
		void clearScreen		();
		int getScreenHight		();
		int initGraph			();
		int pollKey				();
		int getKey				();
		int isKeyDown			();
		void updateScreen		();
}

#endif