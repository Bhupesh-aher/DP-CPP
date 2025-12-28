#include<bits/stdc++.h>
using namespace std;

// Partition DP 


// Recursion Solution

int f(int i, int j, vector<int> &nums){
    if(i == j) return 0;
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = nums[i-1] * nums[k] * nums[j] + f(i, k, nums) + f(k + 1, j, nums);
        if(steps < mini) mini = steps;
    }
    return mini;
}

int matrixChainMultiplication(vector<int> nums){
    int n = nums.size();
    return f(1, n - 1, nums);
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

int f1(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = nums[i-1] * nums[k] * nums[j] + f1(i, k, nums, dp) + f1(k + 1, j, nums, dp);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}

int matrixChainMultiplication1(vector<int> nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f1(1, n - 1, nums, dp);
}


// TC - O(N * N) * N 
// SC - O(N) + O(N * N)     Auxillary stack space  +  dp





// Tabulation 

int matrixChainMultiplication2(vector<int> nums){
    int n = nums.size();
    int dp[n][n];

    for(int  i = 1; i <n; i++) dp[i][i] = 0;            // base case

    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = nums[i-1] * nums[k] * nums[j] + dp[i][k] + dp[k+1][j];
                if(steps < mini) mini = steps;
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

// TC - O(N * N) * N 
// SC - O(N * N)       dp


int main(){

    vector<int> nums = {10, 20, 30, 40, 50};
    
    cout << matrixChainMultiplication(nums);
}
