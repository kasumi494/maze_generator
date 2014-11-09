#ifndef MAZERECURSION_HPP
#define MAZERECURSION_HPP

#include "maze.hpp"

class MazeRecursion : public Maze {
 public:
  void Create(cv::Point2i start = cv::Point2i(0, 0), bool isShow = false);

 private:
  void Wave(cv::Point2i point, cv::Point2i delta);

  bool isShow_;
};

#endif  // MAZERECURSION_HPP
