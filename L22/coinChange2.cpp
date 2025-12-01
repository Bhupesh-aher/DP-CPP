#include<bits/stdc++.h>
using namespace std;



// Recursion Solution

int f(int ind, int T, vector<int> &nums){
    if(ind == 0) {
        if(T % nums[0] == 0) return 1;
        return 0;
    }

    int notTake = f(ind - 1, T, nums);
    int take = 0;
    if(nums[ind] <= T) take = f(ind, T - nums[ind], nums);
    return notTake + take;
}
int change(int target, vector<int>& nums) {
    int n = nums.size();
    return f(n - 1, target, nums);
}

// TC - >> O(2 ^ N)             (>> this means greater than 2 ^ N) beacuse we are standing at same index so that means there are not 2 ways on the index. There multiple ways on index
// SC - O(N)  Auxillary stack space (>> this means greater than  N)
// Therotically it is not possible to to tell the exact TC so just say exponential.
// same goes to SC as well.



// DP Memization

int f1(int ind, int T, vector<int> &nums, vector<vector<int>> &dp){
    if(ind == 0) {
        if(T % nums[0] == 0) return 1;
        return 0;
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = f1(ind - 1, T, nums, dp);
    int take = 0;
    if(nums[ind] <= T) take = f1(ind, T - nums[ind], nums, dp);
    return dp[ind][T] = notTake + take;
}
int change1(int target, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f1(n - 1, target, nums, dp);
}


// TC - O(N * T) 
// SC - O(N) + O(N * T)     Auxillary stack space  +  dp




// Tabulation 
int change2(int target, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int T = 0; T <= target; T++) {
        if(T % nums[0] == 0) dp[0][T] = 1;
        else dp[0][T] = 0;
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            int notTake = dp[ind - 1][T];
            int take = 0;
            if(nums[ind] <= T) take = dp[ind][T - nums[ind]];
            dp[ind][T] = notTake + take;
        }
    }
    return dp[n - 1][target];
}
// TC - O(N * T) 
// SC - O(N * T)      dp




// Space optimization

int change3(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for(int T = 0; T <= target; T++) {
        if(T % nums[0] == 0) prev[T] = 1;
        else prev[T] = 0;
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            int notTake = prev[T];
            int take = 0;
            if(nums[ind] <= T) take = curr[T - nums[ind]];
            curr[T] = notTake + take;
        }
        prev = curr;
    }
    return prev[target];
}


// TC - O(N * T) 
// SC - O(T)      prev






int main(){
    int n = 3;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << "Number of ways to make " << change2(target, nums);
    

                          
 
}
