/**
 *  map2D.cpp
 *  Solve day 3 problem of : 
 *  http://adventofcode.com/day/3
 * 
 *  Author : Benjamin Lux
 *  Date   : Dec. 2015
 *
 * Note : version 2, more space efficient.
 **/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <set>

namespace Char {
  const char Up    = '^';
  const char Down  = 'v';
  const char Left  = '<';
  const char Right = '>';
}

struct Position {
  int x, y;
  Position() : x(0), y(0) {}
  void up()    { y++; }
  void down()  { y--; }
  void right() { x++; }
  void left()  { x--; }
  bool operator()(Position p1, Position p2) const { 
    return ((p1.x<p2.x) || ((p1.x==p2.x) && (p1.y<p2.y))); 
  }
};

bool operator<(const Position& p1, const Position& p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}


class map2D {
  std::set<Position> visitedHouses;
  std::vector<Position> pos;

public:
  map2D(unsigned int pplNb = 1) {
    pos.resize(pplNb);
    visitedHouses.insert(pos[0]);
  }

  void displace(const char c, int idMan = 0) {
    Position& position = pos[idMan];
    switch (c) {
    case Char::Up:
      position.up();
      break;
    case Char::Down:
      position.down();
      break;
    case Char::Left:
      position.left();
      break;
    case Char::Right:
      position.right();
      break;
    default:
      return;
    }
    visitedHouses.insert(position);
  }
    
  unsigned int visitedHouse() const {
    return visitedHouses.size();
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
    map2D map(2);
    const int idSanta = 0;
    const int idRobot = 1;
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

