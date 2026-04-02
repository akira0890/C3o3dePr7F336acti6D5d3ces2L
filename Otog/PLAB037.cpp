#include <iostream>
#include <vector>
#include <climits>

struct Node {
    int dest , weight;

    Node(int Dest , int Weight) : dest(Dest) , weight(Weight) {}
};


class Graph {
    std::vector<std::vector<Node>> g;
    int n;
    int target;
public:
    Graph(int N , int Target) {
        g.resize(N);
        n = N;
        target = Target;
    }

    void addNode(int u , int v , int w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::pair<int,int> dfs(int start , int sum) {
        std::vector<bool> visited(n,false);
        int minsum = INT_MAX;
        int path = 0;
        visited[start] = true;
        dfs_helper(visited , start , 0 , minsum , path);
        return {minsum , path};
    }

    void dfs_helper(std::vector<bool> &visited , int curr, int sum , int& minsum , int &path) {
        if (curr == target) {
            path++;
            if (sum < minsum) {
                minsum = sum;
            }
        }

        for (Node dest : g[curr]) {
            if (!visited[dest.dest]) {
                visited[dest.dest] = true;
                dfs_helper(visited , dest.dest , sum + dest.weight , minsum , path);
                visited[dest.dest] = false;
            }
        }
    }
};

int main() {
    int n,m,start,end;
    std::cin >> n >> m >> start >> end;

    Graph g(n , end);

    int u,v,w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::pair<int,int> path = g.dfs(start,0);

    std::cout << path.second << ' ' << path.first;
}