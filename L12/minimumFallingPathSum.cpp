#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
int f(int i, int j, vector<vector<int>>& grid, int n){
    if(j < 0 || j >= n) return 1e8;
    if(i == 0) return grid[i][j];

    int up = grid[i][j] + f(i - 1, j, grid, n);
    int leftDig = grid[i][j] + f(i - 1, j - 1, grid, n);
    int rightDig = grid[i][j] + f(i - 1, j + 1, grid, n);

    return min(up, min(leftDig, rightDig));
}
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int miniPath = INT_MAX;
    for(int j = 0; j < n; j++){
        miniPath = min(miniPath, f(n-1, j, grid, n));
    }
    return miniPath;
}

// TC - O(3 ^ N) 
// SC - O(N) lenght of the rows (Auxillary stack space)




// DP Memization

int f1(int i, int j, vector<vector<int>>& grid, int n, vector<vector<int>>& dp){
    if(j < 0 || j >= n) return 1e8;
    if(i == 0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f1(i - 1, j, grid, n, dp);
    int leftDig = grid[i][j] + f1(i - 1, j - 1, grid, n, dp);
    int rightDig = grid[i][j] + f1(i - 1, j + 1, grid, n, dp);

    return dp[i][j] = min(up, min(leftDig, rightDig));
}
int minFallingPathSum1(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int miniPath = INT_MAX;
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int j = 0; j < n; j++){
        miniPath = min(miniPath, f1(n-1, j, grid, n, dp));
    }
    return miniPath;
}

// TC - O(N * M) 
// SC - O(N) + O(N * M)   Auxillary stack space + dp




// Tabulation 

int minFallingPathSum2(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int j = 0; j < n; j++) dp[0][j] = grid[0][j];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int up = grid[i][j] + dp[i-1][j];
            int leftDig = grid[i][j];
            if(j -1 >= 0) leftDig += dp[i-1][j-1];
            else leftDig += 1e8;
            int rightDig = grid[i][j];
            if(j + 1 < m) rightDig += dp[i-1][j+1];
            else rightDig += 1e8;

            dp[i][j] = min(up, min(leftDig, rightDig));
        }
    }
    
    int miniPath = INT_MAX;
    for(int j = 0; j < m; j++){
        miniPath = min(miniPath, dp[n-1][j]);
    }
    return miniPath;
}

// TC - O(N * M) + O(N)
// SC - O(N * M)    dp




// Space optimization 

int minFallingPathSum3(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(n, 0);

    for(int j = 0; j < n; j++) prev[j] = grid[0][j];
    
    for(int i = 1; i < n; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j < m; j++){

            int up = grid[i][j] + prev[j];
            int leftDig = grid[i][j];

            if(j -1 >= 0) leftDig += prev[j-1];
            else leftDig += 1e8;

            int rightDig = grid[i][j];
            if(j + 1 < m) rightDig +=  prev[j+1];
            else rightDig += 1e8;

            temp[j] = min(up, min(leftDig, rightDig));
        }
        prev = temp;
    }
    
    int miniPath = INT_MAX;
    for(int j = 0; j < m; j++){
        miniPath = min(miniPath, prev[j]);
    }
    return miniPath;
}

// TC - O(N * M) + O(N)
// SC - O(N)    prev




int main(){
    vector<vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << minFallingPathSum1(grid);                        
 
}
