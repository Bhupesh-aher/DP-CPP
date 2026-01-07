#include<bits/stdc++.h>
using namespace std;


// These sequare questions are only 2 or 3 which comes under DP
// and this problem is one of them
// Now these sequare problems are directly solved using the tabulation style code 
// and we don't need recurrion because it makes the code and logic more complex
// using simple yabulation style code solve this prolem easily


int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
    for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            sum += dp[i][j];
        }
    }
    return sum;
}


// TC -  O(N * M) + O(N * M) 
// SC - O(N * M)  DP





int main(){

    vector<vector<int>> mat = {
        {0, 1, 1, 1}, 
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    
    cout << countSquares(mat);
}
