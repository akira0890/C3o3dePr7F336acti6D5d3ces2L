#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <queue>

std::string tostring(int n) {
    std::string val = "";
    if (n == 0) return "0";
    while (n > 0) {
        val += ((n % 10) + '0');
        n /= 10;
    }
    std::reverse(val.begin() , val.end());
    return val;
}

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;

    std::unordered_map<std::string , std::pair<int,int>> freq;
    std::vector<std::string> v;

    std::string curr;
    for (char c : s) {
        if (c == '/') {
            if (!curr.empty()) {
                v.emplace_back(curr);
                freq[curr].first++;
            }
            curr = "";
        } else {
            curr += c;
        }
    }
    if (!curr.empty()) {
        v.emplace_back(curr);
        freq[curr].first++;
    } 

    for (std::string &str : v) {
        if (freq[str].first > 1 && !(str == ".." || str == ".")) {
            str += tostring(freq[str].second++);
        }
    }

    std::vector<std::string> q;
    for (std::string &str : v) {
        if (str != ".") {
            if (str == "..") {
                if (!q.empty()) q.pop_back();
            }
            else q.emplace_back(str);
        }
    }

    if (q.empty()) std::cout << "/";
    else {
        std::string ans;
        for (std::string &str : q) {
            ans += "/" + str;
        }

        std::cout << ans;
    }
}