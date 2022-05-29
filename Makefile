test: source.o IvedimoDuomenys.o FailoDuomenys.o
	g++ -o test source.o
Source.o: Source.cpp
	g++ -c Source.cpp
IvedimoDuomenys.o: IvedimoDuomenys.cpp
	g++ -c IvedimoDuomenys.cpp
FailoDuomenys.o: FailoDuomenys.cpp
	g++ -c FailoDuomenys.cpp
