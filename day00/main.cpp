/**
 * main.cpp
 * Solve day X problem of : 
 * http://adventofcode.com
 * 
 *  Author : Benjamin Lux
 *  Date   : Dec. 2015
 **/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>

void myFunction(const std::string& fileName);

/** \brief template */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::cout << "Hello Santa !" << std::endl;
    myFunction(argv[1]);
  }
  else {
    std::cout << "Wrong number of args." << std::endl;
    std::cout << "Usage : " << std::endl << argv[0] << " file" << std::endl;
  }
  return EXIT_SUCCESS;
}

void myFunction(const std::string& fileName) {
   ifstream sampleFile (fileName);
   if (myfile.is_open()) {
     // do things
   }
   else {
     std::cout << "Unable to open file : " << fileName;
     return exit(EXIT_FAILURE);
   }
}
