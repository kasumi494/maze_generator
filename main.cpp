#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "mazerecursion.hpp"
#include "mazewave.hpp"

int main()
{
  Maze *maze;
  maze = new MazeRecursion();
//  maze = new MazeWave();

  maze->Create(cv::Point2i(0, 0), true);

  cv::waitKey(0);
  delete maze;

  return 0;
}

