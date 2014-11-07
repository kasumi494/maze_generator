#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "maze.hpp"

int main()
{
  Maze maze;
//  maze.Create(1);
  maze.WaveQueue(cv::Point2i(0, 0));
  cv::waitKey(0);

  return 0;
}

