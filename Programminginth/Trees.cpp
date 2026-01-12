/*
Method 2

each Edge
let u = first value , v = second value

Solution:
each tree pair create 2 tree from there given edge information using pair but instead of let edge be {u,v}
we swap the value of u and v if v > u so when sort tree vector it give same vector when it a same tree
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u,v;

    bool operator<(const Edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }

    bool operator==(const Edge& other) const {
        return u == other.u && v == other.v;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,u,v;

    for (int i = 0 ; i < 5 ; i++) {
        std::cin >> n;

        std::vector<Edge> tree1(n-1),tree2(n-1);

        for (int i = 0 ; i < n-1 ; i++) {
            std::cin >> u >> v;
            if (v > u) std::swap(u,v);
            tree1[i] = {u,v};
        }

        for (int i = 0 ; i < n-1 ; i++) {
            std::cin >> u >> v;
            if (v > u) std::swap(u,v);
            tree2[i] = {u,v};
        }

        std::sort(tree1.begin(),tree1.end());
        std::sort(tree2.begin(),tree2.end());
        std::cout << (tree1==tree2?'Y':'N');
    }
}

/*
method 1 slow but pass

each Edge
let u = first value , v = second value

Solution:
first create direct graph from first line of each tree pair and add edge from gived first line information
then on second line of each tree pair find if u vertex contain v vertex, if it isn't contain v then it not a same tree
*/

// #include <iostream>
// #include <vector>
// #include <unordered_map>

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     int m=5,n,t1,t2;
    
//     while (m--) {
//         std::cin >> n;
//         std::vector<std::unordered_map<int,int>> tree(n); 
//         bool issame = true;
        
//         for (int i = 0 ; i < (n-1) ; i++) {
//             std::cin >> t1 >> t2;
//             t1--;t2--;
//             tree[t1][t2] = 1;
//         }

//         for (int i = 0 ; i < (n-1) ; i++) {
//             std::cin >> t1 >> t2;
//             t1--;t2--;
//             if (!(tree[t1].find(t2) != tree[t1].end() || tree[t2].find(t1) != tree[t2].end()))
//                 issame = false;
//         }

//         if (issame) std::cout << 'Y';
//         else        std::cout << 'N';
//     }
// }