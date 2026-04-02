#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k; std::cin >> n >> k;
    long long l = 0 , r = 1e18;
    long long ans = 0;

    std::vector<long long> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        long long divide = 0;
        for (int i = 0 ; i < n ; i++) {

        }

        if (divide >= k) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
}