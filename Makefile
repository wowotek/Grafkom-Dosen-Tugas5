CC 		= g++
CFLAGS 	= -W -Wall -Wextra
DEPS = -lGL -lGLU -lglut

EXE = tugas5.exec

O = build/o
BIN = build/bin

all: clean build_folder ${EXE}

clean:
	@rm -rf build/

build_folder:
	@mkdir build/
	@mkdir ${O}/
	@mkdir ${BIN}/

scene.o: src/scene.cc src/scene.hh
	${CC} ${CFLAGS} -c src/scene.cc -o ${O}/scene.o

main.o: src/main.cc
	${CC} ${CFLAGS} -c src/main.cc -o ${O}/main.o

${EXE}: scene.o main.o
	${CC} ${CFLAGS} -O3 ${O}/scene.o ${O}/main.o ${DEPS} -o ${BIN}/${EXE}