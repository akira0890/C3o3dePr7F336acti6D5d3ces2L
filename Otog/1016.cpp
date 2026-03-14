#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

inline int convertBinary(const std::string &v) {
    int val = 0 , index = 0;
    for (int i = v.size()-1 ; i >= 0 ; i--) {
        val += (v[i]-'0') * (1 << index);
        index++;
    }
    return val;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q,d,sor; std::cin >> n >> q;

    int powN = 1 << n;
    std::vector<int> distanceOfNode(powN);
    std::vector<long long> dp(powN , LLONG_MIN);

    std::string s;
    for (int i = 0 ; i < powN ; i++) {
        std::cin >> s >> d;
        distanceOfNode[convertBinary(s)] = d;
    }

    dp[0] = distanceOfNode[0];
    for (int state = 1 ; state < powN ; state++) {
        long long currentMax = LLONG_MIN;
        for (int i = 0 ; i < n ; i++) {
            if (state & (1 << i)) {
                int prev = state ^ (1 << i);
                if (dp[prev] != LLONG_MIN) currentMax = std::max(currentMax , dp[prev]);
            }
        }

        for (int i = 0 ; i < n-1 ; i++) {
            int mask = (3 << i);
            if ((state & mask) == mask) {
                int prev = state ^ mask;
                if (dp[prev] != LLONG_MIN) currentMax = std::max(currentMax , dp[prev]);
            }
        }

        if (currentMax == LLONG_MIN) dp[state] = distanceOfNode[state];
        else dp[state] = currentMax + distanceOfNode[state];
    }


    for (int i = 0 ; i < q ; i++) {
        std::cin >> s;
        sor = convertBinary(s);
        std::cout << dp[sor] << '\n';
    }
}