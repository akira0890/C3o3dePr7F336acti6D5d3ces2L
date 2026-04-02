#include <iostream>
#include <vector>

#define ll long long
const ll maxy = 4;
const ll maxx = 1e5+50;
ll dp[maxy][maxy][maxx];
ll v[maxy][maxx];
bool visited[maxy][maxy][maxx];
int m;

ll recursive(int prevI , int prevJ , int l) {
    int r = m - l - 1;
    if (l >= r) return 0;

    if (visited[prevI][prevJ][l]) return dp[prevI][prevJ][l];
    visited[prevI][prevJ][l] = true;
    ll maxs = -1e15;

    for (int i = 0 ; i < maxy ; i++) {
        for (int j = 0 ; j < maxy ; j++) {
            if (i==j) continue;
            if (i==prevI || j==prevJ) continue;

            maxs = std::max(maxs , recursive(i , j , l+1) + v[i][l] + v[j][r]);
        }
    }

    return dp[prevI][prevJ][l] = maxs;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> m;

    for (int i = 0 ; i < maxy ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }

    ll ans = -1e15;
    for (int i = 0 ; i < maxy ; i++) {
        for (int j = 0 ; j < maxy ; j++) {
            if (i==j) continue;

            ans = std::max(ans , recursive(i,j,1) + v[i][0] + v[j][m-1]);
        }
    }

    std::cout << ans;
}