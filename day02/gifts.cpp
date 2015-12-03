/**
 * gifts.cpp
 * Solve day 2 problem of : 
 * http://adventofcode.com/day/2
 * 
 *  Author : Benjamin Lux
 *  Date   : Dec. 2015
 **/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <istream>
#include <sstream>

using Feet = int;
using SquareFeet = int;

void howManyTotalSquareFeetOfWrappingPaper(const std::string& fileName);

struct Box {
  Feet length, width, height;
  SquareFeet wrappingPaperNeeded() {
    SquareFeet totArea = 0, minArea = -1, curArea = 0;
    curArea = length*width;
    minArea = curArea;
    totArea += 2*curArea;
    
    curArea = length*height;
    minArea = std::min(minArea, curArea);
    totArea += 2*curArea;

    curArea = width*height;
    minArea = std::min(minArea, curArea);
    totArea += 2*curArea;

    totArea += minArea;
    return totArea;
  }
  Feet ribbonNeeded() {
    Feet maxVal = std::max(length, width);
    maxVal = std::max(maxVal, height);
    return 2*(length+width+height - maxVal) + length*width*height;
  }
};

std::istream& operator>> (std::istream& is, Box& box) {
  char c;
  is >> box.length >> c >> box.width >> c >> box.height;
  return is;
} 

std::ostream& operator<< (std::ostream& os, const Box& box) {
  return os << box.length << 'x'<< box.width << 'x' << box.height;
} 



/** \brief template */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::cout << "Hello Santa !" << std::endl;
    howManyTotalSquareFeetOfWrappingPaper(argv[1]);
  }
  else {
    std::cout << "Wrong number of args." << std::endl;
    std::cout << "Usage : " << std::endl << argv[0] << " file" << std::endl;
  }
  return EXIT_SUCCESS;
}

void  howManyTotalSquareFeetOfWrappingPaper(const std::string& fileName) {
  SquareFeet wrappingPaperArea = 0;
  Feet ribbonLength = 0;

  std::ifstream inFile (fileName);
  if (inFile.is_open()) {
   
    Box box;
    for ( std::string line ; std::getline(inFile, line) ; ) {
      std::istringstream iss(line);
      iss >> box;
      wrappingPaperArea += box.wrappingPaperNeeded();
      ribbonLength      += box.ribbonNeeded();
    }
    
  }
  else {
    std::cout << "Unable to open file : " << fileName;
    exit(EXIT_FAILURE);
  }

  std::cout << "Elves need to order " << wrappingPaperArea << " feet square of wrapping paper and " << ribbonLength << " feet of ribbon." << std::endl;
}

