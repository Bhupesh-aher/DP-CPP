#include<bits/stdc++.h>
using namespace std;



// Recursion Solution

int f(int ind, int T, vector<int> &nums){
    if(ind == 0){
        if(T % nums[ind] == 0) return T / nums[ind];
        return 1e9;
    }

    int notTake = 0 + f(ind - 1, T, nums);
    int take = INT_MAX;
    if(nums[ind] <= T) take = 1 + f(ind,  T - nums[ind], nums);

    return min(notTake, take);
}
int coinChange(vector<int>& coins, int target) {
    int n = coins.size();
    int ans = f(n - 1, target, coins);
    if(ans >= 1e9) return -1;
    return ans;
}

// TC - >> O(2 ^ N)             (>> this means greater than 2 ^ N) beacuse we are standing at same index so that means there are not 2 ways on the index. There multiple ways on index
// SC - O(N)  Auxillary stack space (>> this means greater than  N)
// Therotically it is not possible to to tell the exact TC so just say exponential.
// same goes to SC as well.



// DP Memization


int f1(int ind, int T, vector<int> &nums, vector<vector<int>> &dp){
    if(ind == 0){
        if(T % nums[ind] == 0) return T / nums[ind];
        return 1e9;
    }

    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = 0 + f1(ind - 1, T, nums, dp);
    int take = INT_MAX;
    if(nums[ind] <= T) take = 1 + f1(ind,  T - nums[ind], nums, dp);

    return dp[ind][T] = min(notTake, take);
}
int coinChange1(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = f1(n - 1, target, coins, dp);
    if(ans >= 1e9) return -1;
    return ans;
}


// TC - O(N * T) 
// SC - O(N) + O(N * T)     Auxillary stack space  +  dp




// Tabulation 

int coinChange2(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
    for(int T = 0; T <= target; T++){
        if(T % nums[0] == 0) dp[0][T] = T / nums[0];
        else dp[0][T] = 1e9;
    }

    for(int ind = 1; ind < n; ind ++){
        for(int T = 0; T <= target; T++){
            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if(nums[ind] <= T) take = 1 + dp[ind][T - nums[ind]];

            dp[ind][T] = min(notTake, take);
        }
    }
    return dp[n-1][target];
}

// TC - O(N * T) 
// SC - O(N * T)      dp




// Space optimization

int coinChang3(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for(int T = 0; T <= target; T++){
        if(T % nums[0] == 0) prev[T] = T / nums[0];
        else prev[T] = 1e9;
    }

    for(int ind = 1; ind < n; ind ++){
        for(int T = 0; T <= target; T++){
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if(nums[ind] <= T) take = 1 + curr[T - nums[ind]];

            curr[T] = min(notTake, take);
        }
        prev = curr;
    }
    int ans = prev[target];
    if(ans >= 1e9) return -1;
    return ans;
}


// TC - O(N * T) 
// SC - O(T)      prev






int main(){
    int n = 3;
    vector<int> coins = {1, 2, 3};
    int target = 8;
    cout << "Minimum number of coins " << coinChange2(coins, target);
    

                          
 
}
