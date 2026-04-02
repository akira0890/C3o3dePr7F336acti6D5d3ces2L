#include <iostream>
#include <vector>
#include <algorithm>

int burger[100005][105];

int main () {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,s;
    std::cin >> n >> m >> s;

    int maxT = 0;
    int t,a,b;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> t >> a >> b;
        burger[t][a] = b;
        maxT = std::max(maxT , t);
    }

    std::vector<long long> prev(n+2 ,-1e18);

    prev[s] = 0;

    for (int t = 1 ; t <= maxT ; t++) {
        std::vector<long long> curr(n+2 , -1e18);
        for (int i = 1 ; i <= n ; i++) {
            long long best = std::max({prev[i-1] , prev[i] , prev[i+1]});

            if (best >= 0) curr[i] = best + burger[t][i];
        }   
        prev = std::move(curr);
    }

    long long ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        ans = std::max(ans , prev[i]);
    }

    std::cout << ans;
}