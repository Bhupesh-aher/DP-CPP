#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
int f(int i, int j, vector<vector<int>> &grid){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e8;
    int up = grid[i][j] + f(i - 1, j, grid);
    int left = grid[i][j] + f(i, j -1, grid);
    return min(up, left);
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(n - 1, m - 1, grid);
}

// TC - O(2 ^ n * m) 
// SC - O(path lenght)




// DP Memization

int f1(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e8;
    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f1(i - 1, j, grid, dp);
    int left = grid[i][j] + f1(i, j -1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum1(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n - 1, m - 1, grid, dp);
}

// TC - O(n * m) 
// SC - O(path lenght) + O(n * m)
    // (n - 1, m - 1)



// Tabulation 

 int minPathSum2(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) continue;
            else {
                int up = 0;
                if(i > 0) up = grid[i][j] + dp[i-1][j];
                else up = 1e8;

                int left = 0;
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                else left = 1e8;
                
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

// TC - O(n * m) 
// SC - O(n * m)


// Space optimization 

int minPathSum3(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);
    
    for(int i = 0; i <n; i++){
        vector<int> temp(m, 0);
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) temp[j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up +=  prev[j];
                else up += 1e8;

                int left = grid[i][j];
                if(j > 0) left +=  temp[j-1];
                else left += 1e8;

                temp[j] = min(up, left);
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
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << minPathSum2(grid);                        
 
}
