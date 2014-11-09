#include <iostream>
#include <memory>
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

  std::unique_ptr<Maze> maze;
  switch (std::atoi(argv[1])) {
    default: case 0:
      maze = std::unique_ptr<Maze>(new MazeRecursion());
      break;
    case 1:
      maze = std::unique_ptr<Maze>(new MazeWave());
      break;
  }

  maze->Create(cv::Point2i(0, 0), true);

  cv::waitKey(0);
  return 0;
}
