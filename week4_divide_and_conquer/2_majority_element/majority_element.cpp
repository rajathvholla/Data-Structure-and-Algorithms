#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
  {
    return a[left];
  }
  //write your code here
  int mid = (left + right) / 2;
  int left_num = get_majority_element(a, left, mid);
  int right_num = get_majority_element(a, mid, right);

  if (right_num == -1 && left_num == -1)
    return -1;
  int left_count = 0;
  if (left_num != -1)
  {

    for (int i = left; i < right; i++)
    {
      if (a[i] == left_num)
        left_count++;
    }
  }

  int right_count = 0;
  if (right_num != -1)
  {
    for (int i = left; i < right; i++)
    {
      if (a[i] == right_num)
        right_count++;
    }
  }

  if (left_count >= (right - left) / 2 + 1)
    return left_num;
  if (right_count >= (right - left) / 2 + 1)
    return right_num;

  return -1;
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
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
