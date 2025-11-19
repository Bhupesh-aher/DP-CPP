#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution

int f(int ind, vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = 0 + f(ind - 1, nums);
    return max(pick, notPick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    return f(n - 1 , nums);
}

// TC - O(N ^ 2) 
// SC - O(N) 





// DP Memization

int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notPick = 0 + f(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n - 1 , nums, dp);
}

// TC - O(N)
// SC - O(N) + O(N)         Auxillary stack space + DP heightsay 




// Tabulation 

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for(int ind = 1; ind < n; ind++){
        int pick = nums[ind];
        if(ind > 1) pick += dp[ind-2];
        int notPick = 0 + dp[ind - 1];
        dp[ind] = max(pick, notPick);
    }
    return dp[n-1];
}

// TC - O(N)
// SC - O(N)   



// Space Optimization 

int rob(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i <n; i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;
        
        int notPick = 0 + prev;
        int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

// TC - O(N) 
// SC - O(1)



int main(){
   
    
 
}
