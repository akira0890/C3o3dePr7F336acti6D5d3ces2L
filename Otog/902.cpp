#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int m; std::cin >> m;
        std::vector<int> v(m+1);
        std::vector<bool> visited(m+1 , false);

        int answer = 1;

        for (int i = 1 ; i <= m ; i++) std::cin >> v[i];

        for (int i = 1 ; i <= m ; i++) {
            if (!visited[i]) {
                int curr = i;

                int sizes = 0;
                while (!visited[curr]) {
                    visited[curr] = true;
                    sizes++;
                    curr = v[curr];
                }

                int cAns;

                if (sizes == 1) cAns = 1;
                else if (sizes % 2 == 0) cAns = 2;
                else cAns = 3;

                answer = std::max(answer , cAns);
            }
        }

        std::cout << answer << '\n';
    }
}