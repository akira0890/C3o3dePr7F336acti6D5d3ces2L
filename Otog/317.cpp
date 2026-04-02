#include <iostream>
#include <vector>
#include <unordered_map>

int n,m;
int hod[6];
long long sum = 0;
std::vector<std::vector<int>> ans;

void backtrack(std::vector<int> &curr , int cHod) {
    if (cHod == n) {
        ans.emplace_back(curr);
        return;
    }

    if (cHod > n || curr.size() >= m) return;

    for (int i = 0 ; i < 6 ; i++) {
        curr.emplace_back(hod[i]);
        backtrack(curr , cHod + hod[i]);
        curr.pop_back();
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    for (int i = 0 ; i < 6 ; i++) std::cin >> hod[i];

    std::vector<int> curr;

    backtrack(curr , 0);

    std::cout << ans.size() << '\n' << "E\n";

    for (int i = 0 ; i < ans.size() ; i++) {
        std::cout << ans[i].size() << ' ';
        for (int t : ans[i]) {
            std::cout << t << ' ';
        }
        std::cout << '\n' << "E\n";
    }
}