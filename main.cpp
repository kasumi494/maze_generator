#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "mazerecursion.hpp"
#include "mazewave.hpp"

void help() {
  std::cout << "Usage: [path_to_progarm] [mode]\n\n"
            << "Available modes: \n"
            << "0: wave with recursion\n"
            << "1: wave with queue\n";
}

int main(int argc, char** argv) {
  if (argc < 2) {
    help();
    return -1;
  }

  Maze* maze;
  switch (std::atoi(argv[1])) {
    default: case 0:
      maze = new MazeRecursion();
      break;
    case 1:
      maze = new MazeWave();
      break;
  }

  maze->Create(cv::Point2i(0, 0), true);

  cv::waitKey(0);
  delete maze;

  return 0;
}
