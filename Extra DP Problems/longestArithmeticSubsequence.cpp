#include<bits/stdc++.h>
using namespace std;



// Recursion Solution

  int solve(int ind, int diff, vector<int> &nums){
    if(ind < 0) return 0;
    int ans = 0;
    for(int j = ind - 1; j >=0; j--){
        if(nums[ind] - nums[j] == diff){
            ans = max(ans, 1 + solve(j, diff, nums));
        }
    }
    return ans;
}
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
        }
    }
    return ans;
}





// DP Memization

int solve1(int ind, int diff, vector<int> &nums, unordered_map<int, int> dp[]){
    if(ind < 0) return 0;
    if(dp[ind].count(diff)) return dp[ind][diff];
    int ans = 0;
    for(int j = ind - 1; j >=0; j--){
        if(nums[ind] - nums[j] == diff){
            ans = max(ans, 1 + solve1(j, diff, nums, dp));
        }
    }
    return dp[ind][diff] = ans;
}
int longestArithSeqLength1(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    unordered_map<int, int> dp[n + 1];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans = max(ans, 2 + solve1(i, nums[j] - nums[i], nums, dp));
        }
    }
    return ans;
}





// Tabulation 

int longestArithSeqLength2(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    unordered_map<int, int> dp[n + 1];
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i] - nums[j];
            int cnt = 1;

            // check if answer already present
            if(dp[j].count(diff)) {
                cnt = dp[j][diff];
            }
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}




int main(){
    vector<int> nums = {3, 6, 9, 12};
    cout << longestArithSeqLength(nums);

}
