#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n, money; std::cin >> n >> money;

    std::vector<int> coins(n) , dp(money+1 , 1e9);
    for (int i = 0 ; i < n ; i++) std::cin >> coins[i];
    dp[money] = 0;

    for (int i = money ; i >= 0 ; i--) {
        for (int j = 0 ; j < n ; j++) {
            if (i + coins[j] <= money) {
                dp[i] = std::min(dp[i] , dp[i + coins[j]]+1);
            }
        }
    }

    std::cout << dp[0] << '\n';
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// int n;
// std::vector<int> v , dp;

// void recursive(int curr) {
//     for (int i = 0 ; i < n ; i++) {
//         // std::cout << curr << " : " << curr-v[i] << '\n';
//         if (curr - v[i] >= 0 && (dp[curr] < dp[curr - v[i]]-1 || dp[curr - v[i]]==0)) {
//             dp[curr - v[i]] = dp[curr]+1;
//             recursive(curr - v[i]);
//         }
//     }
// }

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int money; std::cin >> n >> money;

//     v.resize(n);
//     dp = std::vector<int>(money+1,0);
//     for (int i = 0 ; i < n ; i++) std::cin >> v[i];

//     recursive(money);

//     std::cout << dp[0];
//     // for (int i = 0 ; i <= money ; i++) std::cout << i << ' ' << dp[i] << '\n';
// }