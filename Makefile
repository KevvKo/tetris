tetris: pieces.h pieces.cpp
	g++ -o tetris main.cpp pieces.h pieces.cpp

clean:
	rm tetris