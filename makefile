all: create compile
CFLAGS = -g
create:	Date.cpp Date.h
		g++ $(CFLAGS) -c Date.cpp Date.h
compile: main.cpp Date.o
		 g++ $(CFLAGS) main.cpp Date.o -o run.out
run: 
		./run.out
clean:
		rm Date.o
		rm run.out
		rm Date.h.gch

