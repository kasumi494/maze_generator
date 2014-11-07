#ifndef MAZEWAVE_HPP
#define MAZEWAVE_HPP

#include "maze.hpp"

class MazeWave : public Maze {
 public:
  void Create(bool isShow);

 private:
  bool isShow_;
};

#endif  // MAZEWAVE_HPP
