//Class for ArrayReader

//I should separate this into multiple files,
  //Probably one file for inputbuffer related stuff at least

//I think I'd like to add indexing using unordered maps or something

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "ArrayReader.h"

//Open data file
void ArrayReader::OpenFile() { //string file will be removed as a class argument
                                          //Will use that as a class attribute
  datafile.open(file);
}

//Close data file
void ArrayReader::CloseFile() {

  datafile.close();
}

//Read data from file into buffer array
void ArrayReader::ReadData() {
  
  if (datafile.is_open()) {
    std::string row;
    std::string tmprow;

    while (getline(datafile, row)) {
      tmprow = EditCSV(row);          //Removing any commas from line
      inputbuffer.push_back(tmprow);  //Adding clean lines to inputbuffer
      rowtotal++;                     //For verifying total rows of data
    }
  }
}

//Function to edit .csv files
std::string ArrayReader::EditCSV(std::string row) {
  std::string noComma;
  
  row.erase(std::remove(row.begin(), row.end(), ','), row.end());
  noComma = row;

  return noComma;
}

//Get number of columns
int ArrayReader::GetColumns() {
  int maxcolumns = 0;

  for (int row = 0; row < inputbuffer.size(); row++) {
    int columns = 0;
    std::string line = inputbuffer[row];
    std::stringstream fullrow(line);

    while (fullrow >> line) {
      columns++;
    }
    if (columns > maxcolumns) {
      maxcolumns = columns;
    }
  }

  return maxcolumns;
}

//Allocate Array

void ArrayReader::AllocateArray() {
  
  array.resize(rowtotal, std::vector<std::string> (columntotal));
}

//Fill array with input data
void ArrayReader::FillArray() {
  
  for (int row = 0; row < rowtotal; row++) {

    int column = 0;
    std::string line = inputbuffer[row];
    std::stringstream fullrow(line);

    while (fullrow >> line) {
      array[row][column] = line;
      column++;
    }
  }
}


//Temporary method for displaying inputbuffer vector
//Only use for visualization purposes.
void ArrayReader::PrintBuffer() {

  for (int i = 0; i < inputbuffer.size(); i++) {
    std::cout << inputbuffer[i] << std::endl;
  } 
}

//Temporary method for displaying array vector
//Only use for visualization purposes
void ArrayReader::PrintArray() {

  for (int i = 0; i < rowtotal; i++) {
    for (int j = 0; j < columntotal; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  } 
}

//Function to detect int values in string
  //This should be done on the separated array
  //This will probably be needed for float as well
    //I think it might be best to check all types at once:
    //1) If all characters are digits -> int
    //2) If all characters are digits and contains a single .-> float
    //3) If combination of digits and letters -> keep as string
  //I should a declaration to set the dtype in FillArray()
/*
bool ArrayReader::IsInt(std::string line) {
	FINISH LATER  
}*/
