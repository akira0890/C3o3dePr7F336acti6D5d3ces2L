#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define pii std::pair<long long , int>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    long long maxs = 1LL << m;

    std::vector<long long> dp(maxs , LLONG_MAX);
    dp[0] = 0;

    std::vector<long long> Herb(maxs , LLONG_MAX);

    int t;
    long long v;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> v;
        int good = 0;
        for (int j = 0 ; j < m ; j++) {
            std::cin >> t;
            if (t == 1) good |= (1 << j);
        }

        Herb[good] = std::min(Herb[good] , v);
    }

    std::vector<pii> BestHerb;
    for (int i = 1 ; i < maxs ; i++) {
        if (Herb[i] != LLONG_MAX) {
            BestHerb.emplace_back(Herb[i] , i);
        }
    }

    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
    pq.emplace(0,0);

    while (!pq.empty()) {
        auto [dist , mask] = pq.top();
        pq.pop();

        if (dp[mask] < dist) continue;
        if (mask == maxs-1) break;

        for (auto [value , newmask] : BestHerb) {
            if (dp[mask | newmask] > dp[mask] + value) {
                dp[mask | newmask] = dp[mask] + value;
                pq.emplace(dp[mask | newmask] , mask | newmask);
            }
        }
    }

    std::cout << dp[maxs-1];
}