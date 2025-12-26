#include<bits/stdc++.h>
using namespace std;


// We are going to use the approach which we disucss in the DP - 42 where we print the LIS using hash array
// that same code we will use here and will do small change 
// that way we will get length and using hash array will do backtrack and can genrate the largest divisible subset


vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    sort(nums.begin(), nums.end());

    int maxi = 0;
    int lastIndex = 0;

    for(int ind = 0; ind < n; ind ++){
        hash[ind] = ind;
        for(int prev = 0; prev < ind; prev ++){
            // this condition is changed                                    - apart from this everything remains same
            if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            lastIndex = ind;
        }
    }

    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());

    return lis;
}


// TC - O(N * N) + O(LIS length)            
// SC - O (2N)    dp



int main(){
    vector<int> nums = {1, 16, 7, 8, 4};
    
    vector<int> LDS = largestDivisibleSubset(nums);
    for(auto it: LDS) cout << it << " ";


                          
    
}
