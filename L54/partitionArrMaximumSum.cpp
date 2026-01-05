#include<bits/stdc++.h>
using namespace std;

// Front Partition


// Recursion Solution

int f(int ind, vector<int> &nums, int n, int k){
    if(ind == n) return 0;

    int maxEle = INT_MIN;
    int maxAns = INT_MIN;
    int len = 0;
    for(int j = ind; j < min(n, ind + k); j ++){
        len ++;
        maxEle = max(maxEle, nums[j]);
        int sum = len * maxEle + f(j + 1, nums, n, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}
int maxSumAfterPartitioning(vector<int>& nums, int k) {
    int n = nums.size();
    return f(0, nums, n, k);
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

int f1(int ind, vector<int> &nums, int n, int k, vector<int> &dp){
    if(ind == n) return 0;
    if(dp[ind] != -1) return dp[ind];

    int maxEle = INT_MIN;
    int maxAns = INT_MIN;
    int len = 0;
    for(int j = ind; j < min(n, ind + k); j ++){
        len ++;
        maxEle = max(maxEle, nums[j]);
        int sum = len * maxEle + f1(j + 1, nums, n, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}
int maxSumAfterPartitioning1(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f1(0, nums, n, k, dp);
}


// TC - O(N * k)
// SC - O(N) + O(N)     Auxillary stack space  +  dp



// Tabulation 

int maxSumAfterPartitioning2(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    dp[n] = 0;
    for(int ind = n - 1; ind >=0; ind --){
        int maxEle = INT_MIN;
        int maxAns = INT_MIN;
        int len = 0;
        for(int j = ind; j < min(n, ind + k); j ++){
            len ++;
            maxEle = max(maxEle, nums[j]);
            int sum = len * maxEle + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}



// TC - O(N * k) 
// SC - O(N)      dp





int main(){

    vector<int> nums = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    
    cout << maxSumAfterPartitioning(nums, k);
}
