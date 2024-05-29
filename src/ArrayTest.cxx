//Example code using test.dat
	//This will construct and fill an array.
	//This is just for educational purposes
	//and all of these steps and methods should be combined for elegance.

#include <iostream>
#include <fstream>
#include "ArrayReader.h"

using namespace std;

int main() {

	ArrayReader areader;														//Creates ArrayReader object
	areader.file = "data/test.dat"; 					//Provides file name
  areader.OpenFile();															//Opens file
	areader.ReadData();															//Reads data into input buffer
	areader.CloseFile();														//Closes file
	areader.columntotal = areader.GetColumns();			//Determines the number of columns
	areader.AllocateArray();												//Allocates multidimensional array
	areader.FillArray();														//Fills array
	areader.PrintArray();														//Prints, this function is not for practical use.

	return 0;
		
}
