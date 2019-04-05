#include <iostream>
#include<vector>
using namespace std;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
unsigned long long get_fibonacci_pisano(unsigned long long n, unsigned long long m) {
    
    std::vector<unsigned long long>pisano;
    if (n <= 1)
        return n;

    unsigned long long a = 0;
    unsigned long long b = 1;
    pisano.push_back(0);
    pisano.push_back(1);
    unsigned long long i = 0;
    int f = 0;

    for(i = 0;i<=n; i++)
    {
        unsigned long long t = (a+b)%m;
        a = b;
        b = t;
        pisano.push_back(t % m);
        if( i > 2)
        {
            if ( pisano[i] == 1 && pisano[i-1] == 0)
            {
                f =1;
                break;
            }
        }
    }
    i--;
    if(f)
    return pisano[n%i];
    return pisano[n];
}

int fibonacci_sum_squares_fast(unsigned long long n) 
{
    return (get_fibonacci_pisano(n,10) * get_fibonacci_pisano(n+1,10))%10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    //n = 47;
    std::cout << fibonacci_sum_squares_fast(n);
}
