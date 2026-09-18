#
# Builds the OpenCL example on macOS or Linux.
#
# macOS:  make
# Linux:  make (requires the OpenCL development libraries)
#
EXE = gradient_update
OS = $(shell uname)

ifeq ($(OS), Linux)
	CC = nvcc
	LIBS = -lOpenCL
	CCFLAGS = 
endif

ifeq ($(OS), Darwin)
	CC = gcc
	CCFLAGS = -Wall
	LIBS = -framework OpenCL
endif

all:
	$(CC) $(LIBS) $(CCFLAGS) -o $(EXE) main.c
