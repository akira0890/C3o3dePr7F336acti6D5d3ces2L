#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    long long p;

    std::cin >> n >> p;
    std::vector<long long> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int l = 0 , r = INT_MAX;
    long long ans = 0 , cp = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;

        long long point = 0;
        for (int i = 0 ; i < n ; i++) {
            if (v[i] >= mid) {
                point += v[i] / mid;
            }
        }

        if (point < p) {
            r = mid-1;
        } else {
            ans = mid;
            cp = point; 
            l = mid+1;
        }
    }

    if (cp == p) std::cout << "YES\n";
    else std::cout << "NO\n";
    std::cout << ans;
}