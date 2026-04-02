#pragma GCC optimize("Ofast", "unroll-loops") 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(I) for (int i = 0 ; i < I ; i++)

int C,R;
struct Node {
    int y,x,w;
};

struct Edge {
    int r,c1,c2,type,id;

    Edge(int R , int C1 , int C2 , int Type , int Id) :
         r(R) , c1(C1) , c2(C2) , type(Type) , id(Id) {}

    bool operator<(const Edge& other) const {
        if (r != other.r) return r < other.r;
        return type < other.type;
    }
};

int bits[5005];
inline void update(int idx , int v) {
    for (;idx <= C ; idx += idx & -idx) bits[idx] += v;
}

inline int query(int idx) {
    int sum = 0;
    for (;idx > 0 ; idx -= idx & -idx) sum += bits[idx];
    return sum;
}

inline bool check(const vector<Node> &Tree , const vector<Node> &spinker , int D) {
    vector<Edge> edge;

    FOR(Tree.size()) {
        edge.emplace_back(Tree[i].y-D-1, max(1,Tree[i].x-D) , min(C,Tree[i].x+D) , 1 , i);
        edge.emplace_back(Tree[i].y+D  , max(1,Tree[i].x-D) , min(C,Tree[i].x+D) , 2 , i);
    }

    FOR(spinker.size()) {
        edge.emplace_back(spinker[i].y , spinker[i].x , 0 , 0 , i);
    }

    sort(edge.begin() , edge.end() , [](const Edge& a , const Edge& b){
        if (a.r != b.r) return a.r < b.r;
        return a.type < b.type;
    });

    FOR(C+1) bits[i] = 0;
    vector<int> count(Tree.size()+1,0);

    for (Edge e : edge) {
        // cout << e.r << ' ' << e.c1 << ' ' << e.c2 << ' ' << e.type << '\n';
        if (e.type == 0) {
            update(e.c1 , 1);
        } else {
            int currSum = query(e.c2) - query(e.c1-1);
            if (e.type == 1) count[e.id] -= currSum;
            else             count[e.id] += currSum;
        }
    }

    FOR(Tree.size()) {
        // std::cout << Tree[i].w << ' ' << count[i] << '\n';
        if (count[i] < Tree[i].w) return false;
    }
    return true;
}

int main() {
    // cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m >> R >> C;

    vector<Node> Tree(n);
    vector<Node> spinker(m);

    FOR(n) cin >> Tree[i].y    >> Tree[i].x >> Tree[i].w;
    FOR(m) cin >> spinker[i].y >> spinker[i].x;

    int ans = -1;
    int L = 1 , R = 5005;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        // cout << mid << " work\n";
        if (check(Tree , spinker , mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans;
}