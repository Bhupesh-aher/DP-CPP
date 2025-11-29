#include<bits/stdc++.h>
using namespace std;




// This problem can be easily solve using same code of DP - 17
// just need to set modified target and rest of the things will remain same
// just handle edges cases fot this problem 
// and i have also added the edge case of Dp - 17 what if array is liek this [0, 0, 1] target = 1
// in this case the ans 4
// but the way we have wrote the code the ans will come out to be 1
// so to habdle this case in Dp 17 i have remove the first base case and added checks in second base case of the code DP 17
// so i have made those changes in below codes as we are using DP 17 code


// Recursion Solution
int f(int ind, int target, vector<int> &nums){
    
    if(ind == 0) {
        if(target == 0 && nums[0] == 0) return 2;
        if(target == 0 || target == nums[0]) return 1;
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


int countPartition(int n, int d, vector<int> &nums){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return subsetSumToK(n, (totalSum - d) / 2, nums);
}

// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization

int f1(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
    if(ind == 0) {
        if(target == 0 && nums[0] == 0) return 2;
        if(target == 0 || target == nums[0]) return 1;
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


int countPartition1(int n, int d, vector<int> &nums){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return subsetSumToK1(n, (totalSum - d) / 2, nums);
}

// TC - O(N * Target) 
// SC - O(N) + O(N * target)     Auxillary stack space  +  dp




// Tabulation 

int subsetSumToK2(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(nums[0] != 0 && nums[0] <= k) dp[0][nums[0]] = 1;

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

int countPartition2(int n, int d, vector<int> &nums){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return subsetSumToK2(n, (totalSum - d) / 2, nums);
}

// TC - O(N * target) 
// SC - O(N * target)     dp




// Space optimization

int subsetSumToK3(int n, int k, vector<int> &nums) {
    vector<int> prev(k + 1, 0);
    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(nums[0] != 0 && nums[0] <= k) prev[nums[0]] = 1;

    for(int ind = 1; ind < n; ind ++){
        vector<int> curr(k + 1, 0);
        for(int target = 0; target <= k; target ++){
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

int countPartition3(int n, int d, vector<int> &nums){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return subsetSumToK3(n, (totalSum - d) / 2, nums);
}



// TC - O(N * Target) 
// SC - O(Target)     prev




int main(){
    int n = 4;
    vector<int> nums = {5, 2, 6, 4};
    int d = 3;              
    cout << countPartition3(n, d, nums);
                          
 
}
