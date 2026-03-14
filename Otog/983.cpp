#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , q; std::cin >> n >> q;

    std::vector<long long> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    long long target;
    while (q--) {
        std::cin >> target;

        long long ans = -1;
        long long l = 0 , r = 1e18;
        while (l <= r) {
            long long mid = l + (r - l) / 2;

            int get = 0;
            long long sum = 0;
            bool full = false;
            for (int i = 0 ; i < n ; i++) {
                sum += v[i];
                if (sum >= mid) {
                    get++;
                    sum = 0;
                }

                if (get > target) break;
            }

            if (sum <= mid && sum != 0) get++;

            if (get <= target) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        std::cout << ans << '\n';
    }
}