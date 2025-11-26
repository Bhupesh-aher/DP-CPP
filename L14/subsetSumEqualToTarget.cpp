#include<bits/stdc++.h>
using namespace std;



// Recursion Solution
bool f(int ind, int target, vector<int> &nums){
    if(target == 0) return true;
    if(ind == 0) {
        if(target == nums[ind]) return true;
        return false;
    }

    bool notPick = f(ind - 1, target, nums);
    bool pick = false;
    if(nums[ind] <= target){
       pick = f(ind - 1, target - nums[ind], nums);
    }
    return pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &nums) {
    return f(n-1, k, nums);
}

// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization

bool f1(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) {
        if(target == nums[ind]) return true;
        return false;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notPick = f1(ind - 1, target, nums, dp);
    bool pick = false;
    if(nums[ind] <= target){
       pick = f1(ind - 1, target - nums[ind], nums, dp);
    }
    return dp[ind][target] = pick | notPick;
}

bool subsetSumToK1(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f1(n-1, k, nums, dp);
}


// TC - O(N * Target) 
// SC - O(N) + O(N * target)     Auxillary stack space  +  dp




// Tabulation 

bool subsetSumToK2(int n, int k, vector<int> &nums) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(nums[0] <= k) dp[0][nums[0]] = true;

    for(int ind = 1; ind < n; ind ++){
        for(int target = 1; target <= k; target ++){
            bool notPick = dp[ind - 1][target];
            bool pick = false;
            if(nums[ind] <= target){
                pick = dp[ind - 1][target - nums[ind]];
            }
            dp[ind][target] = pick | notPick;
        }
    }
    return dp[n-1][k];
}

// TC - O(N * target) 
// SC - O(N * target)     dp




// Space optimization

bool subsetSumToK3(int n, int k, vector<int> &nums) {
    vector<bool> prev(k + 1, 0);
    prev[0] = true;
    if(nums[0] <= k) prev[nums[0]] = true;

    for(int ind = 1; ind < n; ind ++){
        vector<bool> curr(k + 1, 0);
        curr[0] = true;
        for(int target = 1; target <= k; target ++){
            bool notPick = prev[target];
            bool pick = false;
            if(nums[ind] <= target){
                pick = prev[target - nums[ind]];
            }
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}



// TC - O(N * Target) 
// SC - O(Target)     prev




int main(){
    int n = 4;
    vector<int> nums = {2, 1, 3, 4};
    int k = 4;               // k = Target
    cout << subsetSumToK3(n, k, nums);
                          
 
}
