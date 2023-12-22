all: main.exe clean

main.exe: main.o Tree_class.o
	g++ -g  main.o Tree_class.o -o main.exe

main.o: main.cpp
	g++ -g -c main.cpp

Tree_class.o: Tree_class.cpp
	g++ -g -c Tree_class.cpp

clean:
	rm -rf *.o
