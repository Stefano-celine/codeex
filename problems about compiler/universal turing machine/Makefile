DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj

SRC = $(wildcard ${DIR_SRC}/*.cpp)
OBJ = $(patsubst %.cpp, ${DIR_OBJ}/%.o, $(notdir ${SRC})) 

TARGET = utm

BIN_TARGET = $(TARGET)

CC = g++
CFLAGS = -g -Wall -std=c++11 -I$(DIR_INC)

CPPFLAGS = -std=c++11

${BIN_TARGET}: ${OBJ} | ${DIR_BIN}
	${CC} ${OBJ} -o $@

${DIR_OBJ}/%.o: ${DIR_SRC}/%.cpp | ${DIR_OBJ}
	${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJ}:
	mkdir $@

.PHONY: clean
clean:
	rm -rf ${DIR_OBJ}/*.o