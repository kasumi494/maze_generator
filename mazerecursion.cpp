#include "mazerecursion.hpp"
#include <algorithm>

void MazeRecursion::Create(bool isShow) {
  isShow_ = isShow;

  cv::Point2i start_point(0, 0);
  Wave(start_point, delta_[2]);
}

void MazeRecursion::Wave(cv::Point2i point, cv::Point2i delta) {
  cv::Point2i new_point = point + delta;

  if (isMoveCorrect(new_point)) {
    /// Mark cell as visited
    maze_struct_(new_point.y, new_point.x) = 100;
    DrawCell(new_point * (int)block_size);

    /// Mark neibours
    MarkNeibours(new_point);

    if (isShow_) Display();

    /// Select next cell
    std::vector<cv::Point2i> curr_delta(delta_);
    std::random_shuffle(curr_delta.begin(), curr_delta.end());
    for (auto x : curr_delta) {
      Wave(new_point, x);
    }
  }
}
