#include<bits/stdc++.h>
using namespace std;



 // DP - 18 code is below because this problem is exact same as DP 18 just they have modified the language
 // so i have direclty used space opimization code
 // in case if you want to try recursion, memoization, tabulation code you can use that code as it is just call
 // countPartition function from findTargetSumWays() function
 // without any change this will work


// space optimization 
int subsetSumToK3(int n, int k, vector<int> &nums) {
    vector<int> prev(k + 1, 0);
    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(nums[0] != 0 && nums[0] <= k) prev[nums[0]] = 1;

    for(int ind = 1; ind < n; ind ++){
        vector<int> curr(k + 1, 0);
        for(int target = 0; target <= k; target ++){
            int notPick = prev[target];
            int pick = 0;
            if(nums[ind] <= target){
                pick = prev[target - nums[ind]];
            }
            curr[target] = pick + notPick;
        }
        prev = curr;
    }
    return prev[k];
}

int countPartition2(int n, int d, vector<int> &nums){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;
    return subsetSumToK3(n, (totalSum - d) / 2, nums);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartition2(n, target, nums);
}




int main(){
    int n = 3;
    vector<int> coins = {1, 2, 3};
    int target = 8;
    cout << "Minimum number of coins " << coinChange2(coins, target);
    

                          
 
}
