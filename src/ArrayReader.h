//Header file for ArrayReader class

//I probably want to create a 'one-and-done' function while builds everything with just an input file called:
  //OpenFile() -> ReadData() -> allocate -> etc. -> etc. 

#ifndef ARRAYREADER_H
#define ARRAYREADER_H


class ArrayReader {
  public:

//Object Constructor
  ArrayReader() {
    std::fstream datafile;
    rowtotal = 0;
  }

  //Class attributes
  std::fstream datafile;   //file fstream object
  std::string file;        //input file name
  std::vector<std::string> inputbuffer;     //vector for input data
  std::vector<std::vector <std::string> > array;
  
  int rowtotal;
  int columntotal;

  //Class methods
  //bool IsInt(std::string line);
  int GetColumns();
  std::string EditCSV(std::string row);
  void OpenFile();
  void CloseFile();
  void AllocateArray();
  void FillArray();
  void ReadData();

  //Temporary methods to be removed later.
    //Or kept in as a testing tool
  void PrintBuffer();
  void PrintArray();
};
#endif
