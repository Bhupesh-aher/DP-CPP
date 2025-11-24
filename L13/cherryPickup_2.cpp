#include<bits/stdc++.h>
using namespace std;



// Recursion Solution
int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m){
    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e8;
    if(i == n - 1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1; dj1++){
        for(int dj2 = -1; dj2 <= +1; dj2 ++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f(i + 1, j1 + dj1, j2 + dj2, grid, n, m);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(0, 0, m - 1, grid, n, m);
}

// TC - O(3 ^ N * 3 ^ N) 
// SC - O(N) lenght of the rows (Auxillary stack space)




// DP Memization

int f1(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e8;

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    if(i == n - 1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1; dj1++){
        for(int dj2 = -1; dj2 <= +1; dj2 ++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f1(i + 1, j1 + dj1, j2 + dj2, grid, n, m, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup1(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return f1(0, 0, m - 1, grid, n, m, dp);
}

// TC - O(N * M * M) 
// SC - O(N) + O(N * M * M)    Auxillary stack space  +  dp







int main(){
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}

    };
    cout << cherryPickup1(grid);                        
 
}
