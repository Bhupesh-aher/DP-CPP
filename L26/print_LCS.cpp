#include<bits/stdc++.h>
using namespace std;

// To print LCS we will use the DP table which we formed while doing tabulation in DP - 25 (LCS)
// I have used the same code of tabulation 
// Once the tabulation is done then with the help of DP array (table) we can form the string 
// Basically we are doing backtracking in the table, we start from n, m index and then goes till any one of the s1 or s2 string gets exhausted


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
    int len =  dp[n][m];
    string ans = "";
    for(int i = 0; i < len; i++){
        ans += '$';
    }

    // O(N + M)

    int index = len - 1;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index --;
            i --;
            j --;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i --;
        }
        else {
            j --;
        }
    }
    cout << ans << endl;
    return 0;
    
}


// TC - O(N * M) + O(N + M)
// SC - O(N * M)      dp






int main(){
    string s1 = "acd";
    string s2 = "ced";

    // Longest Common Subsequence is = cd (so lenght is 2) 
    int n = s1.size();
    int m = s2.size();

    cout << LCS3(n, m, s1, s2);
                          
 
}
