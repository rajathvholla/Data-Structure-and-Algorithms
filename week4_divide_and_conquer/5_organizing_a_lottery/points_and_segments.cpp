#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int bin_search(vector<int> &a, int key)
{
  int low = 0;
  int high = a.size() - 1;
  int mid = (low + high) / 2;

  while (low <= high)
  {
    mid = (high + low) / 2;
    if (a[mid] == key)
      return mid;
    if (a[mid] > key)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  if (key > a[mid])
    return mid + 1;
  return mid;
}
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  int i = 0;
  for (auto point : points)
  {
    int starts_before_point = 0;
    int temp = bin_search(starts, point);
    // if point is outside of begin
    if (temp == 0 && point < starts[temp])
    {
    }
    else
    {
      if (point == starts[temp])
        starts_before_point += temp + 1;
      else
        starts_before_point += temp;
    }

    int ends_before_point = 0;
    int temp2 = bin_search(ends, point);

    // if point is outside of begin
    if (temp2 == 0 && point <= ends[temp2])
    {
    }
    else
    {

      ends_before_point += temp2;
    }
    //if point is outside of begin
    // if point is inside
    cnt[i++] = starts_before_point - ends_before_point;
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end());

  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}