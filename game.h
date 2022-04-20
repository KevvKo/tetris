#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "pieces.h"
#include "io.h"
#include <time.h>
#define WAIT_TIME 700 // number of milliseconds that remain before a piece going one block down

class Game {

	public:

		Game 					(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

		void drawScene			();
		void createNewPiece		();

		int mPosX, mPosY;				// position of the pieces that is falling down
		int mPiece, mRotation;			// kind of rotation that is falling down

	private:

		int mScreenHeight; 				// screen height in pixels		
		int mNextPosX, mNextPosY;		// position of the next piece
		int mNextPiece, mNextRotation;	// kind and rotation of the next piece

		Board *mBoard;
		Pieces *mPieces;
		IO *mIO;

		int getRand				(int pA, int pB);
		void initGame			();
		void drawPiece			(int pX, int pY, int pPiece, int pRotation);
		void drawBoard			();

};

#endif