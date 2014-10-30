#include "maze.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

Maze::Maze(int rows, int cols)
{
  maze_ = cv::Mat_<uchar>(rows * block_size, cols * block_size);
  maze_struct_ = cv::Mat_<uchar>(rows, cols);
}

void Maze::Create(bool isShow)
{
  for(int x = 0; x < 10; ++x) {
    DrawEmptyCell(x * block_size, 5 * block_size);
  }

  Display();
}

void Maze::Display()
{
  cv::imshow("Maze", maze_);
  cv::waitKey(0);
}

void Maze::DrawEmptyCell(int x, int y)
{
  cv::rectangle(maze_, cv::Rect(x, y, block_size, block_size),
                cv::Scalar(255, 255, 255), -1);
}
