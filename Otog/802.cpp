#include <iostream>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    int dest;
    long long weight;
    int idx;

    Node(int Dest , long long Weight , int Idx) : dest(Dest) , weight(Weight) , idx(Idx) {}

    bool operator>(const Node & other) const {
        return weight > other.weight;
    }
};

int n,m,q, start , end;

std::vector<long long> dijkstra(const std::vector<std::vector<Node>> &g , int start , int idx) {
    std::vector<long long> distance(n+1,LLONG_MAX);
    std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
    
    distance[start] = 0;
    pq.emplace(start,0,idx);
    
    while (!pq.empty()) {
        auto [curr , dist , i] = pq.top();
        pq.pop();

        if (distance[curr] < dist) continue;
        
        for (Node dest : g[curr]) {
            if (dest.idx == idx && distance[dest.dest] > distance[curr] + dest.weight) {
                distance[dest.dest] = distance[curr] + dest.weight;
                pq.emplace(dest.dest , distance[dest.dest] , i);
            }
        }
    }

    return distance;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m >> q >> start >> end;
    std::vector<std::vector<Node>> g(n+1);

    int u , v;
    long long w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w,0);
        g[v].emplace_back(u,w,1);
    }

    std::vector<long long> distA = dijkstra(g , start,0);
    std::vector<long long> distB = dijkstra(g , end  ,1);

    int target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;

        std::cout << distA[target] + distB[target] << '\n';
    }
}