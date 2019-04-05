#include <iostream>

long long sum_of_two_digits(long long first_digit, long long second_digit)
{
    return first_digit + second_digit;
}

int main()
{
    // Change everything to long long
    // Changing it to see if things go good.
    long long a = 0;
    long long b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b);
    return 0;
}
