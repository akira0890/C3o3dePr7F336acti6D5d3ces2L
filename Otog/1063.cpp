#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int dest , weight;

    Node (int _dest , int _weight) : dest(_dest) , weight(_weight) {}
};

class Graph {
    int edge;
    std::vector<std::vector<Node>> g;
public:
    Graph(int Edge) {
        edge = Edge;
        g.resize(Edge+1);
    }

    void addNode(int u , int v , int w) {
        g[u].emplace_back(v , w);
        g[v].emplace_back(u , w);
    }

    std::pair<int , std::vector<long long>> bfs(int source) {
        std::vector<long long> distance(edge+1,-1);
        std::queue<int> q;
        q.emplace(source);
        distance[source] = 0;

        int farthestNode = source;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (distance[curr] > distance[farthestNode]) farthestNode = curr;

            for (Node &dest : g[curr]) {
                if (distance[dest.dest] == -1) {
                    distance[dest.dest] = distance[curr] + (long long)dest.weight;
                    q.emplace(dest.dest);
                }
            }
        }
        return {farthestNode , distance};
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int edge,t; std::cin >> edge >> t;

    Graph graph(edge);

    int u , v , w;
    for (int i = 0 ; i < edge-1 ; i++) {
        std::cin >> u >> v >> w;
        graph.addNode(u,v,w);
    }

    int ithA = graph.bfs(1).first;
    auto resA = graph.bfs(ithA);
    int ithB = resA.first;
    auto resB = graph.bfs(ithB);

    std::vector<long long> WeightA = resA.second;
    std::vector<long long> WeightB = resB.second;

    std::vector<long long> maxWeight(edge , 0);
    for (int i = 1 ; i <= edge ; i++) {
        maxWeight[i-1] = std::max(WeightA[i] , WeightB[i]);
    }

    std::vector<int> people(t);
    for (int i = 0 ; i < t ; i++) std::cin >> people[i];

    std::sort(people.begin() , people.end() , std::greater<int>());
    std::sort(maxWeight.begin() , maxWeight.end());

    long long sum = 0;
    for (int i = 0 ; i < t ; i++) {
        sum += (long long)people[i] * maxWeight[i];
    }

    std::cout << sum << '\n';
}