#include "board.h"

Board::Board ( Pieces *pPieces, int pScreenHeight ){

	mScreenHeight = pScreenHeight;
	mPieces = pPieces;

	InitBoard();
}

void Board::InitBoard(){

}