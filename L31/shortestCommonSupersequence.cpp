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



// If you want to print the shotest Common Supersequence 
// Then we can use the DP - 26 logic to print the ans. 
// DP - 26 uses the Dp - 25  tabulation code
// by just adding one extra condtion in the code of DP - 26



string shortestCommonSupersequence2(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
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
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i --;
            j --;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            ans += s1[i-1];
            i --;
        }
        else {
            ans += s2[j-1];
            j --;
        }
    }   
    while(i > 0){
        ans += s1[i-1];
        i --;
    }
    while(j > 0){
        ans += s2[j-1];
        j --;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}





int main(){
    string str1 = "brute";
    string str2 = "groot";
    
    cout << shortestCommonSupersequence(str1, str2);
    cout << shortestCommonSupersequence2(str1, str2);

                          
    
}
