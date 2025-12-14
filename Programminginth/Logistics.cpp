/*
The problem is to find sum of the median of cost between two station if it can't travel from 'X' to 'Y' then print broken

This code use two directional graph
first dfs or bfs thorugh 'X' to check if from 'X' can travel to 'Y'
if it can't travel from X to Y then print broken
if it can travel dfs start at X and calculate Median of the cost between two station by sort the cost and find the median of it
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

int main() {
    int n,t,in = 0;
    float asum = 0;
    char a,b;
    std::cin >> n;

    std::unordered_map<char , std::vector<std::pair<char,int>>> g;
    std::unordered_map<char, bool> visited;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> a >> b >> t;
        g[a].emplace_back(std::make_pair(b,t));
        g[b].emplace_back(std::make_pair(a,t));
        visited[a] = false;
        visited[b] = false;
    }

    std::queue<char> q;
    for (auto [dest, w] : g['X']) q.emplace('X');
    visited['X'] = true;

    while (!q.empty()) {
        char from = q.front();
        q.pop();

        for (auto [nd , nw] : g[from]) {
            if (!visited[nd]) {
                q.emplace(nd);
                visited[nd] = true;
            }
        }
    }

    if (!visited['Y']) {
        std::cout << "broken";
        return 0;
    }

    for (auto it = visited.begin() ; it != visited.end() ; it++) it->second = false;

    q.emplace('X');
    std::vector<int> temp;

    while (!q.empty()) {
        char from = q.front();
        char next;
        q.pop();

        if (from == 'Y') continue;

        visited[from] = true;
        int count = 0;

        for (auto [nd, nw] : g[from]) {
            if (!visited[nd]) {
                temp.emplace_back(nw);
                if (count == 0) {
                    q.emplace(nd);
                    next = nd;
                }
                count++;
            }
        }

        std::sort(temp.begin(), temp.end());
        
        float res;
        if (count%2 == 0) {
            res = (temp[count/2] + temp[count/2 - 1])/2.0;
        } else {
            res = temp[(count)/2];
        }

        temp.assign(0,0);
        std::printf("%c %c %.1f\n",from, next, res);
        asum += res;
    }
    std::printf("%.1f",asum);
}


/*
std::queue<std::pair<std::pair<char,char>, int>> q;
    for (auto [dest, w] : g['X']) q.emplace(std::make_pair(std::make_pair('X',dest) , w));
    while (!q.empty()) {
        auto [p , w] = q.front();
        char from = p.first;
        char dest = p.second;
        q.pop();

        visited[dest] = true;

        for (auto [nd , nw] : g[dest]) {
            if (!visited[nd]) {
                q.emplace(std::make_pair(std::make_pair(dest, nd) , nw));
            }
        }
    }

    if (!visited['Y']) {
        std::cout << "broken";
        return 0;
    }

    for (auto it = visited.begin() ; it != visited.end() ; it++) it->second = false;

    q.emplace(std::make_pair(std::make_pair('X',g['X'].front().first) , g['X'].front().second));
    visited['X'] = true;

    while (!q.empty()) {
        auto [p , w] = q.front();
        char from = p.first;
        char dest = p.second;
        q.pop();

        int sum = 0;

        for (auto [nd, nw] : g[from]) {
            sum += nw;
            if (!visited[nd]) {
                q.emplace(std::make_pair(std::make_pair(nd, g[nd].front().first), g[nd].front().second));
                visited[nd] = true;
                std::cout << "push " << nd << ' ' << g[nd].front().first << ' ';
            }
        }

        float res = (float)sum / g[from].size();
        std::printf("%c %c %.1f %d %d\n",from, dest, res, sum, g[from].size());
        asum += res;
    }
    std::printf("%.1f",asum);
*/