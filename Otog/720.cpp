#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

struct Edge {
    int to;
    long long fuel;

    Edge(int TO , long long Fuel) : to(TO) , fuel(Fuel) {}
};

struct Node {
    int dest;
    long long w , distSum;

    Node(int Dest , int W , int DistSum) :
        dest(Dest) , w(W) , distSum(DistSum) {}

    bool operator>(const Node& other) const {
        if (w != other.w) return w > other.w;
        return distSum > other.distSum;
    }
};

long long formation_time[50005];
long long min_fuel[50005];
std::vector<Edge> edge[50005];

std::unordered_map<std::string ,int> idx;
int getID(const std::string& s) {
    if (idx.find(s) == idx.end()) {
        int i = idx.size();
        idx[s] = i;
    }
    return idx[s];
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,g;
    long long w;
    std::string start_node, end_node , name;
    std::cin >> n >> m >> start_node >> end_node >> g;
    
    for (int i = 0 ; i < n ; i++) {
        std::cin >> name >> w;
        int ind = getID(name);
        formation_time[ind] = w;
        min_fuel[ind] = 4e18;
    }

    std::string u,v;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        int x = getID(u);
        int y = getID(v);
        edge[x].emplace_back(y,w);
        edge[y].emplace_back(x,w);
    }

    int start = getID(start_node);
    int end = getID(end_node);
    std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
    pq.emplace(start , 0 , 0);

    min_fuel[start] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int source = node.dest;
        long long currTime = node.w;
        long long currFuel = node.distSum;

        if (source == end) {
            std::cout << currTime << ' ' << currFuel;
            break;
        }

        if (min_fuel[source] < currFuel) continue;

        for (Edge x : edge[source]) {
            int dest = x.to;
            long long fuel = x.fuel;
            long long nextFuel = currFuel + fuel;

            if (nextFuel <= g && nextFuel < min_fuel[dest]) {
                min_fuel[dest] = currFuel + fuel;
                pq.emplace(dest , std::max(currTime , formation_time[dest]) , min_fuel[dest]);
            }
        }
    }
}