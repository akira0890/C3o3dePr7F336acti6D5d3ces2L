#include <iostream>
#include <vector>
#include <algorithm>

double ans = 1'000'000'000'000;
int n,m;

int moves[8][2] = {
    {1,0},
    {0,1},
    {1,1},
    {-1,0},
    {0,-1},
    {-1,1},
    {1,-1},
    {-1,-1}
};

double v[5][5];
bool visited[5][5];

double recur(int nt) {
    if (nt <= 0) {
        return 0;
    }

    double minsum = 2e12;
    
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;

                double tenpercent = v[i][j] * 0.1;

                v[i+1][j+1] += tenpercent;
                v[i][j+1]   += tenpercent;
                v[i-1][j+1] += tenpercent;
                v[i+1][j]   += tenpercent;
                v[i-1][j]   += tenpercent;
                v[i+1][j-1] += tenpercent;
                v[i][j-1]   += tenpercent;
                v[i-1][j-1] += tenpercent;

                minsum = std::min(minsum , v[i][j] + recur(nt-1));

                v[i+1][j+1] -= tenpercent;
                v[i][j+1]   -= tenpercent;
                v[i-1][j+1] -= tenpercent;
                v[i+1][j]   -= tenpercent;
                v[i-1][j]   -= tenpercent;
                v[i+1][j-1] -= tenpercent;
                v[i][j-1]   -= tenpercent;
                v[i-1][j-1] -= tenpercent;
                visited[i][j] = false;
            }
        }
    }
    return minsum;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::printf("%.2lf" , recur(n*m));
}