#include "mazerecursion.hpp"
#include <algorithm>

void MazeRecursion::Create(cv::Point2i start, bool isShow) {
  isShow_ = isShow;
  Wave(start + cv::Point2i(1, 1), delta_n_[2]);
}

void MazeRecursion::Wave(cv::Point2i point, cv::Point2i delta) {
  cv::Point2i new_point = point + delta;

  if (isMoveCorrect(new_point)) {
    /// Mark cell as visited
    maze_struct_(new_point.y, new_point.x) = CellState::PATH;
    DrawCell(new_point * block_size);

    MarkNeibours(new_point);

    if (isShow_) Display();

    /// Select next cell
    std::vector<int> delta_indexes(indexes_.begin(), indexes_.begin() + 4);
    std::random_shuffle(delta_indexes.begin(), delta_indexes.end());
    for (auto i : delta_indexes) {
      Wave(new_point, delta_n_.at(i));
    }
  }
}
