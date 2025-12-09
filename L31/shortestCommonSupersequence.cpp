#include<bits/stdc++.h>
using namespace std;

// If we want to find the lenght of the shotest Common Supersequence 
// Then the below code is using DP - 25 LCS code as it is 
// i have used tabulation code you can use recusrion, memoization, spaxe optimization code as well, without a shutle change


// Tabulation 

int LCS3(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else dp[i][j] = 0 + max(dp[i][j - 1], dp[i - 1][j]);
        }

    }
    return dp[n][m];
}
int shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    return n + m -  LCS3(n, m, str1, str2);
    
}


// TC - O(N * M) 
// SC - O(N * M)      dp








int main(){
    string str1 = "brute";
    string str2 = "groot";
    
    cout << shortestCommonSupersequence(str1, str2);
    cout << shortestCommonSupersequence2(str1, str2);

                          
    
}
