#include <iostream>
#include <string>

using std::string;

int edit_distance(string str1, string str2)
{
  //write your code here
  //if (str1 == str2)
  //return 0;
  /*
  struct matrix
  {
    int val = 0;
    int ins = 0;
    int del = 0;
    int match = 0;
    int mismatch = 0;
  } matrix[str1.size() + 1][str2.size() + 1];
  */
  int matrixval[str1.size() + 1][str2.size() + 1] = {0};
  int matrixins[str1.size() + 1][str2.size() + 1] = {0};
  int matrixdel[str1.size() + 1][str2.size() + 1] = {0};
  int matrixmatch[str1.size() + 1][str2.size() + 1] = {0};
  int matrixmismatch[str1.size() + 1][str2.size() + 1] = {0};
  for (int i = 0; i <= str1.size(); i++)
  {
    matrixval[i][0] = i;
    matrixdel[i][0] = 1;
  }

  for (int i = 0; i <= str2.size(); i++)
  {
    matrixval[0][i] = i;
    matrixins[0][i] = 1;
  }

  for (int j = 1; j <= str2.size(); j++)
  {
    for (int i = 1; i <= str1.size(); i++)
    {
      int ins = matrixval[i][j - 1] + 1;
      int del = matrixval[i - 1][j] + 1;
      int match = matrixval[i - 1][j - 1];
      int mismatch = matrixval[i - 1][j - 1] + 1;

      if (str1.c_str()[i - 1] == str2.c_str()[j - 1])
      {
        matrixval[i][j] = std::min(ins, std::min(del, match));
        matrixmatch[i][j] = 1;
      }
      else
      {
        matrixval[i][j] = std::min(ins, std::min(del, mismatch));
        matrixmismatch[i][j] = 1;
      }
      if (matrixval[i][j] == ins)
      {
        matrixins[i][j] = 1;
      }
      if (matrixval[i][j] == del)
      {
        matrixdel[i][j] = 1;
      }
    }
  }

  return matrixval[str1.size()][str2.size()];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
