#include <iostream>
#include <vector>
#include <queue>

class Graph {
    std::vector<std::vector<int>> g;
    int n;
public:
    Graph(int N) {
        g.resize(N);
        n = N;
    }

    void addNode(int u , int v , int weight) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int bfs(int source , int end) {
        std::vector<int> dist(n,-1);
        std::queue<int> q;
        q.emplace(source);
        dist[source] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int dest : g[curr]) {
                if (dist[dest] == -1) {
                    dist[dest] = dist[curr]+1;
                    q.emplace(dest);
                }
            }
        }

        return dist[end];
    }

    int printMaxChild() {
        int sum = 0;
        for (int i = 0 ;  i < n ; i++) sum = std::max(sum,(int)g[i].size());
        return sum;
    }
};

int main() {
    int n,m,start,end;
    std::cin >> n >> m >> start >> end;

    Graph g(n);

    int u,v,w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::cout <<g.bfs(start , end);

    std::cout << ' ' << g.printMaxChild();

    return 0;
}