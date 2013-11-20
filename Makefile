CXXFLAGS=-g -Wall
CPPFLAGS=-g 
CFLAGS=-g

ALL: main.o
	g++ -g -o spellcheck main.o

%.o:

clean:
	rm -r *.o spellcheck

