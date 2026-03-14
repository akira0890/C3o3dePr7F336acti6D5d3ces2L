#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, 
             rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,l,a,b,t; std::cin >> n >> l >> a >> b;
    indexed_set s;
    
    int time = 0;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        s.insert({t, time++});
    }

    for (int i = 0 ; i < l ; i++) {
        auto it1 = s.find_by_order(a-1);
        auto it2 = s.find_by_order(b-1);

        long long v1 = (*it2).first - (*it1).first;
        long long v2 = ((*it1).first + (*it2).first)/2;

        s.erase(it2);
        s.erase(it1);

        s.insert({v1,time++});
        s.insert({v2,time++});
    }

    for (auto it = s.begin() ; it != s.end() ; it++) {
        std::cout << (*it).first << ' ';
    }
}

// #include <iostream>
// #include <set>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n,l,a,b,t; std::cin >> n >> l >> a >> b;

//     std::multiset<int> s;

//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> t;
//         s.emplace(t);
//     }

//     for (int i = 0 ; i < l ; i++) {
//         std::set<int>::iterator v1 = s.begin();
//         std::set<int>::iterator v2 = s.begin();
//         std::advance(v1 , a-1);
//         std::advance(v2 , b-1);
        
//         long long n1 = *v2 - *v1;
//         long long n2 = (*v2+*v1)/2;
//         s.erase(v2);
//         s.erase(v1);
//         s.emplace(n1);
//         s.emplace(n2);
//     }

//     for (auto it = s.begin() ; it != s.end() ; it++) {
//         std::cout << *it << ' ';
//     }
// }