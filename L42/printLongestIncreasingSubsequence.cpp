#include<bits/stdc++.h>
using namespace std;


// In DP - 41 we already discuss the Recursion and  DP Memization code
// in this DP - 42 we will see the Tabulation and Space optimization

// Tabulation 


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for(int ind = n - 1; ind >=0; ind --){
        for(int prevInd = ind - 1; prevInd >= -1; prevInd --){
            int len = 0 + dp[ind + 1][prevInd + 1];
    
            if(prevInd == -1 || nums[ind] > nums[prevInd]){
                len = max(len, 1 + dp[ind + 1][ind+1]);
            }
            dp[ind][prevInd + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

// TC - O(N * N) 
// SC - O(N * N)      dp




// Space optimization

int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int ind = n - 1; ind >=0; ind --){
            for(int prevInd = ind - 1; prevInd >= -1; prevInd --){
                int len = 0 + prev[prevInd + 1];
        
                if(prevInd == -1 || nums[ind] > nums[prevInd]){
                    len = max(len, 1 + prev[ind+1]);
                }
                curr[prevInd + 1] = len;
            }
            prev = curr;
        }
        return prev[-1 + 1];
    }

// TC - O(N * N) 
// SC - O (N * 2)     prev and curr




int main(){
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    
    cout << lengthOfLIS3(nums);


                          
    
}
