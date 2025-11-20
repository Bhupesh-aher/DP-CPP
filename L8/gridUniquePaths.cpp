#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
int f(int row, int col, int n, int m){
    if(row == 0 && col == 0) return 1;
    if(row < 0 || col < 0) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int up = f(row - 1, col, n, m);
    int left = f(row, col - 1, n, m );
    
    return up + left;
}
int uniquePaths(int n, int m) {
    return f(n-1, m-1, n, m);
}

// TC - O(2 ^ n * m) 
// SC - O(path lenght)




// DP Memization

int f1(int row, int col, int n, int m, vector<vector<int>> &dp){
    if(row == 0 && col == 0) return 1;
    if(row < 0 || col < 0) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int up = f1(row - 1, col, n, m, dp);
    int left = f1(row, col - 1, n, m, dp);
    
    return dp[row][col] = up + left;
}
int uniquePaths1(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n-1, m-1, n, m, dp);
}

// TC - O(n * m) 
// SC - O(path lenght) + O(n * m)
    // (n - 1, m - 1)



// Tabulation 

int uniquePaths(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) continue;
            else {
                int up = 0;
                int left = 0;
                if(i > 0)  up = dp[i-1][j];
                if(j > 0)  left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

// TC - O(n * m) 
// SC - O(n * m)



// Space optimization 

int uniquePaths(int n, int m) {
    vector<int> prev(n, 0);
    for(int i = 0; i < n; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) temp[j] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[m-1];
}

// TC - O(n * m) 
// SC - O(n)




int main(){
    int n = 3, m = 3;
    cout << uniquePaths1(n, m);                        
 
}
