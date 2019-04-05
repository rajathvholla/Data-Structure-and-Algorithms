#include <iostream>
#include <vector>
#include<algorithm>

long long MaxPairwiseProduct(std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    //Find the first and second element

    std::sort(numbers.begin(),numbers.end(),[](int a,int b){return a>b;});

    return ((long long)(numbers[0]))*numbers[1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
