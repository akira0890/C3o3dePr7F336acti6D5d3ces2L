#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    unsigned long long total = 0,sum = 0;
    int n;

    std::cin >> n >> total;

    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int l = 0 , range = 1000000;
    for (int r = 0 ; r < n ; r++) {
        if (sum < total) {
            sum += v[r];
        }

        while (sum >= total) {
            range = std::min(range , r-l+1);
            sum -= v[l];
            l++;
        }
    }

    std::cout << range;
}