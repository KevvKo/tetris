#ifndef LINUX
#include<windows.h>
#endif

#include "game.h"

Game::Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight){
	
	mScreenHeight = pScreenHeight;
	mBoard = pBoard;
	mPieces = pPieces;
	mIO = pIO;

	initGame();	
}

int Game::getRand( int pA, int pB){
	return rand() % (pB - pA + 1) + pA;
}