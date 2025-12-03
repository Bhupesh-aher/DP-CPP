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




// Tabulation 

int LCS1(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n-1, m-1, s1, s2, dp);
}


// TC - O(N * M) 
// SC - O(N * M)      dp




// Space optimization



// TC - O(N * N) 
// SC - O 2(N)     prev and curr











int main(){
    string s1 = "acd";
    string s2 = "ced";

    // Longest Common Subsequence is = cd (so lenght is 2) 
    int n = s1.size();
    int m = s2.size();

    cout << LCS1(n, m, s1, s2);
                          
 
}
