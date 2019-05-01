#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b)
{

  int matrix[a.size() + 1][b.size() + 1];

  for (int i = 0; i <= a.size(); i++)
  {
    matrix[i][0] = 0;
  }
  for (int i = 0; i <= b.size(); i++)
  {
    matrix[0][i] = 0;
  }

  for (int j = 1; j <= b.size(); j++)
  {
    int alreadyMatched = 0;
    for (int i = 1; i <= a.size(); i++)
    {
      int temp = std::max(matrix[i - 1][j - 1], std::max(matrix[i][j - 1], matrix[i - 1][j]));

      if (a[i - 1] == b[j - 1] &&
          !alreadyMatched)
      {
        temp++;
        alreadyMatched = 1;
      }

      matrix[i][j] = temp;
    }
  }
  return matrix[a.size()][b.size()];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
