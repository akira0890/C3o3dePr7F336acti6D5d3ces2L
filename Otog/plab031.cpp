#include <iostream>
#include <stack>

#define psi std::pair<std::string , long long>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::stack<psi> stk;

    std::string cmd;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> cmd;
        if (cmd == "stk_i_a") {
            int m;
            std::cin >> m;
            std::string s;
            long long value;
            for (int j = 0 ; j < m ; j++) {
                std::cin >> s >> value;
                stk.emplace(std::make_pair(s, value));
            }
        } else if (cmd == "stk_p") {
            if (!stk.empty()) {
                std::cout << stk.top().first << ' ' << stk.top().second << '\n';
            }
        } else if (cmd == "stk_d") {
            if (!stk.empty()) {
                stk.pop();
            }
        } else if (cmd == "stk_i") {
            std::string s;
            long long value;
            std::cin >> s >> value;
            stk.emplace(std::make_pair(s , value));
        } else if (cmd == "stk_s") {
            std::cout << stk.size() << '\n';
        } else {
            while (!stk.empty()) {
                std::cout << stk.top().first << ' ' << stk.top().second << '\n';
                stk.pop();
            }
        }
    }
}