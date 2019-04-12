#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> ans;
  if (n == 0)
    return ans;

  int current_num = 1, prev_num = 0;

  while (n - current_num >= 0)
  {
    n = n - current_num;
    ans.push_back((n <= current_num) ? n + current_num : current_num);
    current_num++;
  }

  return ans;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
