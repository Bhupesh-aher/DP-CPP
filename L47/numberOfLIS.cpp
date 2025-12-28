#include<bits/stdc++.h>
using namespace std;


// We are going to use the approach which we disucss in the DP - 42 
// and with that we will just maintain the count array



int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    int maxi = 0;

    for(int ind = 0; ind < n; ind ++){
        for(int prev = 0; prev < ind; prev ++){
            if(nums[prev] < nums[ind] &&  1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                count[ind] = count[prev];
            }
            else if(nums[prev] < nums[ind] &&  1 + dp[prev] == dp[ind]){
                count[ind] += count[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    int numOfLIS = 0;
    for(int i = 0; i < n; i++){
        if(maxi == dp[i]) numOfLIS += count[i];
    }
    return numOfLIS;
}


// TC - O(N * N) +  O(N)   
// SC - O (2N)    dp



int main(){
    vector<int> nums = {1, 3, 5, 4, 7};
    
    cout << findNumberOfLIS(nums);
}
