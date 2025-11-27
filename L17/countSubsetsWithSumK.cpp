#include<bits/stdc++.h>
using namespace std;



// Recursion Solution
int f(int ind, int target, vector<int> &nums){
    if(target == 0) return 1;
    if(ind == 0) {
        if(target == nums[ind]) return 1;
        return 0;
    }

    int notPick = f(ind - 1, target, nums);
    int pick = 0;
    if(nums[ind] <= target){
       pick = f(ind - 1, target - nums[ind], nums);
    }
    return pick + notPick;
}

int subsetSumToK(int n, int k, vector<int> &nums) {
    return f(n-1, k, nums);
}

// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization

int f1(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(ind == 0) {
        if(target == nums[ind]) return 1;
        return 0;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int notPick = f1(ind - 1, target, nums, dp);
    int pick = 0;
    if(nums[ind] <= target){
       pick = f1(ind - 1, target - nums[ind], nums, dp);
    }
    return dp[ind][target] = pick + notPick;
}

bool subsetSumToK1(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f1(n-1, k, nums, dp);
}


// TC - O(N * Target) 
// SC - O(N) + O(N * target)     Auxillary stack space  +  dp




// Tabulation 

int subsetSumToK2(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(nums[0] <= k) dp[0][nums[0]] = 1;

    for(int ind = 1; ind < n; ind ++){
        for(int target = 1; target <= k; target ++){
            int notPick = dp[ind - 1][target];
            int pick = 0;
            if(nums[ind] <= target){
                pick = dp[ind - 1][target - nums[ind]];
            }
            dp[ind][target] = pick + notPick;
        }
    }
    return dp[n-1][k];
}

// TC - O(N * target) 
// SC - O(N * target)     dp




// Space optimization

int subsetSumToK3(int n, int k, vector<int> &nums) {
    vector<int> prev(k + 1, 0);
    prev[0] = 1;
    if(nums[0] <= k) prev[nums[0]] = 1;

    for(int ind = 1; ind < n; ind ++){
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
        for(int target = 1; target <= k; target ++){
            int notPick = prev[target];
            int pick = 0;
            if(nums[ind] <= target){
                pick = prev[target - nums[ind]];
            }
            curr[target] = pick + notPick;
        }
        prev = curr;
    }
    return prev[k];
}



// TC - O(N * Target) 
// SC - O(Target)     prev




int main(){
    int n = 4;
    vector<int> nums = {1, 2, 2, 3};
    int sum = 3;              
    cout << subsetSumToK3(n, sum, nums);
                          
 
}
