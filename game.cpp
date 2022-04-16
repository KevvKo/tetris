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

void Game::drawBoard(){

	// Calculate the limits of the board in pixels	
	int mX1 = BOARD_POSITION - ( BLOCK_SIZE * (BOARD_WIDTH / 2)) - x;
	int mX2 = BOARD_POSITION + ( BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	// checks that the vertical margin is not to small
	//assert (mX1 > MIN_HORIZONTAL_MARGIN);

	mIO->drawRectangle( mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->drawRectangle( mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	// Drawing the blocks that are already stored in the board
	mX1 += 1;

	for( int i = 0; i < BOARD_WIDTH; i++){
		for( int j = 0; j < BOARD_HEIGHT; j++){

			// if the block is not free, draw
			if( !mBoard->isFreeBlock(i, j) ){

				mIO->drawRectangle(
					mX1 + i * BLOCK_SIZE,
					mY + j * BLOCK_SIZE,
					(mX1+ i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					RED
				)
			}
		}
	}
}

void Game::drawScene(){
	drawBoard();													// draw the limitation lines and blocks stored in the board
	drawPiece(mPosX, mPosY, mPiece, mRotation);						// draw the playing piece 
	drawPiece( mNextPosX, mNextPosY, mNextPiece, mNextRotation); 	// draw the next place
}