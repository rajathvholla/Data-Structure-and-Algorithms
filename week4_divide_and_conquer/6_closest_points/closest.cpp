#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::min;
using std::pair;
using std::string;
using std::vector;
typedef struct point
{
  int x;
  int y;
} Point;

//distance between two points
double dist(Point p1, Point p2)
{
  return abs(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

auto xCompare = [](Point p1, Point p2) {
  return p1.x < p2.x;
};

auto yCompare = [](Point p1, Point p2) {
  return p1.y < p2.y;
};

double minimal_distance(vector<Point> points, int left, int right)
{

  int mid = (right + left) / 2;
  double d1 = minimal_distance(points, left, mid);
  double d2 = minimal_distance(points, mid, right);
  double d = std::min(d1, d2);

  vector<Point> filteredPoints(right - left);
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<Point> points(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> points[i].x >> points[i].y;
  }
  std::sort(points.begin(), points.end(), xCompare);
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, points.size()) << "\n";
}
