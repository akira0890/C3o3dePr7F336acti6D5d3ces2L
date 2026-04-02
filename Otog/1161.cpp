#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

const long long mod = 1e9+7; 

class DSU {
    std::vector<int> parent , rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,1);
        for (int i = 1 ; i < n ; i++) parent[i] = i;
    }

    int find(int p) {
        if (parent[p] == p)
            return p;
        return parent[p] = find(parent[p]);
    }

    void unite(int u , int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<std::pair<int,int>> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i].first , v[i].second = i;

    std::sort(v.begin() , v.end());

    DSU dsu(n);
    std::vector<long long> sumP(n , 0);

    std::queue<std::pair<long long , int>> q1 , q2;

    for (int i = 0 ; i < n ; i++) {
        q1.emplace(v[i]);
    }

    long long sum = v[0].first;
    long long res = 0;
    for (int i = 1 ; i < n ; i++) {
        long long a,b;
        int pa , pb;
        if (!q1.empty()) {
            if (!q2.empty()) {
                if (q1.front().first < q2.front().first) {
                    a = q1.front().first;
                    pa = q1.front().second;
                    q1.pop();
                } else {
                    a = q2.front().first;
                    pa = q2.front().second;
                    q2.pop();
                }
            } else {
                a = q1.front().first;
                pa = q1.front().second;
                q1.pop();
            }
        } else {
            if (!q2.empty()) {
                a = q2.front().first;
                pa = q2.front().second;
                q2.pop();
            }
        }

        if (!q1.empty()) {
            if (!q2.empty()) {
                if (q1.front().first < q2.front().first) {
                    b = q1.front().first;
                    pb = q1.front().second;
                    q1.pop();
                } else {
                    b = q2.front().first;
                    pb = q2.front().second;
                    q2.pop();
                }
            } else {
                b = q1.front().first;
                pb = q1.front().second;
                q1.pop();
            }
        } else {
            if (!q2.empty()) {
                b = q2.front().first;
                pb = q2.front().second;
                q2.pop();
            }
        }

        // std::cout << a << ' ' << b << ' ';

        long long suma = a;
        long long sumb = b;

        long long twoSum = (suma + sumb) % mod;
        long long pows = (twoSum * twoSum) % mod;
        res = (res + pows) % mod;
        // std::cout << res << '\n';

        dsu.unite(pa,pb);
        sumP[dsu.find(pa)] = twoSum;
        q2.emplace(twoSum , dsu.find(pa));
    }

    std::cout << res;
}