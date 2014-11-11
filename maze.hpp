#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <opencv2/core/core.hpp>

class Maze {
public:
  Maze(int rows, int cols, bool isShow);
  virtual ~Maze() {}

  void Display(uint delay = 0);
  virtual void Create(cv::Point2i start = cv::Point2i(0, 0)) = 0;

protected:
  void DrawCell(cv::Point2i point, cv::Scalar color = cv::Scalar(255, 255, 255)); 
  void MarkNeibours(cv::Point2i point);
  bool IsMoveCorrect(cv::Point2i point);

  bool isShow_;
  cv::Mat_<uchar> maze_;
  cv::Mat_<uchar> maze_struct_;

  const std::vector<cv::Point2i> kDeltas_ = {
    cv::Point2i(-1, 0), cv::Point2i(0, -1),
    cv::Point2i( 1, 0), cv::Point2i(0,  1),
    cv::Point2i(-1, -1), cv::Point2i(1,  -1),
    cv::Point2i( -1, 1), cv::Point2i(1,  1)
  };

  const int kBlockSize = 10;
  enum CellState : uchar {MAX_NEIBOURS = 3, PATH = 100, BORDER = 200};
};

#endif  // MAZE_H
