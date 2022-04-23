CC=g++
EXECUTABLE=tetris
SOURCES=main.cpp pieces.cpp board.cpp game.cpp io.cpp

tetris:
	${CC} -o ${EXECUTABLE} ${SOURCES} -I include -L lib

clean:
	-rm -f tetris