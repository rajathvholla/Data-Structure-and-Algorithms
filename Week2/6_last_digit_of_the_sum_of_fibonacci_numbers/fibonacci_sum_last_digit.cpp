#include <iostream>
#include<vector> 
using namespace std;
int fibonacci_sum_naive(unsigned long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long sum      = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current %10;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(unsigned long long n) {
    if (n <= 1)
        return n;
    vector<int> table;
        int a=0 ,b=1,t;
        int table_sum = 1;
        table.push_back(0);
        table.push_back(1);

        for(int i=2;i<=60;i++)
        {
            t = (a+b)%10;
            a=b;b=t;
            table.push_back(b);
            table_sum =( b + table_sum)%10;
        }


        unsigned long ans = ((n/60)*table_sum)%10;
        for(int i=0;i<=n%60;i++)
            ans=(ans+table[i])%10;;


    return ans%10;    
}
int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
