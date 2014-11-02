#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "maze.hpp"

int main()
{
  Maze maze;
  maze.Create(1);
  cv::waitKey(0);

  return 0;
}

