project7: main.o citygraph.o path.o permutation.o
	g++ main.o citygraph.o path.o permutation.o -o project7

main.o: main.cpp
	g++ -c main.cpp

citygraph.o: citygraph.cpp
	g++ -c citygraph.cpp

path.o: path.cpp
	g++ -c path.cpp

permutation.o: permutation.cpp
	g++ -c permutation.cpp

clean:
	rm *.o project7
