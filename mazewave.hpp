#ifndef MAZEWAVE_HPP
#define MAZEWAVE_HPP

#include "maze.hpp"

class MazeWave : public Maze {
 public:
  MazeWave(int rows = 100, int cols = 80, bool isShow = true)
      : Maze(rows, cols, isShow) {}

  void Create(cv::Point2i start = cv::Point2i(0, 0));
};

#endif  // MAZEWAVE_HPP
