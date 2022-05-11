CXX = g++
SRC = src/main.cpp src/cmdmap.cpp
OBJ = ${SRC:.cpp=.o}
LDFLAGS = -ldpp -std=c++17
PREFIX = /usr/local
NAME = dbackdoor
BINARY = ${NAME}.out

build: ${OBJ}
	${CXX} -o ${BINARY} $^ ${LDFLAGS}

clean:
	rm -f ${OBJ} ${NAME} ${BINARY}

.PHONY: clean