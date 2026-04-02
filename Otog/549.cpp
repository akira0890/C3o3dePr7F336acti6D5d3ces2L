#include <iostream>
#include <stack>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::stack<long long> stk;
    std::string cmd;

    long long val;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> cmd;

        if (cmd == "push") {
            std::cin >> val;
            stk.emplace(val);
        } else {
            if (stk.empty()) std::cout << "null\n";
            else {
                std::cout << stk.top() << '\n';
                stk.pop();
            }
        }
    }
}