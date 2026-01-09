#include<bits/stdc++.h>
using namespace std;






// Tabulation 

int longestSubsequence(vector<int>& arr, int diff) {
    int n = arr.size();
    unordered_map<int, int> dp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int temp = arr[i] - diff;
        int tempAns = 0;

        if(dp.count(temp)){
            tempAns = dp[temp];
        }
        dp[arr[i]] = 1 + tempAns;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

// TC - O(N) 
// SC - O(N)     dp



int main(){
    
    vector<int> nums = {1, 2, 3, 4};
    int  difference = 1;
    cout << longestSubsequence(nums, difference);

                          
 
}
