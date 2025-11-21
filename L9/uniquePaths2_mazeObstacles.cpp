#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
int f(int i, int j, vector<vector<int>> &grid){
    if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    int up = f(i - 1, j, grid);
    int left = f(i, j - 1, grid);
    return up + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(n - 1, m - 1, grid);
}

// TC - O(2 ^ n * m) 
// SC - O(path lenght)




// DP Memization

int f1(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f1(i - 1, j, grid, dp);
    int left = f1(i, j - 1, grid, dp);
    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles1(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n - 1, m - 1, grid, dp);
}

// TC - O(n * m) 
// SC - O(path lenght) + O(n * m)
    // (n - 1, m - 1)



// Tabulation 

int uniquePathsWithObstacles2(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) continue;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

// TC - O(n * m) 
// SC - O(n * m)


// Space optimization 

int uniquePathsWithObstacles3(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(n, 0);

    for(int i = 0; i < n; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) temp[j] = 0;
            else if(i == 0 && j == 0) temp[j] = 1; 
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = temp[j-1];
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
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << uniquePathsWithObstacles2(grid);                        
 
}
