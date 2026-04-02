#include <iostream>
#include <set>
#include <string>

int n;
std::set<long long,std::greater<long long>> ans;

void backtrack(int idx , const std::string &s , std::string &curr) {
    if (idx >= n) return;
    
    for (int i = idx ; i < n ; i++) {
        curr.push_back(s[i]);
        ans.emplace(std::stoll(curr));
        backtrack(i+1 , s , curr);
        curr.pop_back();
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> n >> s;

    std::string curr = "";
    backtrack(0,s,curr);
    ans.emplace(0);

    for (auto c : ans) std::cout << c << '\n';
}