#include<bits/stdc++.h>
using namespace std;

// To Find Longest Common Substring we will use the Tabulation code (LCS DP - 25) by changing else condition and we
// can easily get the Longest Common Substring



// Tabulation 

int LCS3(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);               // To get the ans we add this line
            }

            else dp[i][j] = 0;                  // this is where we did change
        }
    }
    return ans;
}


// TC - O(N * M) + O(N + M)
// SC - O(N * M)      dp



// Space optimization

int LCS4(int n, int m, string s1, string s2) {
    vector<int> prev(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        vector<int> curr(m + 1, 0);
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);               // To get the ans we add this line
            }

            else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

// TC - O(N * M) 
// SC - O 2(N)     prev and curr







int main(){
    string s1 = "abcjklp";
    string s2 = "acjkp";


    // Longest Common Substring is = cjk (so lenght is 3) 
    int n = s1.size();
    int m = s2.size();

    cout << LCS4(n, m, s1, s2);
                          
    // s1 = abcd   s2 = abzd 
}
