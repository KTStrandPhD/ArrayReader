#This is just a dummy makefile for now. I'll improve on this later

all:
	g++ -o ArrayReader src/ArrayTest.cxx src/ArrayReader.cxx

clean:
	rm ArrayReader
