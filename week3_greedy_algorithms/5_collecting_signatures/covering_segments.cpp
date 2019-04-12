#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

bool pointInLine(Segment s, int point)
{
  if (point >= s.start && point <= s.end)
    return true;
  return false;
}
vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;

  std::sort(segments.begin(), segments.end(),
            [](Segment a, Segment b) {
              if (a.end < b.end)
                return true;
              else if (a.end == b.end)
              {
                if (a.start < b.start)
                  return true;
              }
              return false;
            });

  while (segments.size() != 0)
  {
    Segment s = segments.front();
    int currentPoint = s.end;
    points.push_back(s.end);

    segments.erase(std::remove_if(segments.begin(), segments.end(), [currentPoint](Segment s) { return pointInLine(s, currentPoint); }), segments.end());
  }
  /* Print all sorted points
  for (size_t i = 0; i < segments.size(); ++i)
  {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
