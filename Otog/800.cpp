#include <iostream>
#include <vector>
#include <climits>
#include <queue>

struct Node {
    int dest;
    long long w;

    Node(int Dest , long long W) : dest(Dest) , w(W) {}

    bool operator>(const Node& other) const {
        return w > other.w;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int n;
    int k;
public:
    Graph(int N , int K) {
        n = N;
        k = K;
        g.resize(n);
    }

    void addNode(int u , int v , long long w) {
        g[u].emplace_back(v , w);
        g[v].emplace_back(u , w);
    }

    long long mst(int source) {
        std::vector<bool> visited(n , false);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;

        std::priority_queue<long long> value;

        long long sum = 0;
        pq.emplace(source , 0);

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (visited[curr.dest]) continue;

            visited[curr.dest] = true;
            value.emplace(curr.w);
            
            for (Node dest : g[curr.dest]) {
                if (!visited[dest.dest]) {
                    pq.emplace(dest.dest , dest.w);
                }
            }
        }

        for (int currk = 0 ; currk < k ; currk++) {
            long long v = value.top() / 2;
            value.pop();
            value.emplace(v);
        }

        while (!value.empty()) {
            sum += value.top();
            value.pop();
        }

        return sum;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k; std::cin >> n >> m >> k;

    Graph g(n,k);

    int u,v;
    long long  w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::cout << g.mst(0);
}