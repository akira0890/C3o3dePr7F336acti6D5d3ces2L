#include <iostream>
#include <algorithm>
#include <climits>

int dp[10001];
std::pair<int,int> ladder[100001];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int p,f,l;
    std::cin >> p >> f >> l;
    for (int i = 1 ; i <= l ; i++) std::cin >> ladder[i].first >> ladder[i].second;
    std::sort(ladder, ladder+l+1);
    std::fill(dp, dp + 10001, INT_MAX);
    dp[1] = 0;

    for (int i = 1 ; i <= l ; i++) {
        if (dp[ladder[i].first] != INT_MAX) {
            dp[ladder[i].second] = std::min(dp[ladder[i].second], dp[ladder[i].first] + 1);
        }
    }
    
    for (int i = f ; i >= 0 ; i--) {
        if (dp[i] <= p) {
            std::cout << i; return 0;
        }
    }
}

// std::vector<std::vector<int>> info;
// int highest[10000] = {0};
// int ans = 1;

// void recursive(int currpower, int currfloor) {
//     if (currfloor > ans) ans = currfloor;

//     if (currpower <= 0 || highest[currfloor] >= currpower) return;

//     highest[currfloor] = currpower;

//     for (int next : info[currfloor]) {
//         recursive(currpower-1 , next);
//     }
// }

// int main() {
//     int power, floors, ladder, source, dest;
//     std::cin >> power >> floors >> ladder;
//     info.reserve(floors);
//     info.resize(floors);

//     while (ladder--) {
//         std::cin >> source >> dest;
//         info[source-1].emplace_back(dest-1);
//     }

//     recursive(power, 0);

//     std::cout << ans+1;
// }