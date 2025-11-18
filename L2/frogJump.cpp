#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution

int f(int ind, vector<int> &heights){
    if(ind == 0) return 0;

    int oneJump = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int twoJumps = INT_MAX;
    if(ind > 1){
        twoJumps = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }
    return min(oneJump, twoJumps);
}



// DP Memization

int f1(int ind, vector<int> &heights, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int oneJump = f1(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int twoJumps = INT_MAX;
    if(ind > 1){
        twoJumps = f1(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(oneJump, twoJumps);
}


// TC - O(N) 
// SC - O(N) + O(N)         Auxillary stack space + DP heightsay 





int main(){
   
    int n = 6;
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    // vector<int> dp(n + 1, -1);
    // cout << f1(n - 1, heights, dp);



    // Tabulation 
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoJumps = INT_MAX;
        if(i > 1){
            twoJumps = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(oneJump, twoJumps);
    }

    cout << dp[n-1];

    // TC - O(N) 
    // SC - O(N) 





    // Space optimization 
    int prev = 0, prev2 = 0;
    
    for(int i = 1; i < n; i++){
        int oneJump = prev + abs(heights[i] - heights[i - 1]);
        int twoJumps = INT_MAX;
        if(i > 1){
            twoJumps = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curri = min(oneJump, twoJumps);
        prev2 = prev;
        prev = curri;
    }

    cout << prev;

    // TC - O(N) 
    // SC - O(1) 

}

