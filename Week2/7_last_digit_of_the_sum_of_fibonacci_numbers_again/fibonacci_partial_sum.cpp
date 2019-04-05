#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
int ans(unsigned long long from, unsigned long long to)
{
    int ans = (get_fibonacci_pisano(to+2, 10) + 10 - get_fibonacci_pisano(from+1, 10)) % 10;
    return  ans;
}
int main() {
    int from, to;
    std::cin >> from >> to;
    //from = 10, to = 10;
    std::cout << ans(from, to) << '\n';
}
