test: Source.o FailoDuomenys.o IvedimoDuomenys.o
	g++ Source.o -o test
Source.o: Source.cpp
	g++ -c Source.cpp
FailoDuomenys.o: FailoDuomenys.cpp
	g++ -c FailoDuomenys.cpp
IvedimoDuomenys.o: IvedimoDuomenys.cpp
	g++ -c IvedimoDuomenys.cpp