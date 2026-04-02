#include <iostream>
#include <vector>
#include <climits>

class Graph {
    std::vector<std::vector<int>> g;
    int N;
public:
    Graph(int n) {
        g = std::vector<std::vector<int>>(n , std::vector<int>(n , -1));
        N = n;
    }

    void addNode(int u , int v , int weight) {
        g[u][v] = weight;
        // g[v][u] = weight;
    }

    void dfs(std::vector<int> &path , int source , int target , bool found , int sum) {
        if (found) return;
        if (source == target) {
            found = true;
            for (int i = 0 ; i < path.size()-1 ; i++) {
                std::cout << path[i] << "->";
            }
            std::cout << path[path.size()-1] << '\n';
            std::cout << path.size()-1 << '\n' << sum;
            return;
        }

        for (int dest = 0 ; dest < N ; dest++) {
            if (g[source][dest] != -1) {
                path.emplace_back(dest);
                dfs(path , dest , target , found , sum + g[source][dest]);
                path.pop_back();
            }
        }
    }
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , m , start , target;
    std::cin >> n >> m >> start >> target;

    Graph g(n);
    int u , v , w;

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::vector<int> path = {start};
    g.dfs(path , start , target , false , 0);
}