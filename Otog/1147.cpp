// QuadTree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Node {
    int x1 , y1 , x2 , y2;
    int count;
    Node *ch[4];

    Node(int _x1 , int _y1 , int _x2 , int _y2) :
        x1(_x1) , x2(_x2) , y1(_y1) , y2(_y2), count(0) {
            for (int i = 0 ; i < 4 ; i++) ch[i] = nullptr;
        }
};

inline int Disttorect(int qx , int qy , int x1 , int y1 , int x2 , int y2) {
    int dx = max({0 , x1 - qx, qx - x2});
    int dy = max({0 , y1 - qy, qy - y2});
    return dx + dy;
}

void update(Node* &node , int x1 , int y1 , int x2 , int y2 , int qx , int qy , int val) {
    if (!node) node = new Node(x1,y1,x2,y2);
    if (x1 == x2 && y1 == y2) {
        node->count += val;
        return;
    }

    int mx = x1 + (x2-x1) / 2;
    int my = y1 + (y2-y1) / 2;

    if (qx <= mx) {
        if (qy <= my) update(node->ch[0] , x1 , y1 , mx , my , qx , qy , val);
        else update(node->ch[2] , x1 , my+1 , mx , y2 , qx , qy , val);
    } else {
        if (qy <= my) update(node->ch[1] , mx+1 , y1 , x2 , my , qx , qy , val);
        else update(node->ch[3] , mx+1 , my+1 , x2 , y2 , qx , qy , val);
    }

    node->count = 0;
    for (int i = 0 ; i < 4 ; i++) {
        if (node->ch[i]) node->count += node->ch[i]->count;
    }
}

void query(Node* node , int qx , int qy , int &ans) {
    if (!node || node->count == 0) return;

    if (Disttorect(qx , qy , node->x1 , node->y1 , node->x2 , node->y2) >= ans) return;

    if (node->x1 == node->x2 && node->y1 == node->y2) {
        ans = min(ans , abs(qx - node->x1) + abs(qy - node->y1));
        return;
    }

    pair<int , int> order[4];
    for (int i = 0 ; i < 4 ; i++) {
        if (node->ch[i] && node->ch[i]->count > 0) {
            order[i] = {Disttorect(qx,qy,node->ch[i]->x1 , node->ch[i]->y1,node->ch[i]->x2 , node->ch[i]->y2) , i};
        } else {
            order[i] = {INF , i};
        }
    }
    sort(order , order+4);

    for (int i = 0 ; i < 4 ; i++) {
        if (order[i].first >= ans) break;
        query(node->ch[order[i].second] , qx , qy , ans);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int r , c , q; cin >> r >> c >> q;

    Node* root = new Node(1,1,r,c);
    vector<bool> isblack(100'005 , false);

    auto Getidx = [&](int row, int col) {
        return (row-1) * c + col-1;
    };

    int command , y , x;
    for (int i = 0 ; i < q ; i++) {
        cin >> command >> x >> y;
        int idx = Getidx(x,y);

        if (command == 1) {
            if (!isblack[idx]) {
                update(root , 1 , 1 , r , c , x , y , 1);
                isblack[idx] = true;
            } else {
                update(root , 1 , 1 , r , c , x , y , -1);
                isblack[idx] = false;
            }
        } else {
            int ans = INF;
            query(root , x , y , ans);
            if (ans == INF) cout << "-1\n";
            else cout << ans << '\n';
        }
    }
}