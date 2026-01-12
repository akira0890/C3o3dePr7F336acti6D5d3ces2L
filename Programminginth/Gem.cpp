#include <iostream>
#include <vector>

#define pii std::pair<int,int>

bool dfs(const std::vector<pii> &p, const std::vector<int> &forbid, std::vector<bool> visited, int n, int index) {
    if (index >= n) return true;

    std::cout << "current: " << p[index].first << '(' << visited[p[index].first] << ')' << "  " << p[index].second << '(' << visited[p[index].second] << ')' << '\n';
    bool res = false;
    if (!visited[p[index].first]) {
        visited[forbid[p[index].first]] = true;
        // std::cout << "Choose: " << p[index].first << " : " << forbid[p[index].first] << '\n';
        res = dfs(p,forbid,visited,n,index+1);
        visited[forbid[p[index].first]] = false;
    }
    if (!visited[p[index].second]) {
        visited[forbid[p[index].second]] = true;
        // std::cout << "Choose: " << p[index].second << " : " << forbid[p[index].second] << '\n';
        res = dfs(p,forbid,visited,n,index+1) || res;
        visited[forbid[p[index].second]] = false;
    }
    return res;
}

int main() {
    int n,m,t1,t2;

    for (int i = 0 ; i < 1 ; i++) {
        std::cin >> n >> m;

        std::vector<pii> p(n);
        std::vector<int> forbid(m+1,0);
        std::vector<bool> visited(m+1,0);

        for (int j = 0 ; j < n ; j++) {
            std::cin >> t1 >> t2;
            p[j] = {t1,t2};
        }

        for (int j = 0 ; j < m/2 ; j++) {
            std::cin >> t1 >> t2;
            forbid[t1] = t2;
            forbid[t2] = t1;
        }

        if (dfs(p,forbid,visited,n,0)) std::cout << 'Y';
        else                   std::cout << 'N';
    }
}