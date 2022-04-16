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

/*
	Parameter:
		>> pA 	First Number
		>> pB 	Secon Number

	Returns 
		>> a random integer between to numbers
*/
int Game::getRand( int pA, int pB){
	return rand() % (pB - pA + 1) + pA;
}

void Game::initGame(){
	srand	((unsigned int) time(NULL));

	mPiece 			= getRand(0, 6);
	mRotation 		= getRand(0, 3);
	mPosX			= ( BOARD_WIDTH / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
	mPosY			= mPieces->getYInitialPosition( mPiece, mRotation);

	mNextPiece 		= getRand(0, 6);
	mNextRotation 	= getRand(0, 3);
	mNextPosX		= BOARD_WIDTH + 5;
	mNextPosY		= 5;
}

void Game::createNewPiece(){
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->getYInitialPosition(mPiexe, mRotation);

	mNextPiece = getRand(0, 6);
	mNextRotation = getRand(0, 3);
}

/*
	Parameter:
		>> pX 			horizontal position in blocks to draw
		>> pY 			vertical position to draw
		>> pPiece 		piece to draw
		>> pRotation 	1 of 4 possible rotations to draw
*/
void Game::drawPiece(int pX, int pY, int pPiece, int pRotation ){

	color mColor;

	int mPixelsX = mBoard->getXPosInPixels(px);
	int mPixelsY = mBoard->getYPosInPixels(pY);


	for( int i = 0; i < PIECE_BLOCKS; i++){
		for( int j = 0; j < PIECE_BLOCKS; j++){

			switch( mPieces->getBlockType(pPiece, pRotation, j, i)){

				case 1: mColor = GREEN; break;  // each block except pivot
				case 2: mColor = BLUE; break; 	// just for the pivot block
			}

			if( mPieces->getBlockType( mPiece, mRotation, j, i) != 0){

				mIO-> drawRectangle(
					mPixelsX + i * BLOCK_SIZE,
					mPixelsY + j * BLOCK_SIZE,
					(mPixelsX + i * BLOCK_SIZE ) + BLOCK_SIZE -1,
					(mPixelsY+ j * BLOCK_SIZE ) + BLOCK_SIZE -1
					)
			}
		}
	}
}