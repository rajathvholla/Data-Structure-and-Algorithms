#include <iostream>


int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) 
{
  int temp;
  if(a < b)
  {
    std::swap(a,b);
  }

  while(b)
  {
    a = a%b;
    std::swap(a,b);
  }
  return a;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  //a=14159572,b= 63967072;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
