tetris: pieces.h pieces.cpp
	g++ -o tetris main.cpp pieces.h pieces.cpp board.h board.cpp

clean:
	rm tetris