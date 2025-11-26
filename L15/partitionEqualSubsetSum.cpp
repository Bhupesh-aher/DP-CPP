#include<bits/stdc++.h>
using namespace std;


// This problem can be solved using DP - 14 easily. 
// As we can use the same code which we used in DP 14 as it is 

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
bool canPartition2(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += nums[i];
    if(totalSum % 2 == 1) return false;
    return subsetSumToK1(n, totalSum / 2, nums);
}



// TC - O(N * Target) + O(N) 
// SC - O(N) + O(N * target)    Auxillary stack space  +  dp



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
    
bool canPartition3(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += nums[i];
    if(totalSum % 2 == 1) return false;
    int target = totalSum / 2;
    return subsetSumToK3(n, target, nums);
}



// TC - O(N * Target) + O(N)
// SC - O(Target)     prev


int main(){
    int n = 4;
    vector<int> nums = {2, 1, 3, 4};
    
    cout << canPartition3(nums);
                          
 
}
