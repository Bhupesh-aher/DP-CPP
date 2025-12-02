#include<bits/stdc++.h>
using namespace std;


// Recursion Solution

int f(int ind, int W, vector<int> &wt, vector<int> &val){
    if(ind == 0){
        if(wt[ind] <= W) {
            return ((int)(W / wt[0])) * val[0];
        }
        return 0;
    }

    int notPick = 0 + f(ind - 1, W, wt, val);
    int pick = INT_MIN;
    if(wt[ind] <= W) pick = val[ind] + f(ind - 1, W - wt[ind], wt, val);

    return max(notPick, pick);
}

int unboundKnapsack(int n, vector<int> &wt, vector<int> &val, int W) {
    return f(n - 1, W, wt, val);
}

// TC - >> O(2 ^ N)             (>> this means greater than 2 ^ N) beacuse we are standing at same index so that means there are not 2 ways on the index. There multiple ways on index
// SC - O(N)  Auxillary stack space (>> this means greater than  N)
// Therotically it is not possible to to tell the exact TC so just say exponential.
// same goes to SC as well.



// DP Memization

int f1(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(ind == 0){
        if(wt[ind] <= W) {
            return ((int)(W / wt[0])) * val[0];
        }
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notPick = 0 + f1(ind - 1, W, wt, val, dp);
    int pick = INT_MIN;
    if(wt[ind] <= W)
        pick = val[ind] + f1(ind - 1, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(notPick, pick);
}

int unboundKnapsack1(int n, vector<int> &wt, vector<int> &val, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f1(n - 1, W, wt, val, dp);
}


// TC - O(N * W) 
// SC - O(N) + O(N * W)     Auxillary stack space  +  dp




// Tabulation 


int unboundKnapsack2(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for(int W = 0; W <= maxWeight; W++) dp[0][W] = ((int)(maxWeight / weight[0])) * value[0];

    for(int ind = 1; ind < n; ind ++){
        for(int W = 0; W <= maxWeight; W++){
            int notPick = 0 + dp[ind - 1][W];
            int pick = INT_MIN;
            if(weight[ind] <= W)
                pick = value[ind] + dp[ind - 1][W - weight[ind]];

            dp[ind][W] = max(notPick, pick);
        }
    }
    return dp[n-1][maxWeight];
}

// TC - O(N * W) 
// SC - O(N * W)      dp




// Space optimization

int unboundKnapsack3(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);

    for(int W = weight[0]; W <= maxWeight; W++) prev[W] =  ((int)(maxWeight / weight[0])) * value[0];

    for(int ind = 1; ind < n; ind ++){
        vector<int> curr(maxWeight + 1, 0);
        for(int W = 0; W <= maxWeight; W++){
            int notPick = 0 + prev[W];
            int pick = INT_MIN;
            if(weight[ind] <= W)
                pick = value[ind] + prev[W - weight[ind]];

            curr[W] = max(notPick, pick);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// TC - O(N * W) 
// SC - O 2(W)     prev and curr










// Space optimization - Single Array Space Optimised 


int unboundKnapsack4(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);

    for(int W = weight[0]; W <= maxWeight; W++) prev[W] = ((int)(maxWeight / weight[0])) * value[0];

    for(int ind = 1; ind < n; ind ++){
        for(int W = maxWeight; W >= 0; W--){
            int notPick = 0 + prev[W];
            int pick = INT_MIN;
            if(weight[ind] <= W)
                pick = value[ind] + prev[W - weight[ind]];

            prev[W] = max(notPick, pick);
        }
    }
    return prev[maxWeight];
}

// TC - O(N * W) 
// SC - O(W)     prev 





int main(){
    int n = 4;
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    cout << unboundKnapsack1(n, wt, val, W);
    
    

                          
 
}
