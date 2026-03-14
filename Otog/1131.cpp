#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,m,k,ans = 0; std::cin >> n >> m >> k;
    long long t;

    std::vector<long long> v1(n+1) , v2(n+1) , diff1(n-m+1) , diff2(n-m+1);
    v1[0] = 0; v2[0] = 0;

    for (int i = 1 ; i <= n ; i++) std::cin >> t , v1[i] = v1[i-1] + t;
    for (int i = 1 ; i <= n ; i++) std::cin >> t , v2[i] = v2[i-1] + t;

    for (int i = 0 ; i <= n-m ; i++) {
        diff1[i] = v1[i+m] - v1[i] , diff2[i] = v2[i+m] - v2[i];
    }

    std::sort(diff2.begin() , diff2.end());

    for (int i = 0 ; i < n-m+1 ; i++) {
        long long target = k - diff1[i];

        int dist = diff2.end() - std::lower_bound(diff2.begin() , diff2.end() , target);

        ans += dist;
    }

    std::cout << ans;
}