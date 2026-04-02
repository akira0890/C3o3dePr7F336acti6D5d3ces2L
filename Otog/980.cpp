#include <iostream>
#include <queue>
#include <map>

struct Node {
    int time , curr;
    Node(int _time , int _curr) : time(_time) , curr(_curr) {}

    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int dijkstra(int target) {
    std::map<int,int> dist;
    std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
    pq.emplace(0 , target);
    dist[target] = 0;

    int Linear = 0;

    while (!pq.empty()) {
        auto [d , u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;
        if (u == 1) return d;

        Linear++;

        if (u % 3 == 0) {
            if (dist.find(u/3) == dist.end() || dist[u/3] > d + 3) {
                dist[u/3] = d+3;
                pq.emplace(d+3 , u/3);
            }
        }

        if (dist.find(u-1) == dist.end() || dist[u-1] > d+1) {
            dist[u-1] = d+1;
            pq.emplace(d+1 , u-1);
        }

        if (dist.find(u+2) == dist.end() || dist[u+2] > d+1) {
            dist[u+2] = d+1;
            pq.emplace(d+1 , u+2);
        }
    }

    return Linear;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q; std::cin >> q;

    int target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;
        
        std::cout << dijkstra(target) << '\n';
    }
}