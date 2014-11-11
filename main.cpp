#include <iostream>
#include <memory>
#include <opencv2/highgui/highgui.hpp>

#include "mazerecursion.hpp"
#include "mazewave.hpp"

void help() {
  std::cout << "Usage: [path_to_progarm] [mode] [isShow {y, n}]\n\n"
            << "Available modes: \n"
            << "0: wave with recursion\n"
            << "1: wave with queue\n";
}

int main(int argc, char** argv) {
  if (argc < 3) {
    help();
    return -1;
  }

  bool isShow = (std::string(argv[2]) == "y");

  std::unique_ptr<Maze> maze;
  switch (std::atoi(argv[1])) {
    default: case 0:
      maze = std::unique_ptr<Maze>(new MazeRecursion(100, 80, isShow));
      break;
    case 1:
      maze = std::unique_ptr<Maze>(new MazeWave(100, 80, isShow));
      break;
  }

  maze->Create(cv::Point2i(0, 0));
  maze->Display();

  return 0;
}
