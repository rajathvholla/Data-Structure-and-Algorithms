#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i)
  {
    if (current_weight + w[i] <= W)
    {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int frac_knap(int W, const vector<int> &weights)
{
  int mat[weights.size() + 1][W + 1];
  for (int i = 0; i <= weights.size(); i++)
    mat[i][0] = 0;
  for (int i = 0; i <= W; i++)
    mat[0][i] = 0;

  int running_weight = 0;
  for (int i = 1; i <= weights.size(); i++)
  {
    for (int w = 1; w <= W; w++)
    {
      mat[w][i] = mat[w][i - 1];
      if (weights[i] <= w)
      {
        int temp = mat[weights[i] - w][i - 1] + weights[i];
        if (mat[w][i] < temp)
          mat[w][i] = temp;
      }
    }
    return mat[W][weights.size()];
  }
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << frac_knap(W, w) << '\n';
}
