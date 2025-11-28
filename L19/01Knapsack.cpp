#include<bits/stdc++.h>
using namespace std;



// Recursion Solution

int f(int ind, int W, vector<int> &weight, vector<int> &value){
    if(ind == 0){
        if(weight[ind] <= W) return value[ind];
        return 0;
    }

    int notPick = 0 + f(ind - 1, W, weight, value);
    int pick = INT_MIN;
    if(weight[ind] <= W) pick = value[ind] + f(ind - 1, W - weight[ind], weight, value);

    return max(notPick, pick);
}

int knapsack(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    return f(n - 1, maxWeight, weight, value);
}

// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization


int f1(int ind, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
    if(ind == 0){
        if(weight[0] <= W) return value[0];
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notPick = 0 + f1(ind - 1, W, weight, value, dp);
    int pick = INT_MIN;
    if(weight[ind] <= W)
        pick = value[ind] + f1(ind - 1, W - weight[ind], weight, value, dp);

    return dp[ind][W] = max(notPick, pick);
}

int knapsack1(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f1(n - 1, maxWeight, weight, value, dp);
}


// TC - O(N * maxWeight) 
// SC - O(N) + O(N * maxWeight)     Auxillary stack space  +  dp




// Tabulation 

int knapsack2(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    for(int W = weight[0]; W <= maxWeight; W++) dp[0][W] = value[0];

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

// TC - O(N * maxWeight) 
// SC - O(N * maxWeight)     dp




// Space optimization

int knapsack3(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);

    for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

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



// TC - O(N * maxWeight) 
// SC - O 2(maxWeight)     prev and curr





// Space optimization -Single Array Space Optimised 

int knapsack4(int n, vector<int> &weight, vector<int> &value, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);

    for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

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

// TC - O(N * maxWeight) 
// SC - O(maxWeight)     prev 




int main(){
    int n = 3;
    vector<int> weight = {3, 2, 5};
    vector<int> value = {30, 40, 50};
    int maxWeight = 6;
    cout << knapsack4(n, weight, value, maxWeight);

                          
 
}
