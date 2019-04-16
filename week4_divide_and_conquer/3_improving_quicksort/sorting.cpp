#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::swap;
using std::vector;
int partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
void partition3(vector<int> &a, int l, int r, int *part_start, int *part_end)
{
  int part_element = a[l];

  int j = l;
  int same = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] < part_element)
    {
      j++;
      swap(a[i], a[j]);
      same++;
      if (same > j)
      {

        swap(a[i], a[same]);
      }
    }
    else if (a[i] == part_element)
    {
      same++;
      swap(a[i], a[same]);
    }
  }
  swap(a[l], a[j]);
  *part_start = j;
  *part_end = same;
}
void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int part_start, part_end;
  partition3(a, l, r, &part_start, &part_end);
  //partition3(a, l, r, &left, &right);
  //cout << "l " << l << " r " << r << " left " << left << " right " << right << " partition " << a[left] << endl;
  randomized_quick_sort(a, l, part_start - 1);
  randomized_quick_sort(a, part_end + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
