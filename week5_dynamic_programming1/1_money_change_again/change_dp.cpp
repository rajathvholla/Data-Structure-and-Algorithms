#include <iostream>
#include <unordered_map>
using namespace ::std;

unordered_map<int, int> T;
int get_change(int m)
{
  //write your code here
  if (m == 0)
    return 0;
  if (T.find(m) != T.end())
    return T[m];

  int t1 = 1 + get_change(m - 1);
  int t2 = 1 + get_change(m - 3);
  int t3 = 1 + get_change(m - 4);

  int t4 = std::min(t1, std::min(t2, t3));
  T[m] = t4;
  return T[m];
}

int main()
{
  int m;
  T[0] = 0;
  T[1] = 1;
  T[2] = 2;
  T[3] = 1;
  T[4] = 1;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
