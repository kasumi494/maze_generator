#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <opencv2/core/core.hpp>

class Maze {
public:
  Maze(int rows = 100, int cols = 80);
  ~Maze() {}

  void Create(bool isShow);
  void Display();

private:
  void DrawCell(cv::Point2i point, cv::Scalar color = cv::Scalar(255, 255, 255));
  void Wave(cv::Point2i point, cv::Point2i delta);
  bool isMoveCorrect(cv::Point2i point);

  cv::Mat_<uchar> maze_;
  cv::Mat_<uchar> maze_struct_;

  const std::vector<cv::Point2i> delta_ = {
    cv::Point2i(-1, 0), cv::Point2i(0, -1),
    cv::Point2i( 1, 0), cv::Point2i(0,  1)
  };

  const std::vector<cv::Point2i> delta_n_ = {
    cv::Point2i(-1, 0), cv::Point2i(0, -1),
    cv::Point2i( 1, 0), cv::Point2i(0,  1),
    cv::Point2i(-1, -1), cv::Point2i(1,  -1),
    cv::Point2i( -1, 1), cv::Point2i(1,  1)
  };

  const size_t block_size = 10;
};

#endif  // MAZE_H
