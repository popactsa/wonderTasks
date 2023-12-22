all: main.exe clean

main.exe: main.o List_class.o Node_class.o
	g++ -g  main.o List_class.o Node_class.o -o main.exe

main.o: main.cpp
	g++ -g -c main.cpp

List_class.o: List_class.cpp
	g++ -g -c List_class.cpp

Node_class.o: Node_class.cpp
	g++ -g -c Node_class.cpp

clean:
	rm -rf *.o
