#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <opencv2/core/core.hpp>

class Maze {
public:
  Maze(int rows = 100, int cols = 80);
  virtual ~Maze() {}

  virtual void Create(cv::Point2i start = cv::Point2i(0, 0),
                      bool isShow = false) = 0;
  void Display();

protected:
  void DrawCell(cv::Point2i point, cv::Scalar color = cv::Scalar(255, 255, 255)); 
  bool isMoveCorrect(cv::Point2i point);
  void MarkNeibours(cv::Point2i cell_coordinate);

  cv::Mat_<uchar> maze_;
  cv::Mat_<uchar> maze_struct_;

  const std::vector<cv::Point2i> delta_n_ = {
    cv::Point2i(-1, 0), cv::Point2i(0, -1),
    cv::Point2i( 1, 0), cv::Point2i(0,  1),
    cv::Point2i(-1, -1), cv::Point2i(1,  -1),
    cv::Point2i( -1, 1), cv::Point2i(1,  1)
  };

  std::vector<int> indexes_ = {0, 1, 2, 3, 4, 5, 6, 7};
  const int block_size = 10;

  enum CellState : uchar {MAX_NEIBOURS = 3, PATH = 100, BORDER = 200};
};

#endif  // MAZE_H
