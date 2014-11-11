#ifndef MAZERECURSION_HPP
#define MAZERECURSION_HPP

#include "maze.hpp"

class MazeRecursion : public Maze {
 public:
  MazeRecursion(int rows = 100, int cols = 80, bool isShow = true)
      : Maze(rows, cols, isShow) {}

  void Create(cv::Point2i start = cv::Point2i(0, 0));

 private:
  void Wave(cv::Point2i point, cv::Point2i delta);
};

#endif  // MAZERECURSION_HPP
