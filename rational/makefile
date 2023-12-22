all: main.exe

main.exe: main.o CRational.o
	g++ main.o CRational.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

general.o: CRational.o
	g++ -c CRational.cpp

clean:
	rm -rf *.o main.exe
