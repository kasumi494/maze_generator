#ifndef MAZE_H
#define MAZE_H

#include <opencv2/core/core.hpp>

class Maze {
public:
  Maze(int rows = 10, int cols = 10);
  ~Maze() {}

  void Create(bool isShow);
  void Display();

private:
  void DrawEmptyCell(int x, int y);

  cv::Mat_<uchar> maze_;
  cv::Mat_<uchar> maze_struct_;

  const size_t block_size = 40;
};

#endif // MAZE_H
