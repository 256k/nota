mkdir bin ;
eval cc nota.c $(pkg-config --libs --cflags raylib) -o bin/nota
