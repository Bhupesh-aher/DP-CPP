#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
int f(int i, int j, vector<vector<int>> &grid, int n){
    if(i == n - 1) return grid[i][j];
    int down = grid[i][j] + f(i + 1, j, grid, n);
    int digonal = grid[i][j] + f(i + 1, j + 1, grid, n);
    return min(down, digonal);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return f(0, 0, triangle, n);
}

// TC - O(2 ^ N) 
// SC - O(N) lenght of the rows (Auxillary stack space)




// DP Memization

 int f1(int i, int j, vector<vector<int>> &grid, int n, vector<vector<int>> &dp){
    if(i == n - 1) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = grid[i][j] + f1(i + 1, j, grid, n, dp);
    int digonal = grid[i][j] + f1(i + 1, j + 1, grid, n, dp);
    
    return dp[i][j] = min(down, digonal);
}
int minimumTotal1(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f1(0, 0, triangle, n, dp);
}

// TC - O(N * M) 
// SC - O(N) + O(N * N)   Auxillary stack space + dp




// Tabulation 

int minimumTotal2(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int j = 0; j < n; j++){
        dp[n-1][j] = grid[n-1][j];
    }
    for(int i = n - 2; i>=0; i--){
        for(int j = i; j >=0; j--){
            int down = grid[i][j] + dp[i+1][j];
            int dignoal = grid[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, dignoal);
        }
    }
    return dp[0][0];
}

// TC - O(N * N) 
// SC - O(N * M)    dp


// Space optimization 

int minimumTotal3(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> front(n, 0);
    
    for(int j = 0; j < n; j++){
        front[j] = grid[n-1][j];
    }
    for(int i = n - 2; i>=0; i--){
        vector<int> temp(n, 0);
        for(int j = i; j >=0; j--){
            int down = grid[i][j] + front[j];
            int dignoal = grid[i][j] + front[j+1];
            temp[j] = min(down, dignoal);
        }
        front = temp;
    }
    return front[0];
}

// TC - O(n * m) 
// SC - O(n)    front




int main(){
    vector<vector<int>> grid = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    cout << minimumTotal2(grid);                        
 
}
