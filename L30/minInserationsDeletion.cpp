#include<bits/stdc++.h>
using namespace std;

// This problem can easily solved using the logic of finding the longest common subsequence DP - 25
// I have used Tabulation and space optimization code as it is from DP - 25
// if you want to you can also use the recursion and memoization code as well without any shutle change



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
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    return n + m - 2 * (LCS3(n, m, word1, word2));
}

// TC - O(N * M) 
// SC - O(N * M)      dp



// Space optimization

int LCS4(int n, int m, string s1, string s2) {
    vector<int> prev(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++){
        vector<int> curr(m + 1, 0);
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }

            else curr[j] = 0 + max(curr[j - 1], prev[j]);
        }
        prev = curr;
    }
    return prev[m];
    }
int minDistance2(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    return n + m - 2 * (LCS4(n, m, word1, word2));
}


// TC - O(N * M) 
// SC - O 2(N)     prev and curr




int main(){
    string word1 = "abcd";
    string word2 = "anc";
    
    cout << minDistance(word1, word2);
                          
    
}
