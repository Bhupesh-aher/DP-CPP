#include<bits/stdc++.h>
using namespace std;

// Partition DP 


// Recursion Solution

 int f(int i, int j, vector<int> &nums){
    if(i > j) return 0;

    int maxi = INT_MIN;

    for(int ind = i; ind <= j; ind ++){
        int cost = nums[i-1] * nums[ind] * nums[j + 1] + f(i, ind - 1, nums) + f(ind + 1, j, nums);
        maxi = max(maxi, cost);
    }
    return maxi;
}
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    return f(1, n, nums);
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

 int f1(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;

    for(int ind = i; ind <= j; ind ++){
        int cost = nums[i-1] * nums[ind] * nums[j + 1] + f1(i, ind - 1, nums, dp) + f1(ind + 1, j, nums, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int maxCoins1(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f1(1, n, nums, dp);
}


// TC - O(N * N) * N 
// SC - O(N) + O(N * N)     Auxillary stack space  +  dp





// Tabulation 

iint maxCoins2(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int ind = i; ind <= j; ind ++){
                int cost = nums[i-1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

// TC - O(N * N) * N 
// SC - O(N * N)       dp


int main(){

    vector<int> nums = {3, 1, 5, 8};
    
    cout << minCost(n, cuts);
}
