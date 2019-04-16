#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t right, size_t mid)
{
  long long count = 0;
  size_t i = left;
  size_t j = mid;
  size_t k = 0;
  while (k < left)
  {
    b[k] = a[k];
    k++;
  }
  while (i < mid && j < right)
  {
    if (a[j] < a[i])
    {
      count += (mid - i);
      /*int temp = a[j];
      a.erase(a.begin() + j);
      a.insert(a.begin() + i, temp);
      */
      b[k++] = a[j];
      j++;
    }
    else
    {
      b[k++] = a[i];
      i++;
    }
  }
  while (i < mid)
  {
    b[k++] = a[i++];
  }
  while (j < right)
  {
    b[k++] = a[j++];
  }
  while (k < a.size())
  {
    b[k] = a[k];
    k++;
  }
  a.swap(b);
  return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right <= left + 1)
    return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  number_of_inversions += merge(a, b, left, right, ave);
  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
