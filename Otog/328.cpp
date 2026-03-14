#include <iostream>
#include <vector>

long long v[1'000'000];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,m; std::cin >> n >> m;

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    unsigned long long l = 0 , r = 1e18;

    while (l <= r) {
        unsigned long long sum = 0 , mid = l+(r-l)/2;
        for (int i = 0 ; i < n ; i++) {
            sum += mid/v[i];
            if (sum >= m) break;
        }

        if (sum < m) l=mid+1;
        else r=mid-1;
    }

    std::cout << l;
}