#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , power; std::cin >> n >> power;

    std::vector<unsigned long long> info(n) , require(n);
    unsigned long long sum = 0 , curr = power;

    for (int i = 0 ; i < n ; i++) std::cin >> info[i];
    for (int i = 0 ; i < n ; i++) std::cin >> require[i];

    for (int i = n-1 ; i >= 0 ; i--) {
        if (info[i] == 0 && curr >= require[i]) {
            sum += 1ULL << i;
            curr -= require[i];
        } else if (info[i] == 1) {
            sum += 1ULL << i;
        }
    }

    std::cout << sum;
}