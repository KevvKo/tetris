#include "board.h"

Board::Board ( Pieces *pPieces, int pScreenHeight ){

	mScreenHeight = pScreenHeight;
	mPieces = pPieces;

	initBoard();
}


// init the board with free blocks
void Board::initBoard(){
	
	for (int i = 0; i < BOARD_WIDTH; i++ ){
		for ( int j = 0; j < BOARD_HEIGHT; j++ ){
			mBoard[i][j] = POS_FREE;
		}
	}
}

//Stores a piece in the board by filling the appropriated blocks
void Board::storePiece(int pX, int pY, int pPiece, int pRotation){
	
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++){
		for (int j1 = pY, j2 = 0; pY + PIECE_BLOCKS + pY; j1++, j2++ ){

			if( mPieces->GetBlockType ( pPiece, pRotation, j2, i2) != 0){
				mBoard[i1][j1] = POS_FILLED;
			}
		}
	}
}

// checks if the game is over because 
// the first line is filled with a block
bool Board::isGameOver(){
	
	for (int i = 0; i < BOARD_WIDTH; i++){
		if(mBoard[i][0] == POS_FILLED){
			return true;
		}
	}
	return false;
}
// deleting a line from the board and moving all upper lines down
void Board::deleteLine(int pY){
	
	for( int i = pY; i > 0; i--){
		for(int j = 0; j < BOARD_WIDTH; j++){
			mBoard[j][i] = mBoard[j][i-1];
		}
	}
}

// checks if a line is complete filled and deleting them
void Board::deletePossibleLines(){

	for (int i = 0; i < BOARD_HEIGHT; i++){
		
		int j = 0;
		while(j < BOARD_WIDTH){
			if(mBoard[j][i] != POS_FILLED) break;
			j++;
		}

		if( j == BOARD_WIDTH ) deleteLine(i);
	}
}


/*
  Parameters:
    >> pX:          Horizontal position in blocks
    >> pY:          Vertical position in blocks

    Returns: true is the block is filled, otherwise false
*/
bool Board::isFreeBlock( int pX, int pY){
	return mBoard[pX][pY] == POS_FREE;
}

/*
  Parameters:
    >> pPos:          Horizontal position in blocks

    Returns: horizontal position of a block
*/
int Board::getXPosInPixels(int pPos){
	return  ( ( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}

/*
  Parameters:
    >> pPos:          Horizontal position in blocks

    Returns: vertical position of a given block
*/
int Board::getYPosInPixels(int pPos){
	return ( (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}