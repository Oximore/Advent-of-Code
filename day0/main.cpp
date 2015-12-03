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

/** \brief template */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::cout << "Hello Santa !" << std::endl;
    ifstream sampleFile (argv[1]);
    if (myfile.is_open()) {
    
    }
    else {
      std::cout << "Unable to open file : " << argv[1];
      return EXIT_FAILURE;
    }
  }
  else {
    std::cout << "Wrong number of args." << std::endl;
    std::cout << "Usage : " << std::endl << argv[0] << " file" << std::endl;
  }
  return EXIT_SUCCESS;
}

