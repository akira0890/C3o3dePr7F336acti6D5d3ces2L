#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int dest;
    char c;

    Node(int Dest, char C) : dest(Dest) , c(C) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m , u , v; std::cin >> n >> m;
    char c;
    std::vector<std::vector<Node>> g(n+1);

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> c;
        g[u].emplace_back(Node{v,c});
    }

    int source , len; std::cin >> source >> len;
    std::string s; std::cin >> s;

    std::vector<std::vector<unsigned long long>> dp(n+1 , std::vector<unsigned long long>(len+1,0));
    dp[source][0] = 1;

    for (int i = 0 ; i < len ; i++) {
        for (int u = 1 ; u <= n ; u++) {
            if (dp[u][i] == 0) continue;

            for (Node& node : g[u]) {
                if (node.c == s[i])
                dp[node.dest][i+1] = (dp[node.dest][i+1] + dp[u][i]) % (long long)(1e9+7);
            }
        }
    }

    unsigned long long ans = 0;

    for (int i = 1 ; i <= n ; i++) {
        ans = (ans + dp[i][len]) % (long long)(1e9+7);
    }

    std::cout << ans;

}