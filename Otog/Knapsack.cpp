#include <iostream>

int n;
int wt[1000];
int val[1000];

long long dp[1005][1005];

long long recursive(int N , int weight) {
    if (N < 0 || weight <= 0) return 0;
    if (dp[N][weight]) return dp[N][weight];
    
    long long res;
    res = recursive(N-1 , weight);
    if (weight >= wt[N]) res = std::max(res , recursive(N-1 , weight - wt[N]) + val[N]);

    return dp[N][weight] = res;
}

int main() {
    std::cin >> n;
    int maxWeight; std::cin >> maxWeight;
    for (int i = 0 ; i < n ; i++) std::cin >> wt[i];
    for (int i = 0 ; i < n ; i++) std::cin >> val[i];

    std::cout << recursive(n-1 ,  maxWeight);
}

// C++ program for solving 0/1 Knapsack Problem using
// recursion

// #include <iostream>
// #include <vector>
// using namespace std;

// // Recursive function to solve 0/1 Knapsack problem
// int knapsackRecursive(vector<int>& weight,
//                       vector<int>& value, int W, int n)
// {
//     // Base case: no items left or capacity is 0
//     if (n == 0 || W == 0)
//         return 0;

//     // If weight of the nth item is more than knapsack
//     // capacity W, it cannot be included
//     if (weight[n - 1] > W)
//         return knapsackRecursive(weight, value, W, n - 1);

//     // Return the maximum of two cases: (1) nth item
//     // included (2) not included
//     return max(value[n - 1]
//                    + knapsackRecursive(weight, value,
//                                        W - weight[n - 1],
//                                        n - 1),
//                knapsackRecursive(weight, value, W, n - 1));
// }

// int main()
// {
//     // define a vector of weight
//     vector<int> weight = { 12 , 7 , 11 , 8 , 9 };

//     // define a vector of value
//     vector<int> value = { 24 , 13 , 23 , 15 , 16 };

//     // Knapsack capacity
//     int W = 26;

//     // call the recusrsive function and print the max value
//     // obtained
//     cout << "Maximum value = "
//          << knapsackRecursive(weight, value, W,
//                               weight.size())
//          << endl;
//     return 0;
// }