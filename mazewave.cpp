#include "mazewave.hpp"
#include <queue>
#include <cstdlib>

void MazeWave::Create(bool isShow) {
  std::queue<cv::Point2i> cells_queue;

  /// Start point
  cells_queue.push(cv::Point2i(0, 0));
  isShow_ = isShow;

  while (!cells_queue.empty()) {
    cv::Point2i current_cell = cells_queue.front();
    cells_queue.pop();

    /// Mark cell as visited
    if (isMoveCorrect(current_cell)) {
      maze_struct_(current_cell.y, current_cell.x) = 100;

      DrawCell(current_cell * (int)block_size);
      MarkNeibours(current_cell);

      for (int i = 0; i < 6; ++i) {
        /// Select next cell
        size_t index = rand() % delta_.size();
        cv::Point2i neibour_cell = current_cell + delta_.at(index);
        cells_queue.push(neibour_cell);
      }
    }

    if (isShow_)  Display();
  }
}
