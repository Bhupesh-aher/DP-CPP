#include<bits/stdc++.h>
using namespace std;


// Recursion Solution

int f(int ind1, int ind2, string &s1, string &s2){
    if(ind1 < 0 || ind2 < 0) return 0;

    if(s1[ind1] == s2[ind2]){
        return 1 + f(ind1 - 1, ind2 - 1, s1, s2);
    }

    return 0 + max(f(ind1, ind2 - 1, s1, s2), f(ind1 - 1, ind2, s1, s2));
}

int LCS(int n, int m, string s1, string s2) {
    return f(n-1, m-1, s1, s2);
}

// TC - O(2 ^ N * 2 ^ M)        exponential
// SC - O(N + M)  Auxillary stack space



// DP Memization

int f1(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]){
        return dp[ind1][ind2] = 1 + f1(ind1 - 1, ind2 - 1, s1, s2, dp);
    }

    return dp[ind1][ind2] = 0 + max(f1(ind1, ind2 - 1, s1, s2, dp), f1(ind1 - 1, ind2, s1, s2, dp));
}

int LCS1(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n-1, m-1, s1, s2, dp);
}


// TC - O(N * M) 
// SC - O(N + M) + O(N * M)     Auxillary stack space  +  dp





// Now if we try to write base case for tabulation we can't write like this dp[-1][somehting]
// because we can't acceess the negative index
// so to do change we will do shifting on index
// that means will shift index by one on the right side
// f(1) means f(0), f(n) means f(n-1) and f(-1) means f(0)
// so that's how we can easily write the base case
// base case will be 
// if(ind1 == 0 || ind2 == 0) return 0;
// because previously ind1 < 0 || ind2 < 0 means that ind1 or ind2 is -1 
// since i shifting index by one on right side 
// f(-1) will be treated as f(0)

// i have write the Memization code again just to understand the shifting index logic and code
// only change is in the base case and first if condition when both string chars are mathced or not
// other than that everything remains exactly same
// remember there is no need of shifting index in recursion and Memization, but we need to do in tabulation
// but just to show how we can do it i have done in the Memization as well in below code  (LCS2 f2)


// DP Memization - After index shifting by one on right side


int f2(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
    if(ind1 == 0 || ind2 == 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1 - 1] == s2[ind2 - 1]){
        return dp[ind1][ind2] = 1 + f2(ind1 - 1, ind2 - 1, s1, s2, dp);
    }

    return dp[ind1][ind2] = 0 + max(f2(ind1, ind2 - 1, s1, s2, dp), f2(ind1 - 1, ind2, s1, s2, dp));
}

int LCS2(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, s1, s2, dp);
}


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

// TC - O(N * M) 
// SC - O 2(N)     prev and curr











int main(){
    string s1 = "acd";
    string s2 = "ced";

    // Longest Common Subsequence is = cd (so lenght is 2) 
    int n = s1.size();
    int m = s2.size();

    cout << LCS4(n, m, s1, s2);
                          
 
}
