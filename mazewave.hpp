#ifndef MAZEWAVE_HPP
#define MAZEWAVE_HPP

#include "maze.hpp"

class MazeWave : public Maze {
 public:
  void Create(cv::Point2i start = cv::Point2i(0, 0), bool isShow = false);

 private:
  bool isShow_;
};

#endif  // MAZEWAVE_HPP
