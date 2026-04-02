#include <iostream>
#include <queue>

struct Node {
    long long a , b;
    std::string s;

    Node(long long a , std::string s , long long b) : a(a) , s(s) , b(b) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::string cmd;
    std::queue<Node> q;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> cmd;
        if (cmd == "que_i_a") {
            int t; std::cin >> t;
            long long a,b;
            std::string s;
            for (int i = 0 ; i < t ; i++) {
                std::cin >> a >> s >> b;
                q.emplace(a,s,b);
            }
        } else if (cmd == "que_i") {
            long long a,b;
            std::string s;
            std::cin >> a >> s >> b;
            q.emplace(a , s , b);
        } else if (cmd == "que_d") {
            if (!q.empty()) {
                q.pop();
            }
        } else if (cmd == "que_p_a") {
            while (!q.empty()) {
                std::cout << q.front().a << ' ' << q.front().s << ' ' << q.front().b << '\n';
                q.pop();
            }
        } else if (cmd == "que_p_f") {
            if (!q.empty()) {
                std::cout << q.front().a << ' ' << q.front().s << ' ' << q.front().b << '\n';
            }
        } else if (cmd == "que_p_l") {
            if (!q.empty()) {
                std::cout << q.back().a << ' ' << q.back().s << ' ' << q.back().b << '\n';
            }
        } else if (cmd == "que_s") {
            std::cout << q.size() << '\n';
        }
    }
}