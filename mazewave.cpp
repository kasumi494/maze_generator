#include "mazewave.hpp"
#include <queue>

void MazeWave::Create(cv::Point2i start) {
  int magic_const = 6;

  std::queue<cv::Point2i> cells_queue;
  cells_queue.push(start + cv::Point2i(1, 1));

  while (!cells_queue.empty()) {
    cv::Point2i current_cell = cells_queue.front();
    cells_queue.pop();

    if (IsMoveCorrect(current_cell)) {
      /// Mark cell as visited
      maze_struct_(current_cell.y, current_cell.x) = CellState::PATH;
      DrawCell(current_cell * kBlockSize);

      MarkNeibours(current_cell);

      /// Select next cells
      for (int i = 0; i < magic_const; ++i) {
        size_t index = rand() % 4;
        cv::Point2i neibour_cell = current_cell + kDeltas_.at(index);
        cells_queue.push(neibour_cell);
      }
    }

    if (isShow_)  Display(1);
  }
}
