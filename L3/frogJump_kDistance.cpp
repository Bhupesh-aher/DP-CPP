#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution

int f(int ind, vector<int> &heights, int k){
    if(ind == 0) return 0;

    int miniSteps = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(ind - j >= 0){
            int jump = f(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);
            miniSteps = min(miniSteps, jump);
        }
    }
    return miniSteps;
}



// DP Memization

int f1(int ind, vector<int> &heights,int k, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int miniSteps = INT_MAX;
    for(int j = 1; j <=k; j++){
        if(ind - j >= 0) {
            int jump = f1(ind - j, heights, k, dp) + abs(heights[ind] - heights[ind - j]);
            miniSteps = min(miniSteps, jump);
        }
    }
    return dp[ind] = miniSteps;
}


// TC - O(N * k)
// SC - O(N) + O(N)         Auxillary stack space + DP heightsay 





int main(){
   
    int n = 5;
    vector<int> heights = {10, 5, 20, 0, 15};
    vector<int> dp(n + 1, -1);
    int k = 2;
    // cout << f1(n - 1, heights, k, dp);




    // Tabulation 
    dp[0] = 0;
    for(int ind = 1; ind < n; ind++){
        int miniSteps = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(ind - j >= 0) {
                int jump = dp[ind - j] + abs(heights[ind] - heights[ind - j]);
                miniSteps = min(miniSteps, jump);
            }
            dp[ind] = miniSteps;
        }
    }
    cout << dp[n - 1];

    // TC - O(N * k)
    // SC - O(N)   
 
}




// Input: heights = [10, 5, 20, 0, 15], k = 2
// Output: 15
// Explanation:
// 0th step -> 2nd step, cost = abs(10 - 20) = 10

// 2nd step -> 4th step, cost = abs(20 - 15) = 5

// Total cost = 10 + 5 = 15.


// Input: heights = [15, 4, 1, 14, 15], k = 3
// Output: 2
// Explanation:
// 0th step -> 3rd step, cost = abs(15 - 14) = 1

// 3rd step -> 4th step, cost = abs(14 - 15) = 1

// Total cost = 1 + 1 = 2.