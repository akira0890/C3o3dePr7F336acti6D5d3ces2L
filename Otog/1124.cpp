#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,t; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int mins1 = 2e9+100000, maxs1 = 0;
    int mins2 = 2e9+100000, maxs2 = 0;
    for (int i = 1 ; i <= n ; i++) {
        int val1 = v[i-1] + i;
        int val2 = v[i-1] - i;
        mins1 = std::min(mins1 , val1);
        mins2 = std::min(mins2 , val2);
        maxs1 = std::max(maxs1 , val1);
        maxs2 = std::max(maxs2 , val2);
    }

    std::cout << std::max(maxs1 - mins1 , maxs2 - mins2);
}