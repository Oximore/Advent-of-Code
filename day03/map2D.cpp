/**
 *  map2D.cpp
 *  Solve day 3 problem of : 
 *  http://adventofcode.com/day/3
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


namespace Char {
  const char Up    = '^';
  const char Down  = 'v';
  const char Left  = '<';
  const char Right = '>';
}

class map2D {
  std::vector<std::vector<int /*passage number*/>> map;
  size_t center[2];
  unsigned int pplNb;
  std::vector<size_t> pos[2];
  unsigned int visitedHouseNumber;

public:
  map2D(size_t maxRange, unsigned int pplNb = 1) {
    size_t size = 2*maxRange+2;
    map.resize(size);
    for (size_t i = 0 ; i < map.size() ; ++i) {
      map[i].assign(size, 0);
    } 
    center[0] = center[1] = maxRange+1;
    visitedHouseNumber = 0;

    pos[0].assign(pplNb, center[0]);
    pos[1].assign(pplNb, center[1]);
  }

  void placeAt(int x, int y, int idMan) {
    pos[0][idMan] = x + center[0];
    pos[1][idMan] = y + center[1];
    addOneInPlace();
  }
  
  void displace(const char c, int idMan = 0) {
    switch (c) {
    case Char::Up:
      ++pos[0][idMan];
      break;
    case Char::Down:
      --pos[0][idMan];
      break;
    case Char::Left:
      --pos[1][idMan];
      break;
    case Char::Right:
      ++pos[1][idMan];
      break;
    default:
      std::cerr << "Error : char " << c << " not reconize." << std::endl;
      return;
      // exit(EXIT_FAILURE);
    }
    addOneInPlace(idMan);
  }
    
  
  unsigned int visitedHouse() const {
    return visitedHouseNumber;
  }
  
private:
  void addOneInPlace(int idMan = 0) {
    if (!map[pos[0][idMan]][pos[1][idMan]]) {
      ++visitedHouseNumber;
    }
    ++map[pos[0][idMan]][pos[1][idMan]];
  }

};


void howManyHouseSantaVisit(const std::string& fileName, bool withRoboSanta = false);

/** \brief template */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::cout << "Hello Santa !" << std::endl;
    howManyHouseSantaVisit(argv[1]);
    howManyHouseSantaVisit(argv[1], true);
  }
  else {
    std::cout << "Wrong number of args." << std::endl;
    std::cout << "Usage : " << std::endl << argv[0] << " file" << std::endl;
  }
  return EXIT_SUCCESS;
}

void howManyHouseSantaVisit(const std::string& fileName, bool withRoboSanta) {
  std::ifstream inFile (fileName);
  if (inFile.is_open()) {
    unsigned int maxRange = 0;
    for (char c ; inFile.get(c) ; ++maxRange);
      
    const int idSanta = 0;
    const int idRobot = 1;
    map2D map(maxRange, 2);
    map.placeAt(0, 0, idSanta);   
    map.placeAt(0, 0, idRobot);   
    
    inFile.clear();
    inFile.seekg(0, inFile.beg);
    for (char c ; inFile.get(c) ;) {
      map.displace(c, idSanta);
      if (withRoboSanta && inFile.get(c)) {
	map.displace(c, idRobot);
      }
    }
    
    std::cout << "Santa" << ((withRoboSanta) ? " and Robo-Santa " : " ") << "have visited " << map.visitedHouse() << " houses." << std::endl;
  }
  else {
    std::cout << "Unable to open file : " << fileName;
    exit(EXIT_FAILURE);
  }
}

