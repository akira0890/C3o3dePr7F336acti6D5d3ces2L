#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::set<int>> v(n+1);

    for (int i = 1 ; i <= n ; i++) {
        int t,p;
        std::cin >> t;
        std::set<int> s;
        for (int j = 0 ; j < t ; j++) {
            std::cin >> p;
            s.emplace(p);
        }
        v[i] = s;
    }

    std::string s;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> s;
        int a,b;
        int value = 0;
        char oper;
        for (char c : s) {
            if (isdigit(c)) {
                value = value*10 + c-'0';
            } else {
                oper = c;
                a = value;
                value = 0;
            }
        }
        b = value;

        std::set<int> temp;
        if (oper == 'U') {
            std::set_union(v[a].begin() , v[a].end() , v[b].begin() , v[b].end() , std::inserter(temp , temp.begin()));
        } else if (oper == '|') {
            std::set_intersection(v[a].begin() , v[a].end() , v[b].begin() , v[b].end() , std::inserter(temp , temp.begin()));
        } else {
            std::set_difference(v[a].begin() , v[a].end() , v[b].begin() , v[b].end() , std::inserter(temp , temp.begin()));
        }

        if (!temp.empty()) {
            for (auto it = temp.begin() ; it != temp.end() ; it++) {
                std::cout << *it << ' ';
            }
        } else {
            std::cout << "Empty";
        }
        std::cout << '\n';
    }
}