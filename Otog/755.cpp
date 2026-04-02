#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> prev;
std::vector<char> ch;
std::vector<bool> isprev;

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    prev.resize(n+1,-1);
    ch.resize(n+1);
    isprev.resize(n+1,false);

    int m; char c,cmd;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> cmd;
        if (cmd == 'T') {
            std::cin >> c;
            int p = i-1;
            while (isprev[p]) p = prev[p];
            prev[i] = p;
            ch[i] = c;
        } else {
            std::cin >> m;
            int p = i-m-1;
            while (isprev[p]) p = prev[p];
            prev[i] = p;
            isprev[i] = true;
        }
    }

    int curr = n;
    std::string s = "";
    while (prev[curr] != -1) {
        if (!isprev[curr]) {
            s.push_back(ch[curr]);
        }
        curr = prev[curr];
    }

    std::reverse(s.begin() , s.end());
    std::cout << s;
}