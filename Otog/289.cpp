#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> v[i];
    }

    int t;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> t;

        int l=0 , r=n-1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;

            if (v[mid] <= t) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        std::cout << ans << '\n';
    }
}