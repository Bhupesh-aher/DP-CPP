#include<bits/stdc++.h>
using namespace std;

// We can again solve this problem using LCS (DP-25) 
// and if want to print if use LCS (DP - 26) function to print it



// Tabulation (DP - 25)


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

int longestPalindromicSubsequence(int n, string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = s2.size();
    return LCS3(n, m, s1, s2);
}



// TC - O(N * M) + O(N + M)
// SC - O(N * M)      dp











int main(){
    string s = "bbbab";

    //  subsequences for given string s => "ab", "bb", "bbb", "bbbb", "bab" and there are lot more subsequencse for string s
    //  Palindromic Subsequence for given string s are  =>  "bb", "bbb", "bbbb", "bab"
    // Longest Palindromic Subsequence is => "bbbb" (lenght of it is 4)


    int n = s.size();
   

    cout << longestPalindromicSubsequence(n, s);
                          
    
}
