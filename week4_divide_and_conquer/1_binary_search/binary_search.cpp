#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int binary_search(const vector<int> &a, int x)
{
  int left = 0, right = (int)a.size();

  //write your code here
  if (right == 0)
    return -1;
  int mid = (left + right) / 2;
  //cout << left << right << mid << a[mid] << endl;
  if (a[mid] == x)
    return mid;
  if (a[mid] > x)
  {
    vector<int> b(a.begin(), a.begin() + mid);
    int n = binary_search(b, x);

    return n;
  }
  else
  {
    vector<int> b(a.begin() + mid + 1, a.end());
    int n = binary_search(b, x);
    if (n != -1)
      return n + mid + 1;
    else
      return n;
  }
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n = 5;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }

  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
