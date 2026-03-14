#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define ll long long

struct Edge {
    int to;
    ll cost;
    bool isSpecial;
};

struct State {
    ll cost;
    int node;
    int tickets;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<vector<Edge>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        ll a_i, b_i;
        int x_i;
        cin >> a_i >> x_i >> b_i;
        adj[i].push_back({i + 1, a_i, false});
        adj[i].push_back({x_i, b_i, true});
    }

    vector<vector<ll>> dist(N, vector<ll>(K + 1, LLONG_MAX));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[0][K] = 0;
    pq.push({0, 0, K});

    ll min_cost = LLONG_MAX;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        ll d = current.cost;
        int u = current.node;
        int t = current.tickets;

        if (d > dist[u][t]) continue;
        if (u == N - 1) {
            min_cost = min(min_cost, d);
        }

        for (const auto& edge : adj[u]) {
            int next_t = t;
            if (edge.isSpecial) next_t--;
            if (next_t < 0) continue;

            if (dist[edge.to][next_t] > d + edge.cost) {
                dist[edge.to][next_t] = d + edge.cost;
                pq.push({dist[edge.to][next_t], edge.to, next_t});
            }
        }
    }

    cout << min_cost << "\n";

    return 0;
}