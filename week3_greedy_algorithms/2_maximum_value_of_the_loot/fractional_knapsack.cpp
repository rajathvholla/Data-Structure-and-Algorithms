#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  vector<std::tuple<double, int, int>> objects;

  for (auto weights_it = weights.begin(), values_it = values.begin(); weights_it != weights.end(); weights_it++, values_it++)
  {
    objects.push_back(std::make_tuple(((double)(*values_it)) / (*weights_it), *values_it, *weights_it));
  }
  sort(objects.begin(), objects.end(), [](std::tuple<double, int, int> a, std::tuple<double, int, int> b) { return get<0>(a) > get<0>(b); });

  int idx = 0;
  while (capacity != 0 && idx < objects.size())
  {
    double idx_val_per_weight;
    int idx_value;
    int idx_weight;
    std::tie(idx_val_per_weight, idx_value, idx_weight) = objects[idx];
    int quantity = (capacity > idx_weight) ? idx_weight : capacity;

    value += (double)(quantity * idx_val_per_weight);
    capacity -= quantity;
    idx++;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  //n = 1;
  //capacity = 10;
  vector<int> values(n);  //{60, 100, 120};
  vector<int> weights(n); //{20, 50, 30};
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
