CXX	=	g++
CXXFLAGS = -Wall -std=c++20		$(shell pkg-config --cflags sdl3)
LDFLAGS = $(shell pkg-config --libs sdl3)

SRC = src/main.cpp	src/platform/factory.cpp	\
	  src/platform/sdl3/sdl_window.cpp	\
	  src/platform/sdl3/sdl_renderer.cpp	\
	  src/core/framebuffer.cpp	\
	  src/core/line.cpp	\
	  src/core/shape.cpp	\
	  src/software/softwarerenderer.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = renderer

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o:	%.cpp
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJ)	$(TARGET)



