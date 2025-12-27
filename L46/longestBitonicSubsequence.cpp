#include<bits/stdc++.h>
using namespace std;


// We are going to use the approach which we disucss in the DP - 42 
// in all cases we did LIS from left to right. here we will do the same
// but we will also do the LIS from right to left as well



int longestBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n, 1);

    for(int ind = 0; ind < n; ind ++){
        for(int prev = 0; prev < ind; prev ++){
            if(nums[prev] < nums[ind] &&  1 + dp1[prev] > dp1[ind]){
                dp1[ind] = 1 + dp1[prev];
            }
        }
    }

    vector<int> dp2(n, 1);

    for(int ind = n-1; ind >= 0; ind --){
        for(int prev = n-1; prev > ind; prev --){
            if(nums[prev] < nums[ind] &&  1 + dp2[prev] > dp2[ind]){
                dp2[ind] = 1 + dp2[prev];
            }
        }
    }
    
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
    
}


// TC - O(N * N) +  O(N * N)   
// SC - O (2N)    dp



int main(){
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    
    cout << longestBitonicSubsequence(nums);
}
