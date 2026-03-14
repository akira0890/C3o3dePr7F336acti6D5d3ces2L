#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

class BIT {
    int size;
    std::vector<ull> Tree;
public:
    BIT(int n) : size(n) {
        Tree.resize(n+1,0);
    }

    void update(ull n, int index) {
        for (int i = index+1 ; i <= size ; i += i & -i) {
            Tree[i] = std::max(Tree[i] , n);
        }
    }

    ull query(int index) {
        ull res = 0;
        index++;
        while (index > 0) {
            res = std::max(Tree[index] , res);
            index -= index & -index;
        }
        return res;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    ull t , ind , val;
    char cmd;

    BIT BiTree(n);

    while (m--) {
        std::cin >> cmd;
        if (cmd == 'B') {
            std::cin >> ind >> val;
            BiTree.update(val , ind);
        } else {
            std::cin >> ind;
            std::cout << BiTree.query(ind) << '\n';
        }
    }

}