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



// Best solution uses the weird mehtod which we are going to discuss
// it's tabulation method but in different way 

// [5, 4, 11, 1, 16, 8]
//  1  1  2   1   3  2          DP[i] - significes the largest IS that ends at index i

// 16 has 3 means we can have longest IS as [4, 11, 16] or [5, 11, 16]
// and lenght for LIS is  3  (max of all DP[i])


int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    for(int ind = 0; ind < n; ind ++){
        for(int prev = 0; prev < ind; prev ++){
            if(nums[prev] < nums[ind]){
                dp[ind] = max(1 + dp[prev], dp[ind]);
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}


// TC - O(N * N) 
// SC - O (N)    dp



// Now above solution is required if we want to trace back the LIS in order to print LIS
// we will do backtrack in order to print LIS
// we will carry one more array hash with our DP
// and that hash array will say who was the previous index

// [5, 4, 11, 1, 16, 8] dry run this example on code you will understand the approach to print LIS




int lengthOfLIS3(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    int maxi = 0;
    int lastIndex = 0;

    for(int ind = 0; ind < n; ind ++){
        hash[ind] = ind;
        for(int prev = 0; prev < ind; prev ++){
            if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind]){
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

    for(auto it: lis) cout << it << " ";
    cout << endl;

    return maxi;
}


// TC - O(N * N) + O(LIS length)            
// SC - O (2N)    dp

int main(){
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    
    cout << lengthOfLIS3(nums);


                          
    
}
