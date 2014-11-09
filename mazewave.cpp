#include "mazewave.hpp"
#include <queue>

void MazeWave::Create(cv::Point2i start, bool isShow) {
  std::queue<cv::Point2i> cells_queue;
  cells_queue.push(start);
  isShow_ = isShow;

  while (!cells_queue.empty()) {
    cv::Point2i current_cell = cells_queue.front();
    cells_queue.pop();

    /// Mark cell as visited
    if (isMoveCorrect(current_cell)) {
      maze_struct_(current_cell.y, current_cell.x) = 100;

      DrawCell(current_cell * block_size);
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
