#include <iostream>
#include <vector>

#define mod 100'000'003

long long prev[1005] , curr[1005];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    for (int i = 0 ; i <= m ; i++) prev[i] = 1;

    for (int i = 0 ; i <= n ; i++) {
        curr[0] = 1;
        for (int j = 1 ; j <= m ; j++) {
            curr[j] = (curr[j-1] + prev[j]) % mod;
        }
        std::swap(curr , prev);
    }

    std::cout << curr[m];
}