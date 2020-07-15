# Install
current_dir = $(shell pwd)
BIN = $(current_dir)/viewMd2
CC = g++

# Flags
CFLAGS += `pkg-config --cflags glfw3 epoxy` -pedantic -O2
SOURCE = $(current_dir)/../app/src/main/cpp/opengl/

SRC = $(SOURCE)Renderer.cpp $(SOURCE)Md2.cpp $(SOURCE)ShaderProgram.cpp $(SOURCE)Texture2D.cpp $(SOURCE)Core.cpp $(SOURCE)window.cpp
OBJ = $(SRC:.cpp=.o)

ifeq ($(OS),Windows_NT)
BIN := $(BIN).exe
LIBS = `pkg-config --libs glfw3 epoxy` -lopengl32 -lm -lGLU32
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
	else
		LIBS = -lglfw -lepoxy -lGL -lm -lGLU
	endif
endif

$(BIN):
	rm -f $(BIN) $(OBJS)
	$(CC) $(SRC) $(CFLAGS) -o $(BIN) $(LIBS)
