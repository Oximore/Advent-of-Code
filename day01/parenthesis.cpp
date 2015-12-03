/**
 *  parenthesis.cpp
 *  Solve day 1 problem of : 
 *  http://adventofcode.com/day/1
 * 
 *  Author : Benjamin Lux
 *  Date   : Dec. 2015
 **/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

namespace Floor {
  const char up = '(';
  const char down = ')';
}

int whatIsMyFloor(const std::string& parenthesis);
int whenIWillArriveAtFloor(const std::string& seq, int floor);

int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::cout << "Hello Santa, you are at floor : " << whatIsMyFloor(argv[1]) << std::endl;
    std::cout << "You will enter the basment at step : " << whenIWillArriveAtFloor(argv[1], -1) << std::endl;
 }
  else {
    std::cout << "Wrong number of args." << std::endl;
  }
  return EXIT_SUCCESS;
}

int whatIsMyFloor(const std::string& seq) {
  int floor = 0;
  floor += std::count(seq.begin(), seq.end(), Floor::up);
  floor -= std::count(seq.begin(), seq.end(), Floor::down);
  return floor;
}

int whenIWillArriveAtFloor(const std::string& seq, int floor) {
  int curentFloor = 0;
  unsigned indice = 0;
  for (auto c : seq) {
    switch (c) {
    case Floor::up :
      ++curentFloor;
      break;
    case Floor::down : 
      --curentFloor;
      break;
    default:
      std::cerr << "Error : " << c << std::endl;
      exit(EXIT_FAILURE);
    }
    ++indice;
    if (curentFloor == floor) {
      return indice;
    }
  }
  std::cerr << "Never ever !!!" << std::endl;
  exit(EXIT_FAILURE);
  return indice;
}
