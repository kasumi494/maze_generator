#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "mazerecursion.hpp"
#include "mazewave.hpp"

int main()
{
//  MazeRecursion maze;
  MazeWave maze;
  maze.Create(1);

  cv::waitKey(0);
  return 0;
}

