#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <climits>
using namespace std;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
    {
      n /= 3;
    }
    else if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

std::unordered_map<int, std::pair<int, int>> dict;
vector<int> sequence;
vector<int> optimal_sequence_mine(int n)
{
  std::vector<int> sequence;
  while (n > 1)
  {
    sequence.push_back(n);
    n = dict[n].second;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

void primitive_calculator_iter(int n)
{

  int temp = 2;

  while (temp <= n)
  {
    int t3 = INT_MAX - 1;
    int t2 = INT_MAX - 1;
    int t1 = INT_MAX - 1;

    if (temp % 3 == 0)
    {
      t3 = dict[temp / 3].first + 1;
    }
    if (temp % 2 == 0)
    {
      t2 = dict[temp / 2].first + 1;
    }
    t1 = dict[temp - 1].first + 1;

    int t = std::min(t3, std::min(t2, t1));
    if (t == t3)
    {
      //cout << temp << " " << t << " " << temp / 3 << endl;
      dict[temp] = make_pair(t, temp / 3);
    }
    else if (t == t2)
    {
      //cout << temp << " " << t << " " << temp / 2 << endl;
      dict[temp] = make_pair(t, temp / 2);
    }
    else
    {
      //cout << temp << " " << t << " " << temp - 1 << endl;
      dict[temp] = make_pair(t, temp - 1);
    }
    temp = temp + 1;
  }
}
int primitive_calculator(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 0;

  if (dict.find(n) != dict.end())
  {
    return dict[n].first;
  }

  int t3 = INT_MAX - 1;
  int t2 = INT_MAX - 1;
  int t1 = INT_MAX - 1;
  if (n % 3 == 0)
  {
    t3 = primitive_calculator(n / 3) + 1;
  }
  if (n % 2 == 0)
  {
    t2 = primitive_calculator(n / 2) + 1;
  }
  t1 = primitive_calculator(n - 1) + 1;

  int t = std::min(t3, std::min(t2, t1));

  if (t == t3)
  {
    //cout << n << " " << t << " " << n / 3 << endl;
    dict[n] = make_pair(t, n / 3);
  }
  else if (t == t3)
  {
    //cout << n << " " << t << " " << n / 2 << endl;
    dict[n] = make_pair(t, n / 2);
  }
  else
  {
    //cout << n << " " << t << " " << n - 1 << endl;
    dict[n] = make_pair(t, n - 1);
  }

  return t;
}

int main()
{
  int n;
  std::cin >> n;
  dict[1] = make_pair(0, 1);
  //dict[2] = make_pair(1, 1);
  //dict[3] = make_pair(1, 1);
  primitive_calculator_iter(n);
  vector<int> sequence = optimal_sequence_mine(n);

  //vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
