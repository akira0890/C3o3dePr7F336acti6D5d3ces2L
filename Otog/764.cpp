#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    unsigned long long n,m,s,start; std::cin >> n >> m >> s; s--;
    start = s;

    std::vector<long long> v(n);
    std::vector<long long> visited(n , 0);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int time = 0;
    while (time < m) {
        if (visited[s] != 0) {
            long long firstloop = visited[s]-1;
            long long cycle = time - firstloop;
            long long remain_m = m - time;

            long long remain = remain_m % cycle;

            for (int i = 0 ; i < remain ; i++) s += v[s];

            std::cout << s+1;
            return 0;
        }

        visited[s] = time + 1;
        s += v[s];
        time++;
    }

    std::cout << s+1;
}

/*
1    2   3   4   5   6   7
1    1   0   1   1   1   1
1    1   0   1   0   1   1

1 2 3 4 5 6 7
1 1 1 1 1 1 1
4 0 3 5 2 1 6
        -
*/