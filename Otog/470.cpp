#include <iostream>
#include <vector>
#include <queue>
#include <climits>

const long long INF = 1e15;

struct Node {
    long long dest , weight;

    Node(long long Dest , long long Weight) : dest(Dest) , weight(Weight) {}

    bool operator<(const Node& other) const {
        return weight < other.weight;
    }

    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    long long n;
public:
    Graph(long long N) {
        g.resize(N);
        n = N;
    }

    void addNode(long long u , long long v , long long w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::vector<long long> dijkstra(long long source) {
        std::vector<long long> distance(n , INF);

        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        pq.emplace(source,0);
        distance[source] = 0;

        while (!pq.empty()) {
            auto [curr,dist] = pq.top();
            pq.pop();

            if (distance[curr] < dist) continue;

            for (Node dest : g[curr]) {
                if (distance[dest.dest] > distance[curr] + dest.weight) {
                    distance[dest.dest] = distance[curr] + dest.weight;
                    pq.emplace(dest.dest , distance[dest.dest]);
                }
            }
        }

        return distance;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,m , start , end , Maxweight;
    std::cin >> n >> m >> start >> end >> Maxweight;

    Graph g(n);

    long long u,v,w;
    for (long long i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::vector<long long> distanceFirst = g.dijkstra(start);
    if (distanceFirst[end] <= Maxweight) {
        std::cout << end << ' ' << distanceFirst[end] << ' ' << 0;
    } else {
        std::vector<long long> distanceSecond = g.dijkstra(end);

        long long mindistance = INF;
        long long idx = -1;
        for (long long i = 0 ; i < n ; i++) {
            if (i != end && distanceFirst[i] <= Maxweight) {
                if (distanceSecond[i] < mindistance) {
                    mindistance = distanceSecond[i];
                    idx = i;
                } else if (mindistance == distanceSecond[i]){
                    if (idx != -1 || i < idx) idx = i;
                }
            }
        }

        std::cout << idx << ' ' << distanceFirst[idx] << ' ' << distanceSecond[idx];
    }
}
