EigenPath = /Users/giacorri/eigen-3.4.0

ll: poly.o interpol.o testInterpol

poly.o: poly.cpp
	g++ -c poly.cpp -I$(EigenPath)

interpol.o: interpol.cpp poly.o
	g++ -c interpol.cpp -I$(EigenPath)

testInterpol: testInterpol.cpp interpol.o poly.o
	g++ testInterpol.cpp -o testInterpol -I$(EigenPath) poly.o interpol.o