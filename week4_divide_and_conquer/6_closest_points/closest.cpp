#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using std::cout;
using std::endl;
using std::min;
using std::pair;
using std::string;
using std::vector;

//#define DEBUG
#ifdef DEBUG
#define pout cout
#else
#define pout 0 && cout
#endif
int debug = 1;

typedef struct point
{
  int x;
  int y;
} Point;

//distance between two points
double dist(Point p1, Point p2)
{
  double x = (double)p1.x - p2.x;
  double y = (double)p1.y - p2.y;
  x *= x;
  y *= y;
  double sq = sqrt(x + y);
  return sq;
}

auto xCompare = [](Point p1, Point p2) {
  return p1.x < p2.x;
};

auto yCompare = [](Point p1, Point p2) {
  return p1.y < p2.y;
};
double bfDist(vector<Point> points, int left, int right)
{
  double min;
  if (right - left == 2)
  {
    min = dist(points[left], points[left + 1]);
  }
  else
  {
    double d1 = dist(points[left], points[left + 1]);
    double d2 = dist(points[left], points[left + 2]);
    double d3 = dist(points[left + 1], points[left + 2]);
    min = std::min(d1, std::min(d2, d3));
  }
  return min;
}
double minimal_distance(vector<Point> points, int left, int right)
{
  pout << endl;
  int mid = (right + left) / 2;
  pout << "Left:" << left << " right:" << right << " mid:" << mid << endl;
  for (auto i = left; i < right; i++)
  {
    pout << points[i].x << "," << points[i].y << " ";
  }
  pout << endl;

  if (right - left <= 3)
  {
    double temp = bfDist(points, left, right);
    pout << "(right - left <= 3):" << ((right - left)) << " min Dist:" << temp << endl;
    return temp;
  }
  double d1 = minimal_distance(points, left, mid);
  double d2 = minimal_distance(points, mid, right);
  double d = std::min(d1, d2);

  pout << "d1:" << d1 << " d2:" << d2 << " d(min(d1,d2):" << d << endl;

  vector<Point> filteredPoints;
  // filter points which are less than d from mid
  pout << "Filtered y array ";
  for (auto i = left; i < right; i++)
  {
    if (abs(points[i].x - points[mid - 1].x) < d)
    {
      filteredPoints.push_back(points[i]);
      pout << points[i].x << "," << points[i].y << " ";
    }
  }
  pout << endl;

  std::sort(filteredPoints.begin(), filteredPoints.end(), yCompare);

  pout << "After y sort" << endl;
  for (auto i = 0; i < filteredPoints.size(); i++)
  {
    pout << filteredPoints[i].x << "," << filteredPoints[i].y << " ";
  }

  pout << endl;
  double dFiltered = d;
  signed int s = filteredPoints.size();
  pout << "Dist between each filtered point\n";
  for (int i = 0; i < s - 1; i++)
  {
    for (size_t j = i + 1; j < s; j++)
    {
      double temp = dist(filteredPoints[i], filteredPoints[j]);
      pout << filteredPoints[i].x << "," << filteredPoints[i].y << " " << filteredPoints[j].x << "," << filteredPoints[j].y << " dist:" << temp << endl;
      if (temp < dFiltered)
        dFiltered = temp;
    }
  }

  pout << "d:" << d << " dFiltered:" << dFiltered << " min:" << std::min(d, dFiltered);
  return std::min(d, dFiltered);
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
