#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Love {
    int nth , Love;
};

struct Question {
    int nth , p , k;
};

struct DSU {
    std::vector<int> parent , sz;

    DSU(int n) {
        sz.resize(n+1,1);
        parent.resize(n+1);
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = find(n);
    }

    void unite(int u , int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (sz[pu] < sz[pv]) {
            sz[pv] += sz[pu];
            parent[pu] = pv;
        } else {
            sz[pu] += sz[pv];
            parent[pv] = pu;
        }
    }
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,Q; std::cin >> n >> m >> Q;

    std::vector<Love> love(n);
    std::vector<int> originalLove(n);
    for (int i = 0 ; i < n ; i++) {
        std::cin >> love[i].Love, love[i].nth = i;
        originalLove[love[i].nth] = love[i].Love;
    }

    std::sort(love.begin() , love.end() , [](const Love& a , const Love& b){
        return a.Love < b.Love;
    });

    int u,v;
    std::vector<std::vector<int>> g(n);
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        g[u-1].emplace_back(v-1);
        g[v-1].emplace_back(u-1);
    }

    std::vector<Question> question(Q);
    for (int i = 0 ; i < Q ; i++) {
        question[i].nth = i;
        std::cin >> question[i].p >> question[i].k;
        question[i].p--;
    }

    std::sort(question.begin() , question.end() , [](const Question& a , const Question& b){
        return a.k < b.k;
    });

    std::vector<int> ans(Q);
    std::vector<bool> visited(n+1,false);
    int use = 0;
    DSU dsu(n);

    for (int i = 0 ; i < Q ; i++) {
        Question ques = question[i];
        std::cout << "work1\n";

        while (use < n && love[use].Love <= ques.k) {
            int curr = love[use].nth;
            visited[curr] = true;
            for (int dest : g[curr]) {
                if (visited[dest]) {
                    dsu.unite(curr , dest);
                }
            }
            use++;
        }

        std::cout << "work2\n";

        if (originalLove[ques.p] > ques.k) {
            ans[ques.nth] = 0;
        } else {
            ans[ques.nth] = dsu.sz[dsu.find(ques.p)];
        }
    }

    for (int i = 0 ; i < Q ; i++) {
        std::cout << ans[i] << '\n';
    }
}