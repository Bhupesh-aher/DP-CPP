#include<bits/stdc++.h>
using namespace std;


// This problem can be solved using DP - 14 Tabulation approach. 
// As we can use the same code which we used in DP 14 Tabulation as it is 



// Tabulation 

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += nums[i];
    int k = totalSum;

    // DP - 14 Tabulation code
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(nums[0] <= k)  dp[0][nums[0]] = true;

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

    // dp[n-1][totalSum] we are gonna iterate on this
    // if the particualr col is true then we will calcualte abs(s1 - s2)
    int miniSum = INT_MAX;
    for(int s1 = 0; s1 <= totalSum; s1++){
        if(dp[n-1][s1] == true){
            int s2 = totalSum - s1;
            miniSum = min(miniSum, abs(s1 - s2));
        }
    }
    return miniSum;
}


// TC - O(N * target) + O(2N)
// SC - O(N * target)     dp



// Space optimization

int minimumDifference2(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += nums[i];
    int k = totalSum;

    // DP - 14 Space optimization code
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

    // dp[n-1][totalSum] we are gonna iterate on this
    // if the particualr col is true then we will calcualte abs(s1 - s2)
    int miniSum = INT_MAX;
    for(int s1 = 0; s1 <= totalSum; s1++){
        if(prev[s1] == true){
            int s2 = totalSum - s1;
            miniSum = min(miniSum, abs(s1 - s2));
        }
    }
    return miniSum;
}

// TC - O(N * Target) + O(2N)
// SC - O(Target)     prev


int main(){
    int n = 4;
    vector<int> nums = {3, 2, 7};
    
    cout << minimumDifference2(nums);
                          
 
}
