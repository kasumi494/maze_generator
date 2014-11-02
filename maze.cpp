#include "maze.hpp"
#include <iostream>
#include <algorithm>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

Maze::Maze(int rows, int cols) {
  maze_ = cv::Mat_<uchar>(cols * block_size, rows * block_size);
  maze_struct_ = cv::Mat_<uchar>(cols, rows);
}

void Maze::Create(bool isShow) {
  cv::Point2i start_point(0, 0);

  Wave(start_point, delta_[2]);

  if (isShow) Display();
}

void Maze::Display() {
  cv::imshow("Maze", maze_);
  cv::waitKey(1);
}

void Maze::DrawCell(cv::Point2i point, cv::Scalar color) {
  cv::rectangle(maze_, cv::Rect(point.x, point.y, block_size, block_size),
                color, -1);
}

void Maze::Wave(cv::Point2i point, cv::Point2i delta) {
  step_count++;
  cv::Point2i new_point = point + delta;

  if (isMoveCorrect(new_point)) {
    /// Mark cell as visited
    maze_struct_(new_point.y, new_point.x) = 100;
    DrawCell(new_point * (int)block_size);

    /// Mark neibours
    for (auto x : delta_) {
      cv::Point2i tmp = new_point + x;
      if (isMoveCorrect(tmp)) {
        if (maze_struct_(tmp.y, tmp.x) != 100) {
          maze_struct_(tmp.y, tmp.x)++;
          DrawCell(tmp * (int)block_size, cv::Scalar(100, 100, 100));
        }
      }
    }

    Display();

    std::vector<cv::Point2i> curr_delta(delta_);
    std::random_shuffle(curr_delta.begin(), curr_delta.end());
    for (auto x : curr_delta) {
      Wave(new_point, x);
    }
  }
}

bool Maze::isMoveCorrect(cv::Point2i point) {
  if ((point.y < maze_struct_.rows) && (point.y >= 0) &&
      (point.x < maze_struct_.cols) && (point.x >= 0)) {
    if (maze_struct_(point.y, point.x) < 2) {
      return true;
    }
  }

  return false;
}
