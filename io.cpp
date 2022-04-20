#include "io.h"

static SDL_Surface *mScreen;
static Uint32 mColors [COLOR_MAX] = {
	0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
    0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff
};

IO::IO(){
	initGraph();
}

void IO::clearScreen(){
	boxColor(mScreen, 0, 0, mScreen->w-1, mScreen->h-1, mColors[BLACK]);
}

/*
	Parameters:
		>> pX1, pY1: 		Upper left corner of the rectangle
		>> pX2, pY2: 		Lower right corner of the rectangle
		>> pC				Rectangle color
*/
void IO::drawRectangle( int pX1, int pY1, int pX2, int pY2, enum color pC){
	boxColor( mScreen, pX1, pY1, pX2, pY2-1, mColors[pC]);
}

int IO::getScreenHeight(){
	return mScreen->h;
}


void IO::updateScreen(){
	SDL_Flip(mScreen);
}

int IO::getKey(){
	
	SDL_Event event; 

	while(true){
		SDL_WaitEvent(&event);

		if(event.type == SDL_KEYDOWN) break;
		if(event.type == SDL_QUIT) exit(3);
	}
	return event.key.keysym.sym;

}

int IO::isKeyDown(int pKey){
		Uint8 * mKeyTable;
		int mNumKeys;
		SDL_PumpEvents();
		mKeyTable = SDL_GetKeyState(&mNumKeys);
		return mKeyTable[pKey];
}

int IO::initGraph(){

	const SDL_VideoInfo *info;
	Uint8 video_bpp;
	Uint32 videoflags;

	if( SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could'nt initialize SDL: %s\n", SDL_GetError());
		return 1;
	} 
	atexit(SDL_Quit);

	info = SDL_GetVideoInfo();

	if(info->vfmt->BitsPerPixel > 0){
		video_bpp = info->vfmt->BitsPerPixel;
	}else {
		video_bpp = 16;
	}

	videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

	if( (mScreen=SDL_SetVideoMode(640, 480, video_bpp, videoflags)) == NULL) {
		fprintf(stderr, "Could'nt set %ix%i video mode %s\n", 640, 480, SDL_GetError());
		return 2;
	}

	return 0;
}