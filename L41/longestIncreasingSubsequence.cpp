#include<bits/stdc++.h>
using namespace std;





// Recursion Solution

int f(int ind, int prevInd, vector<int> &nums, int n){
    if(ind == n) return 0;

    int notPick = 0 + f(ind + 1, prevInd, nums, n);
    int pick = 0;
    if(prevInd == -1 || nums[ind] > nums[prevInd]){
        pick = 1 + f(ind + 1, ind, nums, n);
    }
    return max(pick, notPick);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return f(0, -1, nums, n);
}

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space


int f(int ind, int prevInd, vector<int> &nums, int n){
    if(ind == n) return 0;

    int len = 0 + f(ind + 1, prevInd, nums, n);
    
    if(prevInd == -1 || nums[ind] > nums[prevInd]){
        len = max(len, 1 + f(ind + 1, ind, nums, n));
    }
    return len;
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return f(0, -1, nums, n);
}

// this above code is also Recursion code just in short cut way
// both above code is exact same just second code is short so you can use anyone





// DP Memization

int f1(int ind, int prevInd, vector<int> &nums, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;

    if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

    int len = 0 + f1(ind + 1, prevInd, nums, n, dp);
    
    if(prevInd == -1 || nums[ind] > nums[prevInd]){
        len = max(len, 1 + f1(ind + 1, ind, nums, n, dp));
    }
    return dp[ind][prevInd + 1] = len;
}
public:
int lengthOfLIS1(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f1(0, -1, nums, n, dp);
}

// we did N + 1 and prevInd + 1
// because we are starting the prevInd with -1 
// and we cannot store negative index so for that we just shifted prevInd by + 1 on right side
// we have done this in some previous problems same logic here we have used to shift the index
// but shifting is only done for prevInd and not for ind
// that's why only prevInd we have done + 1




// TC - O(N * N) 
// SC - O(N) + O(N * N)     Auxillary stack space  +  dp



// Tabulation and space optimization code we will see in DP - 42



int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    
    cout << lengthOfLIS1(nums);

                          
    
}
