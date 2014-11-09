#include "maze.hpp"
#include <cstdlib>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

Maze::Maze(int rows, int cols) {
  srand(time(NULL));

  maze_ = cv::Mat_<uchar>(cols * block_size, rows * block_size, uchar(0));
  maze_struct_ = cv::Mat_<uchar>(cols, rows, uchar(0));
}

void Maze::Display() {
  cv::imshow("Maze", maze_);
  cv::waitKey(1);
}

void Maze::DrawCell(cv::Point2i point, cv::Scalar color) {
  cv::rectangle(maze_, cv::Rect(point.x, point.y, block_size, block_size),
                color, -1);
}

bool Maze::isMoveCorrect(cv::Point2i point) {
  auto is_in_range = [this](cv::Point2i point) {
    return ((point.y < maze_struct_.rows) && (point.y >= 0) &&
            (point.x < maze_struct_.cols) && (point.x >= 0));
  };

  if (is_in_range(point)) {
    /// It isn't a path and have < 3 path in the surrounding area
    if (maze_struct_(point.y, point.x) < 3) {
      return true;
    }
  }

  return false;
}

void Maze::MarkNeibours(cv::Point2i cell_coordinate) {
  for (auto x : delta_n_) {
    cv::Point2i tmp = cell_coordinate + x;

    if (isMoveCorrect(tmp)) {
      if (maze_struct_(tmp.y, tmp.x) != 100) {
        maze_struct_(tmp.y, tmp.x)++;
        DrawCell(tmp * block_size, cv::Scalar(100, 100, 100));
      }
    }
  }
}
