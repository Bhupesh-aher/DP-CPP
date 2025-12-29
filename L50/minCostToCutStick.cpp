#include<bits/stdc++.h>
using namespace std;

// Partition DP 


// Recursion Solution

int f(int i, int j, vector<int> &cuts){
    if(i > j) return 0;
    int mini = INT_MAX;


    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f(i, ind - 1, cuts) + f(ind + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return f(1, c, cuts);
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

int f1(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j) return 0;
    int mini = INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f1(i, ind - 1, cuts, dp) + f1(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minCost1(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c+1, -1));
    return f1(1, c, cuts, dp);
}


// TC - O(C * C) * C 
// SC - O(N) + O(C * C)     Auxillary stack space  +  dp





// Tabulation 

int minCost2(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c+2, 0));

    for(int i = c; i >= 1; i--){
        for(int j = 1; j <= c; j++){
            if(i > j) continue;
            int mini = INT_MAX;
            for(int ind = i; ind <= j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + dp[i][ind - 1] + dp[ind + 1][j];
            mini = min(mini, cost);
        }
        dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

// TC - O(C * C) * C 
// SC - O(C * C)       dp


int main(){

    vector<int> cuts = {1,3,4,5};
    int n = 7;
    
    cout << minCost(n, cuts);
}
