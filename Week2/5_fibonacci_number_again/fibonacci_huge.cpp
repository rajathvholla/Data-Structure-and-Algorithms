#include <iostream>
#include <vector>
using namespace std;
unsigned long long get_fibonacci_huge_naive(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    
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

int main() {
    unsigned long long n, m;
    std::cin>>n>>m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
