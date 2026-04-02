#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<std::string> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
    std::vector<std::string> stk;

    int stringidx = 0;
    bool left = false;
    std::string cmd;
    for (int i = 0 ; i < n*2 - 1 ; i++) {
        std::cin >> cmd;
        if (cmd == "SHIFT") {
            stk.emplace_back(v[stringidx]);
            stringidx++;
        } else if (cmd == "RIGHT") {
            if (stk.size() >= 2) {
                stk.erase(stk.begin() + stk.size() - 2);
            }
        } else {
            if (stk.size() >= 1) {
                stk.pop_back();
            }
        }

        // for (int i = 0 ; i < stk.size() ; i++) std::cout << stk[i] << ' '; std::cout << '\n';
    }

    // std::cout << '\n';

    std::cout << stk.front();
}