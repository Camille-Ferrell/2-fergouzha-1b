Main: Main.o Code.o 
	g++ main.o Mastermind.o Response.o Code.o -o Main

Main.o: Main.cpp Mastermind.h Response.h Code.h
	g++ -c Main.cpp

Mastermind.o: Mastermind.cpp Mastermind.h Response.h Code.h
	g++ -c Mastermind.cpp

Response.o: Response.cpp Response.h Code.h
	g++ -c Response.cpp

Code.o: Code.cpp Code.h
	g++ -c Code.cpp

clean:
	rm -rf *.o main
