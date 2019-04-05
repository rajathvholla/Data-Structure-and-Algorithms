#include <iostream>
#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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
long long lcm_fast(int a,int b)
{
    return ((long long)a*b)/(long long)gcd_fast(a,b);
}

void test()
{
  int a, b;
  for (int n = 0; n < 100; ++n)
  {   
      
      a = std::rand() , b = std::rand();
      long long t = lcm_fast(a,b),t2 = lcm_naive(a,b);
      std::cout<<a<<" "<<b<<" fast:"<<t<<" slow:"<<t2<<std::endl;
      assert(t==t2);
  }
}
int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
   
  return 0;
}
