#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

string largest_number(vector<string> a)
{

  std::sort(a.begin(), a.end(),
            [](string a, string b) {
              int aIdx = 0, bIdx = 0;
              while (!(aIdx == a.size() - 1 && bIdx == b.size() - 1))
              {
                if (a.c_str()[aIdx] > b.c_str()[bIdx])
                  return true;
                else if (a.c_str()[aIdx] < b.c_str()[bIdx])
                  return false;
                if (aIdx != a.size() - 1)
                  aIdx++;
                if (bIdx != b.size() - 1)
                  bIdx++;
              }
              if (a.c_str()[aIdx] > b.c_str()[bIdx])
                return true;
              return false;
            });
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

string largest_number_diff(vector<string> a)
{

  std::sort(a.begin(), a.end(),
            [](string a, string b) {
              if (a + b > b + a)
                return true;
              return false;
            });
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}
int main()
{
  int m = 10000;

  for (int i = 0; i < m; i++)
  {
    int n = rand() % 100000;
    //std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
      a[i] = std::to_string(rand());
    }
    string ab = largest_number(a);
    string b = largest_number(a);
    if (ab != b)
    {
      for (auto s : a)
      {
        std::cout << s << std::endl;
      }
      std::cout << "Non working : " << ab << std::endl;
      std::cout << "Working : " << b << std::endl;
      break;
    }
  }
}
