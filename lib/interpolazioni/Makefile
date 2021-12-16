# Modify the Eigen path to compile the library and the test programs

EigenPath = /Users/giacorri/eigen-3.4.0

ll: poly.o interpol.o testInterpol testLettura
#ll: RIMUOVI

poly.o: poly.cpp
	g++ -c poly.cpp -I$(EigenPath)

interpol.o: interpol.cpp interpol.hpp poly.o
	g++ -c interpol.cpp -I$(EigenPath)

testInterpol: testInterpol.cpp interpol.o poly.o
	g++ testInterpol.cpp -o testInterpol -I$(EigenPath) poly.o interpol.o

testLettura: testLettura.cpp interpol.o poly.o
	g++ testLettura.cpp -o testLettura -I$(EigenPath) poly.o interpol.o

RIMUOVI:
	rm output.txt
	rm *.o
	rm testInterpol
	rm testLettura
	rm *.pdf